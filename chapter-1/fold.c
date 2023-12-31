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
    int c, i, letter;
    char line[DEFAULT];

    while ((c = getchar()) != EOF) {
        // DEFAULT - 1 to have room for null terminator
        for (i = 0; i < DEFAULT - 1 || c == '\n'; ++i) {
            line[i] = c;
            c = getchar();
        }
        line[i] = '\0';
        letter = 0;
        for (i; i >= 0; --i) {
            if (line[i] != ' ' || line[i] != '\t')
                letter = 1;
            if ((line[i] == ' ' && letter == 0) || (line[i] == '\t' &&
            letter == 0))
                line[i] = '\0';
        }
        for (i = 0; line[i] != '\0'; ++i)
            putchar(line[i]);
        printf("\n");
    }
}