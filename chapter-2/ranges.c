#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("CHAR:    max = %d, min = %d\n   \
            U_CHAR:  max = %d, min = %d\n   \
            SHORT:   max = %d, min = %d\n   \
            U_SHORT: max = %d, min = %d\n   \
            INT:     max = %d, min = %d\n   \
            U_INT:   max = %lli, min = %d\n \
            LONG:    max = %d, min = %d\n   \
            U_LONG:  max = %lli, min = %d\n \
            ", CHAR_MAX, CHAR_MIN,          \
            UCHAR_MAX, 0,                   \
            SHRT_MAX, SHRT_MIN,             \
            USHRT_MAX, 0,                   \
            INT_MAX, INT_MIN,               \
            UINT_MAX, 0,                    \
            LONG_MAX, LONG_MIN,             \
            ULONG_MAX, 0);

    return 0;
}