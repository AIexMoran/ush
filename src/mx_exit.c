#include "ush.h"

void mx_exit(char **args) {
    int code = 0;
    system("leaks -q ush");
<<<<<<< HEAD
    mx_deinit();
    if (!*args) {
=======
    mx_disable_canon();
    if (!*args)
>>>>>>> 9793ba78e7c5acbd29734738f4e9eb64db327a88
        exit(code);
    if (mx_arr_size(args) > 1) {
        fprintf(stderr, "exit: too many arguments\n");
        exit(1);
    }
    for (unsigned int i = 0; i < strlen(args[0]); i++)
        if (!isnumber(args[0][i])) {
            fprintf(stderr, "exit: bad argument\n");
            exit(1);
        }
    code = atoi(args[0]);
    exit(code);
}
