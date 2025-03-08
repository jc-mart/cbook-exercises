#include <stdio.h>
#include <string.h>

// Exercise 3-4
void itoa(int n, char s[]);

int main() {

}


/**
 * Exercise 3-4.
 *
 * In a two's compliment number representation, our version of `itoa` does
 * not handle the largest negative number, that is, the value `n` equal to
 * `-(2^(wordsize - 1))`. Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 *
 * Explanation: In two's compliment, the MSB is regarded as the sign bit.
 * With that extra 1, we're able to reach a higher negative number than
 * we could positive, as the MSB would be 0 to indicate a positive number.
 */ 
void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';
	reverse(s);
}
