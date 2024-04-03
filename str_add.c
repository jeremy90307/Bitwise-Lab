#include <stdio.h>
#include <stdint.h>
#include <string.h>

// static void str_add(char *b, char *a, char *res, size_t size)
// {
//     int carry = 0;

//     for (int i = 0; i < size; i++) {
//         int tmp = (b[i] - '0') + (a[i] - '0') + carry;
//         carry = tmp / 10;
//         tmp = tmp % 10;
//         res[i] = tmp + '0';
//     }
// }

#include <stdint.h>
#include <stdio.h>

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