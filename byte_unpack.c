#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

//2C : 0010

#define DCD                     7
#define CTS                     6
#define DSR                     5
#define PPP                     4
#define LCP                     3
#define IPCP                    2
#define NONE1                   1
#define NONE2                   0

#define BIT_SET(var, pos)       ((var) & (1 << (pos)))
#define BIT_VAL(var, pos)       (BIT_SET(var, pos) >> pos)

int main()
{
    //2C 0A 0D 4F 4B
    char    array[16] = {0x2c, 0x0a, 0x0d, 0x4f, 0x4b};

    int i;
    (void) i;
    /*
    for (i=0; i<5; i++) {
        printf("%d\n", array[i]);
    }
    */
    uint8_t sbyte = array[0];

    printf("sbyte: %d\n", sbyte);

    printf("DCD: %d\n", BIT_VAL(sbyte, DCD));
    printf("CTS: %d\n", BIT_VAL(sbyte, CTS));
    printf("DSR: %d\n", BIT_VAL(sbyte, DSR));
    printf("PPP: %d\n", BIT_VAL(sbyte, PPP));
    printf("LCP: %d\n", BIT_VAL(sbyte, LCP));
    printf("IPCP: %d\n", BIT_VAL(sbyte, IPCP));
    printf("NONE1: %d\n", BIT_VAL(sbyte, NONE1));
    printf("NONE2: %d\n", BIT_VAL(sbyte, NONE2));
}
