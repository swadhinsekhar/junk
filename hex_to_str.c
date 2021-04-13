#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define BIT_SET(var, pos)       ((var) & (1 << (pos)))
#define BIT_VAL(var, pos)       (BIT_SET(var, pos) >> pos)

int main()
{
    char    hex[16] = {0x32, 0x2E, 0x31, 0x32, 0x2E, 0x30, 0x0a, 0x0d, 0x4f, 0x4b};

    char hw_ver[4];
    char sw_ver[4];

    memset(hw_ver, 0 , 4);
    memset(sw_ver, 0 , 4);

    sprintf(hw_ver, "%c%c%c%c", hex[0], hex[1], hex[2], '\0');
    sprintf(sw_ver, "%c%c%c%c", hex[3], hex[4], hex[5], '\0');

    printf("hw-ver: %s\n", hw_ver);
    printf("sw-ver: %s\n", sw_ver);
}
