#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

void byte_dump(uint8_t *b, size_t sz)
{
    int i;

    for (i = 0; i<sz; i++) {
        printf("%02X ", b[i]);
    }
    printf("\n");
}


uint8_t *ipstr_to_byte(char *ipstr, uint8_t *ip, size_t sz)
{
    uint32_t     sip;

    sip = inet_addr(ipstr);
    //printf("%u \n", sip);

    memset(ip, 0, sz);

    ip[0] = (uint8_t) (sip & 0xFF);
    ip[1] = (uint8_t) ((sip >> 8) & 0xFF);
    ip[2] = (uint8_t) ((sip >> 16) & 0xFF);
    ip[3] = (uint8_t) ((sip >> 24) & 0xFF);

    return ip;
}

int main()
{
    char        ipstr[] = "10.253.11.54";   //o/p: 0A FD 0B 36
    char        ipstr2[] = "10.253.11.53";   //o/p: 0A FD 0B 36
    char        ipstr1[] = "255.255.255.252";   //o/p: FF FF FF FC
    uint8_t     ip[4];
    uint8_t     ip2[4];
    uint8_t     sn[4];

    ipstr_to_byte(ipstr, ip, 4);
    byte_dump(ip, 4);
    ipstr_to_byte(ipstr2, ip2, 4);
    byte_dump(ip2, 4);
    ipstr_to_byte(ipstr1, sn, 4);
    byte_dump(sn, 4);

    return 0;
}
