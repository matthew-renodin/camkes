/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

/* WARNING: This code does no error checking whatsoever. */

int main(int argc, char **argv) {
    struct winsize x = { 0 };
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &x);

    FILE *f = fopen(argv[1], "w");
    fprintf(f, "#ifndef _TERMINAL_TERMINAL_H_\n"
           "#define _TERMINAL_TERMINAL_H_\n"
           "\n"
           "/* THIS FILE IS AUTOGENERATED. DO NOT EDIT. */\n"
           "\n"
           "#define TERMINAL_WIDTH %d\n"
           "#define TERMINAL_HEIGHT %d\n"
           "\n"
           "#endif /* !_TERMINAL_TERMINAL_H_ */\n",
           x.ws_col, x.ws_row);
    fclose(f);
    return 0;
}
