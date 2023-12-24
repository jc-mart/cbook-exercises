#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/**
 * Exercise 1-3. Modify the temperature conversion program to print a heading
 * above the table.
*/

void fahrToCelsius() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // Lower limit
    upper = 300; // Upper limit
    step = 20; // Step size

    // Heading describes conversion and units
    printf("Fahr to Celsius\n%4s %7s\n", "°F", "°C");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}

/**
 * Exercise 1-4. Write a program to print the corresponding Celsius to
 * Fahrenheit table.
*/

void celsiusToFahr() {
    printf("Celsius to Fahr\n%4s %7s\n", "°C", "°F");

    for (int celsius = 0; celsius <= 300; celsius += 20) {
        printf("%3d %6.0f\n", celsius, celsius * (9.0 / 5.0) + 32.0);
    }
}

/**
 * Exercise 1-5. Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0.
*/

void fahrToCelsiusDesc() {
    printf("Fahr to Celsius (Desc)\n%4s %8s\n", "°F", "°C");

    for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3d %7.2f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}

/**
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
*/

float fahrToCelsius2(int fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main() {
    fahrToCelsius();
    printf("\n");
    celsiusToFahr();
    printf("\n");
    fahrToCelsiusDesc();
    printf("\n%f\n", fahrToCelsius2(212));
}