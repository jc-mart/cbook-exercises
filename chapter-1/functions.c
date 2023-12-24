#include <stdio.h>

// Function prototype
int power(int m, int n);

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

/**  
 * power: raise base to n-th power; n>=0; version 2
 * 
 * Taking advantage over the fact that functions make private copies of
 * variables. Because of this, we can modify the for loop to not use variable i
 * anymore and instead decrement using n. n can't be modified as the argument
 * is a copy.
 * 
 * If modifying the value is wanted, the use of pointers is then needed.
*/
int power2(int base, int n) {
    int p;

    for (p = 1; n > 0; --n)
        p *= base;
    return p;
}

int main() {
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}