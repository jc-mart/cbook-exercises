#include <stdio.h>

/**
 * Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly. C
 * comments do not nest.
*/

void removeComments();

int main() {
    removeComments();
}

void removeComments() {
    int c, quoted;

    quoted = 0;
    while ((c = getchar()) != EOF) {
        if ((c == '"' && quoted == 0) || (c == '\'' && quoted == 0)) {
            quoted = 1;
            putchar(c);
            c = getchar();
        }
        if (c == '/' && quoted == 0)
            if ((c = getchar()) == '/' && c != EOF)
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
        
        if ((quoted == 1 && c == '\'') || (quoted == 1 && c == '"'))
            quoted = 0;

        putchar(c);
    }
}