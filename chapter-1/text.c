#include <stdio.h>
#define MAXLINE 10000 // Maximum input line size

int getline(char line[]);
void copy(char to[], char from[]);
// Part of exercise 1-17
void printLong80();
// Part of exercise 1-18
void removeTrailing();
// Part of exercise 1-19
void reverse(char s[]);

/* print longest input line */
int main() {
    int len; // Current line length
    int max; // Max line length seen so far
    char line[MAXLINE]; // Current input line
    char longest[MAXLINE]; // Longest line saved here

    max = 0;
    while ((len = getline(line)) > 0)
        reverse(line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) // There was a line
        printf("%s", longest);
    return 0;
}

/* getline: read a line into s, return length */

/**
 * Exercise 1-16. Revise the main routine of the longest-line program so it
 * will print the length of arbitrarily long input lines, and as much as
 * possible of the text.
*/
int getline(char s[]) { // Removed limit, prints long lengths.
    int c, i;

    // Removed limits here as well
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

/**
 * Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
*/

void printLong80() {
    int c, i;
    int line[MAXLINE];

    while ((c = getchar()) != EOF) {
        for (i = 0; c != '\n'; ++i) {
            line[i] = c;
            c = getchar();
        }
        line[i] = '\0';
        if (i >= 80)
            for (i = 0; line[i] != '\0'; ++i)
                putchar(line[i]);
        printf("\n");
    }
}

/**
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
*/

void removeTrailing() {
    int c, i;
    char line[MAXLINE];
    int letter;

    while ((c = getchar()) != EOF) {
        for (i = 0; c != '\n'; ++i) {
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

/**
 * Exercise 1-19. Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a
 * time.
*/

void reverse(char s[]) {
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ;

    for (i; i >= 0; --i)
        putchar(s[i]);
    printf("\n");
}