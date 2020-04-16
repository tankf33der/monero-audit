#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "hmac-keccak.h"

int main(void)
{
    printf("start\n");
    uint8_t r[32];
    uint8_t k[32];
    uint8_t m[256];

    for (size_t i = 0; i < 256; i++) {
        m[i] = i;
    }
    for (size_t i = 0; i < 32; i++) {
        k[i] = i;
    }
    hmac_keccak_hash(r, k, 0, m, 0);
    /*
    for (size_t i = 0; i < 256; i++) {
        hmac_keccak_hash(r, k, 0, m, i);
    }
    for (size_t i = 0; i < 32; i++) {
        hmac_keccak_hash(r, k, i, m, 256);
    }
    */
    return 0;
}
