#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*CN: hosts file category type defined*/
typedef enum {
    DNS_FILTER_UNKNOWN = 0,
    DNS_FILTER_PORN = 1,
    DNS_FILTER_AD = 2,
    DNS_FILTER_MALWARE = 3,
    DNS_FILTER_SOCIAL = 4,
    DNS_FILTER_GAMES = 5,
    DNS_FILTER_MAX = DNS_FILTER_GAMES + 1,
} DNS_FILTER;

#define HOSTS_PORN      "/tmp/hosts.porn"
#define HOSTS_AD        "/tmp/hosts.ad"
#define HOSTS_MALWARE   "/tmp/hosts.malware"
#define HOSTS_SOCIAL    "/tmp/hosts.social"
#define HOSTS_GAMES     "/tmp/hosts.games"

typedef struct cat_arr_s {
#define HOSTS_FILE_LEN      256
#define CAT_STR_LEN         64
    uint16_t    cat;
    char        str[CAT_STR_LEN];
    char        hosts[HOSTS_FILE_LEN];
} cat_arr_t;

cat_arr_t g_cat_arr[DNS_FILTER_MAX] = {
    {
        .cat = DNS_FILTER_UNKNOWN,
        .hosts = "unknown",
        .str = "unknown"
    },
    {
        .cat = DNS_FILTER_PORN,
        .hosts = HOSTS_PORN,
        .str = "porn"
    },
    {
        .cat = DNS_FILTER_AD,
        .hosts = HOSTS_AD,
        .str = "ads"
    },
    {
        .cat = DNS_FILTER_MALWARE,
        .hosts = HOSTS_MALWARE,
        .str = "malware"
    },
    {
        .cat = DNS_FILTER_SOCIAL,
        .hosts = HOSTS_SOCIAL,
        .str = "social"
    },
    {
        .cat = DNS_FILTER_GAMES,
        .hosts = HOSTS_GAMES,
        .str = "games"
    },
};


static inline uint16_t get_dns_category(char *fname)
{

    uint16_t i, cat = DNS_FILTER_UNKNOWN;

    if (!fname) return cat;

    for (i = DNS_FILTER_UNKNOWN; i < DNS_FILTER_MAX; i++) {
        if (0 == strcmp(g_cat_arr[i].hosts, fname)) {
            return g_cat_arr[i].cat;
        }
    }

    return cat;
}

static inline char *dns_category_str(uint16_t cat)
{
    if (cat > DNS_FILTER_MAX) {
        return "unknown";
    }
    return g_cat_arr[cat].str;
}

int main()
{
    printf("%s : %d : %s\n", HOSTS_PORN, get_dns_category(HOSTS_PORN),
                            dns_category_str(get_dns_category(HOSTS_PORN)));

    printf("%s : %d : %s\n", HOSTS_AD, get_dns_category(HOSTS_AD),
                            dns_category_str(get_dns_category(HOSTS_AD)));

    printf("%s : %d : %s\n", HOSTS_MALWARE, get_dns_category(HOSTS_MALWARE),
                        dns_category_str(get_dns_category(HOSTS_MALWARE)));

    printf("%s : %d : %s\n", HOSTS_SOCIAL, get_dns_category(HOSTS_SOCIAL),
                            dns_category_str(get_dns_category(HOSTS_SOCIAL)));

    printf("%s : %d : %s\n", HOSTS_GAMES, get_dns_category(HOSTS_GAMES),
                            dns_category_str(get_dns_category(HOSTS_GAMES)));

    return 0;
}

