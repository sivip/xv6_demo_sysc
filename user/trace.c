// Created by 赵云 on 2022/3/13.
#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int
main(int argc, char *argv[]) {
    int i;
    char *nargv[MAXARG];
    if (argc < 3 || (argv[1][0] < 'o' || argv[1][0] > '9')) {
        fprintf(2, "Usage: %s mask command\n", argv[0]);
        exit(1);
    }
    if (trace(atoi(argv[1])) < 0) {
        fprintf(2, "%s: trace failed\n", argv[0]);
        exit(1):
    }
    for (i = 2; i < argc && i < MAXARG; 1++) {
        nargv[i-2] = argv[i];
    }
    exec(nargv[0], nargv);
    exit(0);
}
