#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct person_s
{
    char        name[16];
    uint8_t     age;
    uint32_t    acc_num;
} person_t;

typedef struct country_s
{
    char        name[64];
    char        state[64];
    char        city[64];
    uint32_t    pin;
} country_t;

int pack_struct_data(void *data)
{
    if (!data) return -1;

    person_t    *person = (person_t *) data;
    country_t   *country = (country_t *) (data + sizeof(person_t));

    if (!person || !country) {
        printf("pack-struct: memeory creation error\n");
        return -1;
    }
    memset(person, 0, sizeof(person_t));
    memset(country, 0, sizeof(country_t));

    sprintf(person->name, "%s", "Sony");
    person->age = 28;
    person->acc_num = 5678234;

    sprintf(country->name, "%s", "India");
    sprintf(country->state, "%s", "Odisha");
    sprintf(country->city, "%s", "Cuttack");
    country->pin = 753012;

    return 0;
}

int extract_struct_data(void *data)
{
    if (!data) return -1;

    person_t    *person = (person_t *) data;
    country_t   *country = (country_t *) (data + sizeof(person_t));

    if (!person || !country) {
        printf("pack-struct: memeory creation error\n");
        return -1;
    }
    printf("person :    name: %s     age:%u    accno:%u\n",
            person->name, person->age, person->acc_num);
    printf("country:    name: %s    state:%s    city:%s     pin:%u\n",
            country->name, country->state, country->city, country->pin);

    return 0;
}

int main()
{
    void        *buf = NULL;

    //printf("%ld \n", ((sizeof (person_t) + (sizeof (country_t)))));
    buf = (void *) malloc((sizeof (person_t)) + (sizeof (country_t)));
    if (!buf) {
        printf("out of memory\n");
        return 0;
    }
    memset(buf, 0, sizeof(buf));

    if (pack_struct_data(buf) < 0) {
        goto bailout;
    }

    if ((extract_struct_data(buf) < 0)) {
        goto bailout;
    }

bailout:
    if (buf) free(buf);
    return 0;
}

