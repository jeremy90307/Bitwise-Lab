#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
Using bitwise operations to perform mod 10 and div 10.
For more details, refer to https://web.archive.org/web/20180517023231/http://www.hackersdelight.org/divcMore.pdf
*/
int main()
{
    for (int n = 0; n <= 19; n++) {
        unsigned d2, d1, d0, q, r;
        d0 = q & 0b1;
        d1 = q & 0b11;
        d2 = q & 0b111;
        q = ((((n >> 3) + (n >> 1) + n) << 3) + d0 + d1 + d2) >> 7;
        r = n - (((q << 2) + q) << 1);
        printf("q: %d r: %d\n",  q, r);
    } 
    return 0;
}