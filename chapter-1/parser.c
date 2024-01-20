#include <stdio.h>

/**
 * Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly. C
 * comments do not nest.
*/

void removeComments();

/**
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parenthesis, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This
 * program is hard if you do it in full generality)
*/

void checkProgram();

int main() {
    checkProgram();
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
            else
                putchar('/');
        
        if ((quoted == 1 && c == '\'') || (quoted == 1 && c == '"'))
            quoted = 0;

        putchar(c);
    }
}

void checkProgram() {
    int c, bal, sinEsc, dobEsc, comEsc;

    // 'esc' references anything in quotes or comments
    bal = sinEsc = dobEsc = comEsc = 0;
    while ((c = getchar()) != EOF) {
        // Double quotes
        if (c == '"' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            dobEsc = 1;
            bal += 1;
        } else if (c == '"' && dobEsc == 1 && sinEsc == 0 && c != EOF) {
            dobEsc = 0;
            bal -= 1;
        }
        // Single quotes
        if (c == '\'' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            sinEsc = 1;
            bal += 1;
        } else if (c == '\'' && dobEsc == 0 && sinEsc == 1 && c != EOF) {
            sinEsc = 0;
            bal -= 1;
        }
        // Braces
        if (c == '{' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            bal += 1;
        } else if (c == '}' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            bal -= 1;
        }
        // Brackets
        if (c == '[' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            bal += 1;
        } else if (c == ']' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            bal -= 1;
        }
        // Parentheses
        if (c == '(' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            bal += 1;
        } else if (c == ')' && dobEsc == 0 && sinEsc == 0 && c != EOF) {
            bal -= 1;
        }
        // In-line comment
        if (c == '/' && sinEsc == 0 && dobEsc == 0)
            if ((c = getchar()) == '/' && c != EOF)
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
            else
                putchar('/');
        
        putchar(c);
        if (bal != 0)
            printf("\nProgram has missing braces, brackets, or parenthesis. %d\n", bal);
    }
}