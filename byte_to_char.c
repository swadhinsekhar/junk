#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define snzprintf(dst, fmt, data...) do { \
            size_t sz = sizeof(dst); \
            memset(dst, 0, sz); \
            snprintf(dst, (sz-1), fmt, data); \
        } while(0)


int main()
{
    char buf[] = {0x32, 0x2E, 0x30};
    uint8_t sw[4];

    printf("%c\n", buf[2]);
    sprintf(sw, "%c%c%c%c", (char) buf[0], (char)buf[1], buf[2], '\0');


    printf("%s\n", sw);

    return 0;
}
