#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
// Exercise 2-6
unsigned setbits(unsigned x, int p, int n, unsigned y);
// Exercise 2-7
unsigned invert(unsigned x, int p, int n);
// Exercise 2-8
unsigned rightrot(unsigned x, int n);
// Exercise 2-9
int bitcount(unsigned x);
int bitcount_faster(unsigned x);

int main() {
    // GETBITS example
    unsigned int getbits_alpha = 15;
    unsigned int getbits_result = getbits(getbits_alpha, 2, 2);

    // Familiarizing bit shifting
    /**
    printf("Left shift by 0: %d.\n", ~(~0 << 0));
    printf("Left shift by 1: %d.\n", ~(~0 << 1));
    printf("Left shift by 2: %d.\n", ~(~0 << 2));
    */
    printf("%d's the new result.\n", getbits_result);

    // SETBITS exercise
    unsigned int alpha = 0b1111;
    unsigned int bravo = 0b1001;
    unsigned int expected = 0b1011;
    unsigned int new_result = setbits(alpha, 2, 2, bravo);

    printf("[SETBITS] Actual result of %u when expecting %u.\n", new_result, expected);

    // INVERT exercise
    unsigned int invert_alpha = 0b1111;
    unsigned int invert_expected = 0b1110;
    unsigned int invert_result = invert(alpha, 1, 1);

    printf("[INVERT] Actual result of %u when expecting %u.\n", invert_result, invert_expected);

    // RIGHTROT exercise
    unsigned int righrot_alpha = 0b11011;
    unsigned int rightrot_expected = 0b11110;
    unsigned int rightrot_result = rightrot(righrot_alpha, 2);

    printf("[RIGHTROT] Actual result of %u when expecting %u.\n", rightrot_result, rightrot_expected);

    //BITCOUNT exercise
    unsigned int bitcount_alpha = 0b1101;
    int bitcount_expected = 3;
    int bitcount_result = bitcount(bitcount_alpha);

    unsigned int bitcount_faster_alpha = 0b1101;
    int bitcount_faster_expected = 4;
    int bitcount_faster_result = bitcount_faster(bitcount_alpha);

    printf("Expecting %d. From bitcount: %d. From bitcount faster: %d.\n", bitcount_expected, bitcount_result, bitcount_faster_result);
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
    /**
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
    */
    return x & ~(~(~0 << n) << p - 1) | (y & ~(~0 << n)) << p - 1;
}


/**
 * Exercise 2-7.
 * 
 * Write a function `invert(x,p,n)` that returns `x` with the `n` bits that
 * begin at position `p` inverted (i.e., 1 changed to 0 and vice versa),
 * leaving the other bits unchanged.
 */
unsigned invert(unsigned x, int p, int n) {
    /**
    // Create bitmask
    unsigned bitmask = ~(~0 << n);
    // Shift bitmask over p positions to the left
    bitmask = bitmask << p - 1;
    // XOR to invert the desired bits and return
    return x ^ bitmask;
    */
    return x ^ (~(~0 << n) << p - 1);
}

/**
 * Exercise 2-8.
 * 
 * Write a function `rightrot(x,n)` that returns the value of the integer `x`
 * rotated to the right by `n` bit positions.
 */
unsigned rightrot(unsigned x, int n) {
    unsigned y, bit_length;
    // Determine bit length
    for (y = x, bit_length = 0; (y = y >> 1) > 1; bit_length++)
        ;
    /**
    // Create bitmask
    unsigned bitmask = ~(~0 << n);
    // Extract n bits to be moved
    unsigned extracted = bitmask & x;
    // Shift n bits over to the right
    extracted = extracted << bit_length;
    // Move x n bits to the left
    x = x >> n;
    // Return rotation
    return extracted | x;
    */
    return ((~(~0 << n) & x) << bit_length) | (x >> n);
}

/**
 * Exercise 2-9.
 * 
 * In a two's complement number system, `x &= (x-1)` deletes the rightmost
 * 1-bit in `x`. Explain why. Use this observation to write a faster version of
 * `bitcount`.
 * 
 * EXPLANATION: Starting with 1111 as an example
 * 1111 &= (1111 - 1) -> 1111 &= 1110 -> 1110
 * 1110 &= (1110 - 1) -> 1110 &= 1101 -> 1100
 * 1100 &= (1100 - 1) -> 1100 &= 1011 -> 1000
 */
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}

int bitcount_faster(unsigned x) {
    int b;

    for (b = 0; x > 0; x &= (x - 1), b++)
        ;
    
    return b;
}
