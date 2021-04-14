
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define snzprintf(dst, fmt, data...) do { \
        size_t sz = sizeof(dst); \
        memset(dst, 0, sz); \
        snprintf(dst, (sz-1), fmt, data); \
    } while(0)

static inline uint16_t swap_uint16(uint16_t val)
{
    return (val << 8) | (val >> 8);
}

int main()
{
    /*
     *  2 bytes LCP UP Count,
     *  2 bytes IPCP UP Count
     *  2 bytes LCP Down Count,
     *  2 bytes IPCP Down Count
     *  \n\r OK
    */
    char    byte[32] = {    0x0A, 0xAA,
                            0x05, 0x55,
                            0x88, 0x88,
                            0x08, 0x88,
                    0x0A, 0x0D, 0x4F, 0x4B };

    uint16_t    lcp_up = 0, ipcp_up = 0, lcp_down = 0, ipcp_down = 0;

    lcp_up = swap_uint16(*(uint16_t *) byte);
    ipcp_up = swap_uint16(*(uint16_t *) (byte + sizeof (uint16_t)));
    lcp_down = swap_uint16(*(uint16_t *) (byte + (sizeof (uint16_t) * 2)));
    ipcp_down = swap_uint16(*(uint16_t *) (byte + (sizeof (uint16_t) * 3)));

    printf("lcp-up:%u, ipcp-up: %u, lcp_down: %u, ipcp_down: %u\n",
        lcp_up, ipcp_up, lcp_down, ipcp_down);
}
