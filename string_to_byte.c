/*
 * 
 * 0001000000010000OK
 * */


#include <stdio.h>
#include <stdint.h>
#include <string.h>

static void inline ascii_to_byte(char *buf, uint8_t *ret)
{
#define ASCII_CHAR  2
    uint8_t r[ASCII_CHAR], i;

    for (i=0; i<ASCII_CHAR; i++) {
        r[i] = buf[i];
    }
    *ret = strtol(r, NULL, 16);
}

int main()
{
    //char buf[1024] = "0001000000010000OK";
    char buf[1024] = "fcc8ec11eab8d67bOK";
    uint8_t r = 0, i;

    size_t l = strlen(buf);

    buf[l-2] = '\0';
    printf("recv-buf : %s : %ld\n", buf, strlen(buf));

    for (i=0; i<20; i=i+2) {
        ascii_to_byte(buf + i, &r);
        printf("%02X ", r);
    }
    printf("\n");
}
