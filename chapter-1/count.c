#include <stdio.h>

#define IN 1 // Inside a word
#define OUT 0 // Outside a word

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
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

/**
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

void countSpacing() {
    int c, n;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++n;
    printf("%d\n", n);
}

/**
 * Exercise 1-11. How would you test the word count program? What kinds of
 * input are most likely to uncover bugs if there are any?
 * 
 * Backspaces may present an issue; may be counted as words. If reading a
 * file as input, words that span multiple lines may be counted as two.
 * If numbers are put into input, they may be counted as words as well.
*/

void countWords() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d", nl, nw, nc);
}

int main() {
    countChars_1();
}