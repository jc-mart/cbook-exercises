#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    unsigned int test = 15;
    unsigned int result = getbits(test, 2, 2);

    printf("Left shift by 0: %d.\n", ~(~0 << 0));
    printf("Left shift by 1: %d.\n", ~(~0 << 1));
    printf("Left shift by 2: %d.\n", ~(~0 << 2));

    printf("%d's the new result.\n", result);


    unsigned int alpha = 0b1111;
    unsigned int bravo = 0b1001;
    unsigned int expected = 0b1011;
    unsigned int new_result = setbits(alpha, 2, 2, bravo);

    printf("Actual result of %u when expecting %u.\n", new_result, expected);
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(1 << n);
}

/**
 * Exercise 2-6.
 * 
 * Write a function `setbits(x,p,n,y)` that returns `x` with the `n` bits that
 * begin at position `p` set to the rightmost `n` bits of `y`, leaving the
 * other bits unchanged.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Create bitmask
    unsigned bitmask = ~(~0 << n);
    // Bitwise `&` the bitmask with y to extract right-most `n` bits
    unsigned extracted = y & bitmask;
    // Shift extracted bits left `p` bits
    extracted = extracted << p - 1;
    // Shift bitmask `p` bits to the left to create a new bitmask that operates
    // on `n` bits starting at position `p`
    bitmask = bitmask << p - 1;
    // Bitwise `&` the inverse shifted bitmask with `x` to mask out the bits
    // you want to replace
    x = ~bitmask & x;
    // Bitwise `|` to get result
    return x | extracted;
}
