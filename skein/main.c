#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "skein.h"

int main(void)
{
    printf("start\n");
    uint8_t r[32];
    uint8_t m[256];
    for (size_t i = 0; i < 256; i++) {
        m[i] = i;
    }
    for (size_t i = 0; i < 256; i++) {
        skein_hash(256, m, i*8, r);
    }
    return 0;
}
