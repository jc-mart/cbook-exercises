#include <stdio.h>

/* count characters in input; 1st version */

void countChars_1(){
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}

/* count characters in input; 2nd version */

void countChars_2(){
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ; // Null statement; C rules say a for loop must have a body
    printf("%.0f\n", nc);
}

void countLines() {
    int c, n1;

    n1 = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++n1;
    printf("%d\n", n1);
}

/**
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

int countSpacing() {
    int c, n;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++n;
    printf("%d\n", n);
}

int main() {
    countChars_1();
}