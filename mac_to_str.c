#include <stdio.h>

unsigned char mac[6] = {0x00, 0x0d, 0x3f, 0xcd, 0x02, 0x5f};

char* MACADDR_toString(unsigned char* addr)
{
    static char str[18];

    if(addr == NULL) return "";

    snprintf(str, sizeof(str), "%02x:%02x:%02x:%02x:%02x:%02x", 
             addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

    return str;
}

char* MACADDR_toString_r(unsigned char* addr, char* str, size_t size)
{
    if(addr == NULL || str == NULL || size < 18) return NULL;

    snprintf(str, size, "%02x:%02x:%02x:%02x:%02x:%02x", 
             addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

    return str;
}

int main(int argc, char* argv[])
{
    char str[18];
    printf("%s\n", MACADDR_toString(mac));
    printf("%s\n", MACADDR_toString_r(mac, str, sizeof(str)));
    return 0;
}
