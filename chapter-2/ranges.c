#include <stdio.h>
#include <limits.h>
#include <float.h>

/**
 * Exercise 2-1.
 * 
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder ifyou compute them:
 * determine the ranges of the various floating-point types.
*/
int main() {
    // Integer values, use %lli for Windows, %lu for macOS
    printf("CHAR:    max = %d, min = %d\n"   
            "U_CHAR:  max = %d, min = %d\n"   
            "SHORT:   max = %d, min = %d\n"   
            "U_SHORT: max = %d, min = %d\n"   
            "INT:     max = %d, min = %d\n"   
            "U_INT:   max = %u, min = %d\n"   
            "LONG:    max = %li, min = %li\n"   
            "U_LONG:  max = %lu, min = %d\n", 
            CHAR_MAX, CHAR_MIN,          
            UCHAR_MAX, 0,                   
            SHRT_MAX, SHRT_MIN,             
            USHRT_MAX, 0,                   
            INT_MAX, INT_MIN,               
            UINT_MAX, 0,                    
            LONG_MAX, LONG_MIN,             
            ULONG_MAX, 0);

    // Double values
    printf("\nFLOAT:   max = %e, min = %e\n"   
            "DOUBLE:  max = %e, min = %e\n"   
            "L_DBL:   max = %e, min = %e\n",   
            FLT_MAX, FLT_MIN,
            DBL_MAX, DBL_MIN,
            LDBL_MAX, LDBL_MIN);

    return 0;
}