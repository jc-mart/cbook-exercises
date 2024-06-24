#include <stdio.h>

// Exercise 3-1
int binsearch(int x, int v[], int n);
int binsearch_modified(int x, int v[], int n);
// Exercise 3-2
void escape(char s[], char t[]);
void escape_reverse(char s[], char t[]);

int main() {
    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    int expecting = 5;
    int result = binsearch_modified(expecting, sorted, 7);

    printf("Expecting %d and got %d.\n", expecting, result);
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

void escape(char s[], char t[]) {

    return 0;
}

void escape_reverse(char s[], char t[]) {

    return 0;
}
