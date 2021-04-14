
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define snzprintf(dst, fmt, data...) do { \
        size_t sz = sizeof(dst); \
        memset(dst, 0, sz); \
        snprintf(dst, (sz-1), fmt, data); \
    } while(0)

static inline uint32_t swap_uint32(uint32_t val)
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

int main()
{
    /*
     *  4 bytes Ethernet TX,
     *  4 bytes Ethernet RX,
     *  \n\r OK
    */
    char    byte[32] = { 0x00, 0x00, 0x03, 0xE8,
                    0x00, 0x01, 0x00, 0x00,
                    0x0A, 0x0D, 0x4F, 0x4B };

    uint32_t    eth_tx = 0, eth_rx = 0;

    eth_tx = swap_uint32(*(uint32_t *) byte);
    eth_rx = swap_uint32(*(uint32_t *) (byte + sizeof (uint32_t)));

    printf("ethtx: %u\n", eth_tx);
    printf("ethrx: %u\n", eth_rx);
}
