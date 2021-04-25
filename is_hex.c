#include <stdio.h>
#include <stdint.h>
#include <string.h>


static int is_hex(const uint8_t *data, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++) {
        if (data[i] < 32 || data[i] >= 127) {
            printf("%c\n", data[i]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    char    *hex = "3030353063323963646236363134313430303032313431343030303166666666666666634f4b";

    printf("is-hex: %s\n", is_hex(hex, strlen(hex) -1 ) ? "Yes" : "No");
}
