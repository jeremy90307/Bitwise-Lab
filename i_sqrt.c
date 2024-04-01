#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/*Call log2 to complete the square root calculation.*/
int i_sqrt(int N)
{
    int msb = (int) log2(N);
    int a = 1 << msb;
    int result = 0;
    while (a != 0) {
        if ((result + a) * (result + a) <= N)
            result += a;
        a >>= 1;
    }
    return result;
}

/*
Using the Digit-by-digit calculation method to perform the
square root calculation.
*/
int i_sqrt_dbd(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int z = 0;
    for (int m = 1UL << ((31 - __builtin_clz(x)) & ~1UL); m; m >>= 2) {
        int b = z + m;
        z >>= 1;
        if (x >= b)
            x -= b, z += m;
    }
    return z;
}

/*
Introduce the ffs function to make Digit-by-digit calculation
independent of GNU extension.
*/
int i_sqrt_fls(int x)
{
    if (x <= 1)
        return x;
    int tmp = x, msb = 0;
    while (tmp) {
        int ffs_num = ffs(tmp);
        msb += ffs_num;
        tmp >>= ffs_num;
    }
    msb--;

    int z = 0;
    for (int m = 1UL << (msb & ~1UL); m; m >>= 2) {
        int b = z + m;
        z >>= 1;
        if (x >= b) {
            x -= b;
            z += m;
        }
    }
    return z;
}

int main()
{
    int i = 10000;
    while (i--) {
        assert(i_sqrt(i) == i_sqrt_fls(i));
        assert(i_sqrt(i) == i_sqrt_dbd(i));
    }
    printf("success\n");
    return 0;
}