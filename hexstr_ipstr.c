#include <stdio.h>
#include <string.h>
#include <stdint.h>


int main()
{
    char *ipstr = "fffffffc";
    size_t l = strlen(ipstr);

    int i, pos = 0;
    char    ip[16];

    for (i=0; i<8; i+=2) {
        uint8_t st_byte[2];
        memset(st_byte, 0, 2);
        memcpy(&st_byte, (ipstr + i), 2);
        printf("%c%c ", st_byte[0], st_byte[1]);
        uint8_t test_byte = (uint8_t) strtol((const char *) &st_byte, NULL, 16);;
        pos += sprintf(ip + pos, "%u.", test_byte);
    }
    ip[pos-1] = '\0';
    printf("\n decimal : %s\n", ip);
}
