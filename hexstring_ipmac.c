/*
 * (hex-dump)   :    30 30 35 30 63 32 39 63 64 62 36 36 31 34 31 34 30 30 30 32 31 34 31 34 30 30 30 31 66 66 66 66 66 66 66 63 4f 4b 
 * (string)	    :    0050c29cdb66 14140002 14140001 fffffffc OK
 **/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAC_STR = 1,
    IP_STR = 2,
};

static inline char *byte_to_str(unsigned char *addr, char *str, size_t size, uint8_t type)
{
    int i, pos = 0;

    if (addr == NULL || str == NULL) return NULL;

    switch (type) {
        case MAC_STR:
            for (i = 0; i < 12; i=i+2) {
                uint8_t sbyte[2];
                memset(sbyte, 0, 2);
                memcpy(&sbyte, (addr + i), 2);
                if (pos < size)
                    pos += sprintf(str + pos, "%c%c:", sbyte[0], sbyte[1]);

            }
            break;
        case IP_STR:
            for (i = 0; i < 8; i=i+2) {
                uint8_t s_byte[2], dbyte;

                memcpy(&s_byte, (addr + i), 2);
                dbyte = (uint8_t) strtol((const char *) &s_byte, NULL, 16);;

                if (pos < size)
                    pos += sprintf(str + pos, "%u.", dbyte);
            }
            break;
        default:
            break;
    }
    str[pos - 1] = '\0';

    return str;
}

static inline char byte_to_ascii(const char *input)
{
    char  c[2], out;

    memcpy(&c, input, 2);
    sprintf(&out, "%c", (int)strtol((const char *) &c, NULL, 16));

    return out;
}

static inline int hexstr_to_ascii(const char *input, unsigned int length, char *output)
{
    int         m_index, s_index = 0, pos = 0;
    char        buffer[length];

    memset(buffer, 0, length);
    for (m_index = 0; m_index < (length - 1); m_index++) {
        s_index = m_index * 2;
        char b = byte_to_ascii(&input[s_index]);
        memcpy(&buffer[m_index], &b, 1);
    }
    buffer[m_index] = '\0';
    memcpy(output, buffer, length);

    return 0;
}

int main()
{
    char    *hex = "3030353063323963646236363134313430303032313431343030303166666666666666634f4b";
    size_t  l = strlen(hex);
    int     i;
    char    buf = 0;

    printf("%s\n", hex);

#define MAC_HEX_LEN             (6 * 2)
#define IP_HEX_LEN              (4 * 2)

#define MAC_HEX_POS             (MAC_HEX_LEN)
#define ETH_IP_HEX_POS          ((MAC_HEX_POS) * 2)
#define SER_IP_HEX_POS          ((ETH_IP_HEX_POS) + ((IP_HEX_LEN) * 2))
#define SUBNET_HEX_POS          ((SER_IP_HEX_POS) + ((IP_HEX_LEN) * 2))

    size_t  mlen = (MAC_HEX_LEN) + 1;
    size_t  iplen = (IP_HEX_LEN) + 1;

    char    mac[mlen], eth_ip[iplen], ser_ip[iplen], subnet[iplen];

    memset(mac, 0, mlen);
    memset(eth_ip, 0, iplen);
    memset(ser_ip, 0, iplen);
    memset(subnet, 0, iplen);

    char mac_id[32], ether_ip[16], server_ip[16], subnet_mask[16];

    hexstr_to_ascii(hex, mlen, mac);
    printf("%s\n", mac);
    byte_to_str(mac, mac_id, 32, MAC_STR);
    printf("%s\n", mac_id);

    hexstr_to_ascii(hex+ETH_IP_HEX_POS, iplen, eth_ip);
    printf("%s\n", eth_ip);
    byte_to_str(eth_ip, ether_ip, 16, IP_STR);
    printf("%s\n", ether_ip);

    hexstr_to_ascii(hex+SER_IP_HEX_POS, iplen, ser_ip);
    printf("%s\n", ser_ip);
    byte_to_str(ser_ip, server_ip, 16, IP_STR);
    printf("%s\n", server_ip);

    hexstr_to_ascii(hex+SUBNET_HEX_POS, iplen, subnet);
    printf("%s\n", subnet);
    byte_to_str(subnet, subnet_mask, 16, IP_STR);
    printf("%s\n", subnet_mask);
}
