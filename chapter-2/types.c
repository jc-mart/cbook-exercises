#include <stdio.h>
#include <math.h>

void expand();
int htoi(char s[]);

int main() {
    printf("Result of htoi: %d\n", htoi("0X7cF")); // Decimal equivalent: 1999
}

/**
 * Exercise 2-2.
 * 
 * Write a loop equivalent to the `for` loop above without using `&&` or `||`.
*/
void expand() {
    int lim = 5;
    char c, s[lim];

    // Expanded logical operands by using nested conditionals
    for(int i = 0; i < lim - 1; ++i)
        if ((c = getchar()) != '\n')
            if (c != EOF)
                s[i] = c;
}

/**
 * Exercise 2-3.
 * 
 * Write a function `htoi(s)`, which converts a string of hexadecimal digits,
 * (including an optional `0x` or `0X`) into its equivalent integer value. The
 * allowable digits are `0` through `9`, `a` through `f`, and `A` through `F`.
*/
#define HEX 16

int htoi(char s[]) {
    // Count size of string, optional hexadecimal prefix, exponent, character,
    // and sum.
    int i, j, p, c, sum;
    i = j = p = c = sum = 0;

    // Determine string size
    for (i; s[i] != '\0'; i++)
        ;

    // Determine if hexadecimal identifier is present
    if (i > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        j = 2;

    // Work from end of string to beginning
    for (i -= 1; i >= j; --i) {
        // Obtain a character from the string and evaluate value
        c = s[i];

        if (c >= '0' && c <= '9')
            c -= '0';
        else if (c >= 'a' && c <= 'f')
            c -= 'a' - 10;
        else if (c >= 'A' && c <= 'F')
            c -= 'A' - 10;

        // Add value to rolling sum
        sum += c * pow(HEX, p++);
    }

    return sum;
}