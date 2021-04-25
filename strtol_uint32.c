#include <stdio.h>
#include <stdint.h>



int main()
{
    uint8_t *stx = "0000000b";
    uint8_t *srx = "00009b06";

    uint32_t tx = (uint32_t) strtol(stx, NULL, 16);
    uint32_t rx = (uint32_t) strtol(srx, NULL, 16);

    printf("%s : %u\n", stx, tx);
    printf("%s : %u\n", srx, rx);
}
