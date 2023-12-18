#include <stdio.h>

/* copy input to output; 1st version */

void io_1() {
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

/* copy input to output; 2nd version*/

void io_2() {
    int c;

    while ((c = getchar()) != EOF) 
        putchar(c);
}

/**
 * Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/

void io_3() {
    int c;

    while ((c = getchar()) != EOF) {
        printf(" Do we still have input? %d ", c != EOF);
        putchar(c);
    }
}

/**
 * Exercise 1-9. Write a program to copy its input to output, replacing each
 * string of one or more blanks by a single blank.
*/

void replaceSpace() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // Keep iterating through stream until there's no space
            while ((c = getchar()) == ' ')
                ;
            putchar(' ');
        }
        putchar(c);
    }
}

/**
 * Exercise 1-7. Write a program to print the value of EOF.
*/

int main() {
    // Value of EOF is -1
    printf(" Value of EOF: %d\n", EOF);
    replaceSpace();
}