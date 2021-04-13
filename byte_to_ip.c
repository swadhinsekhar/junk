#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

enum {
    MAC_STR,
    IP_STR
};

static char *byte_to_str(unsigned char *addr, uint8_t spos, uint8_t epos,
        char *str, size_t size, uint8_t type)
{
    int i, pos = 0;
    if (addr == NULL || str == NULL) return NULL;

    switch (type) {
        case MAC_STR:
            for (i = spos; i < epos; i++) {
                if (pos < size)
                    pos += sprintf(str + pos, "%02x:", addr[i]);
            }
            break;
        case IP_STR:
            for (i = spos; i < epos; i++) {
                if (pos < size)
                    pos += sprintf(str + pos, "%u.", (unsigned char) addr[i]);
            }
            break;
        default:
            break;
    }
    str[pos - 1] = '\0';

    return str;
}

int main()
{
    /*first 6 bytes MAC,
    next 4 bytes Ethernet IP,
    next 4 bytes Serial IP,
    last 4 bytes subnet followed by \n\r OK*/
    char    byte[32] = { 0x00, 0x50, 0xC2, 0x9C, 0xDA, 0x01,
                    0x0A, 0xFD, 0x0B, 0x36,
                    0x0A, 0xFD, 0x0B, 0x35,
                    0xFF, 0xFF, 0xFF, 0xFC,
                    0x0A, 0x0D, 0x4F, 0x4B};

    char    *ptr = byte;

    char    mac_id[18];
    char    ether_ip[15];
    char    ser_ip[15];
    char    subnet[15];

    printf("macid: %s\n", byte_to_str(ptr, 0, 6, mac_id, 18, MAC_STR));
    printf("ether_ip: %s\n", byte_to_str(ptr, 6, 10, ether_ip, 15, IP_STR));
    printf("ser_ip: %s\n", byte_to_str(ptr, 10, 14, ser_ip, 15, IP_STR));
    printf("subnet: %s\n", byte_to_str(ptr, 14, 18, ser_ip, 15, IP_STR));
}
