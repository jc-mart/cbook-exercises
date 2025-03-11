#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

// Exercise 3-4
void itoa(int n, char s[]);
void reverse(char* s);
// Exercise 3-5
void itob(int n, char s[], int b);

int main() {
	char dest[50] = "";

	itoa(INT_MIN, dest);
	printf("Min is %d, string is %s\n", INT_MIN, dest);
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

	if (n < 0)
		sign = 1;
	
	i = 0;
	do {
		if (sign)
			s[i++] = abs(abs(n) % 10) + '0';
		else
			s[i++] = n % 10 + '0';
	} while((abs(n /= 10)) > 0);
	
	if (sign)
		s[i++] = '-';
	
	s[i] = '\0';
	reverse(s);
}

void itob(int n, char s[], int b) {
	
}

void reverse(char* s) {
	// Initialize l and r pointers
    int l = 0;
    int r = strlen(s) - 1;
    char t;

    // Swap characters till l and r meet
    while (l < r) {
      
        // Swap characters
        t = s[l];
        s[l] = s[r];
        s[r] = t;

        // Move pointers towards each other
        l++;
        r--;
    }
}
