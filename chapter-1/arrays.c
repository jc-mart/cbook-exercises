#include <stdio.h>\

#define IN 1
#define OUT 0

void countDigits() {
    // Value initialization
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    // Aggregate counters
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    
    // Print results
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

/**
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
*/

#define LETTERS 16

void horizontalHistogram() {
    int c, i, j, wc;
    int wl[LETTERS]; // Assuming 15-letter long words

    for (i = 0; i < LETTERS; ++i)
        wl[i] = 0;
    
    wc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++wl[wc];
            wc = 0;
        } else {
            ++wc;
        }

        putchar(c);
        // Ideally this is outside the loop to prevent repetition
        for (i = 1; i < LETTERS; ++i) {
            printf("Length %2d: ", i);
            for (j = 0; j < wl[i]; ++j)
                printf("-");
            printf("\n");
        }
    }
}

/**
 * [SUPPLEMENTAL]
 * Exercise 1-13. Vertical instead.
*/

void verticalHistogram() {
    int c, i, j, wc, max;
    int wl[LETTERS];

    for (i = 0; i < LETTERS; ++i)
        wl[i] = 0;

    wc = 0;
    max = -1;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++wl[wc];
            wc = 0;
        } else {
            ++wc;
        }

        //putchar(c);
        // Find the biggest value
        for (i = 1; i < LETTERS; ++i) {
            if (wl[i] > max)
                max = wl[i];
        }

        printf("\n");
        for (i = max; i > 0; --i) {
            for (j = 1; j < LETTERS; ++j) {
                if (wl[j] >= i)
                    if (j < 10)
                        printf("|  ");
                    else
                        printf("|   ");
                else
                    if (j < 10)
                        printf("   ");
                    else
                        printf("    ");
            }
            printf("\n");
        }
        for (i = 1; i < LETTERS; ++i)
            printf("%d, ", i);
        printf("\n");
    }
}


/**
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
*/

#define CHAR_BUF 95 // All keys that may be pressed by keyboard
#define CHAR_BEGIN 32 // Keyboard characters begin, starting at space
#define HIST_LIMIT 20

void charFrequency() {
    int c, i, cc;
    float r;
    int cl[CHAR_BUF];
    char ci;

    for (i = 0; i < CHAR_BUF; ++i)
        cl[i] = 0;

    cc = 0;
    while ((c = getchar()) != EOF) {
        ++cl[c - CHAR_BEGIN];
        ++cc;

        //putchar(c);
        for (i = 0; i < CHAR_BUF; ++i) {
            if (cl[i] != 0) {
                ci = i + CHAR_BEGIN;
                r = cl[i] / cc * HIST_LIMIT;
                // Print out frequencies
            }
        }
    }
}
    
int main() {
    verticalHistogram();
}