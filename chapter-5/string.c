#include <stdio.h>

void astrcat(char s[], char t[]);
void pstrcat(char *s, char *t);

int main() {
    // Exercise 5-3
    char dest[6] = {'H', 'e', '\0'};
    char src[] = "llo";

    printf("Before function: %s\n", dest);
    pstrcat(dest, src);
    printf("After function: %s\n", dest);
}

void astrcat(char s[], char t[]) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
        i++;
    
    while ((s[i++] = t[j++]) != '\0')
        ;
}

/**
 * Exercise 5-3
 * 
 * Write a pointer version of the function `strcat` that we showed in Chapter 2:
 * `strcat(s,t)` copies the string `t` to the end of `s`. 
*/

void pstrcat(char *s, char *t) {
    while (*s != '\0')
        s++;

    while ((*s = *t) != '\0') {
        s++, t++;
    }
}