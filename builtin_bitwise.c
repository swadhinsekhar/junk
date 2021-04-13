#include <stdio.h>
#include <stdint.h>


enum ppe_af_pkt_size_stats {
    PKT_SZ_64 = 0,      //0 - 63
    PKT_SZ_128,         //64 - 127
    PKT_SZ_256,         //128 - 255
    PKT_SZ_512,         //256 - 511
    PKT_SZ_1024,        //512 - 1023
    PKT_SZ_GR_1024,     //1024 to -
    PKT_SZ_MAX,
};

inline static uint8_t pkt_len_idx (uint16_t pkt_len)
{
    if (pkt_len >= 64)
        return ((32 - __builtin_clz(pkt_len)) + 1) - 7;
    return 0;
}

int main()
{

    printf("%d\n", pkt_len_idx(32));        //0
    printf("%d\n", pkt_len_idx(64));        //1
    printf("%d\n", pkt_len_idx(128));       //2
    printf("%d\n", pkt_len_idx(256));       //3
    printf("%d\n", pkt_len_idx(512));       //4
    printf("%d\n", pkt_len_idx(1024));      //5
    printf("1024 :: %d\n", pkt_len_idx(1500) % PKT_SZ_MAX);
    printf("%d\n", pkt_len_idx(1501));
    printf("%d\n", pkt_len_idx(2047));
    printf("%d\n", pkt_len_idx(2048) % PKT_SZ_MAX);

    printf("\n1 mod 6 : %d\n", pkt_len_idx(64) % PKT_SZ_MAX);        //1
    printf("2 mod 6 : %d\n", pkt_len_idx(128) % PKT_SZ_MAX);       //2

    printf("5 % 6 = %d\n", (5 % 6));
    printf("6 % 6 = %d\n", (6 % 6));
    printf("7 % 6 = %d\n", (7 % 6));
}
