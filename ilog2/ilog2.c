#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int ilog2(int i)
{
    int log = -1;
    while (i) {
        i >>= 1;
        log++;
    }
    return log;
}
static size_t ilog2_b(size_t i)
{
    size_t result = 0;
    while (i >= 65536) {
        result += 16;
        i >>= 16;
    }
    while (i >= 256) {
        result += 8;
        i >>= 8;
    }
    while (i >= 16) {
        result += 4;
        i >>= 4;
    }
    while (i >= 2) {
        result += 1;
        i >>= 1;
    }
    return result;
}

int main()
{
    for (int i = 32768; i; i >>= 1)
        assert(ilog2(i) == ilog2_b(i));
    printf("Success\n");
    return 0;
}