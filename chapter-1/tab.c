#include <stdio.h>

#define DEFAULT 2

/**
 * Exercise 1-20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
*/

void detab(int col);

/**
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or single blank would suffice to
 * reach a tab stop, which should be given preference?
*/

void entab(int col);

int main() {
    entab(DEFAULT);
    detab(DEFAULT);
}

void detab(int col) {
    int c, i;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            for (i = 0; i < col; ++i)
                putchar(' ');
        else
            putchar(c);
    }
}

void entab(int col) {
    int c, i;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            i = 1;
            while ((c = getchar()) == ' ')
                ++i;
            // Tabs are given precedence over blanks
            for (i; i >= DEFAULT; i -= DEFAULT)
                putchar('\t');
            for (i; i > 0; --i)
                putchar(' ');
        }
        putchar(c);
    }
}