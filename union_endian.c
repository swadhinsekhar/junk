#include <stdio.h>
#include <stdint.h>

typedef union endian_u {
    int     a;
    uint8_t b[4];
} endian;

int main()
{
    endian en;

    en.a = 1;
    // 1 0 0 0 - Littele Endian (if big endian : 0 0 0 1)
    printf("%d : %d %d %d %d\n", en.a, en.b[0], en.b[1], en.b[2], en.b[3]);

    return 0;
}
