#include <stdio.h>

#define DEFAULT 20

/**
 * Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there there are no blanks or tabs before the specified
 * column.
*/

void fold(int n);

int main() {
    fold(DEFAULT);
}

void fold(int n) {
    int c, i, j, letter;
    char line[DEFAULT];

    c = 0;
    while ((c = getchar()) != EOF) {
        line[i] = c;
        ++i;

        if (i == DEFAULT || c == '\n') {
            letter = 0;
            while (letter)
                if (line[i] != ' ' && line[i] != '\t')
                    letter = 1;
                else if (i == 0)
                    letter = 1;
                else
                    --i;
            for (j = 0; j < i; ++j) {
                putchar(line[j]);
            }
            printf("\n");
            i = 0;
        }
    }
}