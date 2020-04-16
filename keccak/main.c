#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

extern int keccak(const uint8_t *in, size_t inlen, uint8_t *md, size_t mdlen);

int main(void)
{
    printf("start\n");
    uint8_t b[200];
    uint8_t m[256];

    for (size_t i = 0; i < 256; i++) {
        m[i] = i;
    }

    for (size_t i = 0; i < 256; i++) {
        keccak(m, i, b, 200);
    }

    return 0;
}
