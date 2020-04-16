#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "blake256.h"

int main(void)
{
    printf("start\n");
    uint8_t r[32];
    uint8_t k[64];
    uint8_t m[256];
    for (size_t i = 0; i < 256; i++) {
        m[i] = i;
    }
    for (size_t i = 0; i < 64; i++) {
        k[i] = i;
    }

    for (size_t i = 0; i < 256; i++) {
        blake256_hash(r, m, i);
        blake224_hash(r, m, i);
    }
    for (size_t i = 0; i < 64; i++) {
        hmac_blake256_hash(r, k, i, m, i);
        hmac_blake224_hash(r, k, i, m, i);
    }
    return 0;
}
