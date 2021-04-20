#include <stdio.h>
#include <stdint.h>

#define CR          0x0D

#define snoop_cmd   0x23
int main()
{
    uint8_t tx_clk = 1;
    uint8_t rx_clk = 0;
    char    byte[4];

    byte[0] = snoop_cmd;
    byte[1] = tx_clk;;
    byte[2] = rx_clk;
    byte[3] = CR;

    int i;

    for (i=0; i < 4; i++) {
        printf("%02x ", byte[i]);
    }
    printf("\n");
}
