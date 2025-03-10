#include <stdio.h>
#include <string.h>

// Exercise 3-1
int binsearch(int x, int v[], int n);
int binsearch_modified(int x, int v[], int n);
// Exercise 3-2
void escape(char s[], char t[]);
void unescape(char s[], char t[]);
// Exercise 3-3
void expand(char s1[], char s2[]);

int main() {
    // Exercise 3-1
    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    int expecting = 5;
    int result = binsearch_modified(expecting, sorted, 7);

    printf("Expecting %d and got %d.\n", expecting, result);

    // Exercise 3-2
    char escape_src[] = "\tThis is a test.\nOh!";
    char escape_dest[] = "                       ";
    escape(escape_dest, escape_src);

    printf("\nInput:\n%s\nOutput:\n%s\n", escape_src, escape_dest);

    char unescape_src[] = "\\tThis is a test.\\nOh!";
    char unescape_dest[] = "                       ";
    unescape(unescape_dest, unescape_src);

    printf("\nInput:\n%s\nOutput:\n%s\n", unescape_src, unescape_dest);
	
	// Exercise 3-3
	char expand_src[] = "-A-c0-1"; // 29 chars, 2 nums
	char expand_dest[29 + 2] = "";
	expand(expand_src, expand_dest);

	printf("\nInput:\n%s\nOutput:\n%s\n", expand_src, expand_dest);

}

/**
 * Exercise 3-1
 * 
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 */
int binsearch(int x, int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else // Found match
            return mid;
    }

    return -1; // No match
}

int binsearch_modified(int x, int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;

    do {
        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    } while (low <= high && x != v[mid]);

    if (x == v[mid])
        return x;

    return -1;
}

/**
 * Exercise 3-2.
 * 
 * Write a function `escape(s,t)` that converts characters like newline and tab
 * into visible escape sequences like `\n` and `\t` as it copies the string `t`
 * to `s`. Use a switch. Write a function for the other direction as well,
 * converting escape sequences into the real characters.
 */
void escape(char s[], char t[]) {
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; i++, j++) {        
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\r':
                s[j++] = '\\';
                s[j] = 'r';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\'':
                s[j++] = '\\';
                s[j] = '\'';
                break;
            case '\"':
                s[j++] = '\\';
                s[j] = '\"';
                break;
            case '\?':
                s[j++] = '\\';
                s[j] = '\?';
                break;
            default:
                s[j] = t[i];
                break;
        }

        s[j + 1] = '\0';
    }
}

void unescape(char s[], char t[]) {
    int i, curr, next;

    for (i = 0, curr = 0, next = 1; t[next] != '\0'; i++, curr++, next++) {
        printf("%c", t[curr]);

        if (t[curr] == '\\') {
            switch(t[next]) {
                case 'n':
                    s[i] = '\n';
                    curr++, next++;
                    break;
                case 'r':
                    s[i] = '\r';
                    curr++, next++;
                    break;
                case 't':
                    s[i] = '\t';
                    curr++, next++;
                    break;
                case '\\':
                    s[i] = '\\';
                    curr++, next++;
                    break;
                case '\'':
                    s[i] = '\'';
                    curr++, next++;
                    break;
                case '\"':
                    s[i] = '\"';
                    curr++, next++;
                    break;
                case '\?':
                    s[i] = '\?';
                    curr++, next++;
                    break;
            }
        } else
            s[i] = t[curr];
    }

    s[i] = t[curr];
    s[i + 1] = '\0';
}

/**
 * Exercise 3-3.
 *
 * Write a function `expand(s1,s2)` that expands shorthand notations like
 * `a-z` in the string `s1` into the equivalent complete list `abc...xyz`
 * in `s2`. Allow for letters of either case and digits, and be prepared
 * to handle cases like `a-b-c` and `a-z0-9` and `-a-z`. Arrange that a
 * leading or trailing `-` is taken literally.
 */
void expand(char s1[], char s2[]) {
    int i, total;
    char leading_dash = 0, leading_char = 0, trailing_char = 0, \
        leading_int = 0, trailing_int = 0;

    // Process input string for what characters to output
    for (i = 0; i < strlen(s1); i++) {
        // Letters
        if (s1[i] >= 'A' && s1[i] <= 'z') {
            if (!leading_char)
                leading_char = s1[i];
            else
                trailing_char = s1[i];
        // Numbers
        } else if (s1[i] >= '0' && s1[i] <= '9') {
            if (!leading_int)
                leading_int = s1[i];
            else
                trailing_int = s1[i];
        // Leading dash
        } else if (s1[i] == '-' && i == 0)
            leading_dash = '-';
    }

    // s2's potential length
    total = trailing_char - leading_char + trailing_int - leading_int;	
	int k = 0;

    if (leading_dash) {
        // Fill out backward logic
		i = total;
		while (i > 0) {
			for (int j = trailing_int; j >= leading_int; j--, i--)
				s2[k++] = j;

			for (int j = trailing_char; j >= leading_char; j--, i--) {
				if (96 >= j && j >= 91)
					continue;
				
				s2[k++] = j;;
			}
		}
    } else {
        // Fill out forward logic
		i = 0;
		while (i < total) {
			for (int j = leading_char; j <= trailing_char; j++, i++) {
				if (91 <= j && j <= 96)
					continue;

				s2[k++] = j;
			}

			for (int j = leading_int; j <= trailing_int; j++, i++)
				s2[k++] = j;
		}
    }
	putchar('\n');
}
