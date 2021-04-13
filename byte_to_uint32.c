
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define snzprintf(dst, fmt, data...) do { \
        size_t sz = sizeof(dst); \
        memset(dst, 0, sz); \
        snprintf(dst, (sz-1), fmt, data); \
    } while(0)

int main()
{
    /*
     *  4 bytes Ethernet TX,
     *  4 bytes Ethernet RX,
     *  \n\r OK
    */
    char    byte[32] = { 0x30, 0x30, 0x30, 0x31,
                    0x32, 0x32, 0x32, 0x32,
                    0x0A, 0x0D, 0x4F, 0x4B };
    size_t  i;
    for (i = 0; i < 4; i++) {
        printf("%c\n", byte[i]);
    }

    uint32_t    eth_tx = 0, eth_rx = 0;

    eth_tx = (uint32_t) (byte[0] << 24 | byte[1] << 16 | byte[2] << 8 | byte[3]);
    eth_rx = (uint32_t) (byte[4] << 24 | byte[5] << 16 | byte[6] << 8 | byte[7]);

    printf("ethtx: %u\n", eth_tx);
    printf("ethrx: %u\n", eth_rx);

    char    ether_tx[16], ether_rx[16];

    snzprintf(ether_tx, "%c%c%c%c%c", byte[0], byte[1], byte[2], byte[3], '\0');
    snzprintf(ether_rx, "%c%c%c%c%c", byte[4], byte[5], byte[6], byte[7], '\0');

    printf("ether-tx: %s ether-rx: %s\n", ether_tx, ether_rx);
}
