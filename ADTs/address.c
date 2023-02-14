#include "address.h"
#include <stdlib.h>
#include <stdio.h>

struct address {

    char state[3];
    char street[64];
    int number;
    int zipCode;
};

Address address_create() {

    return (Address)calloc(1, sizeof(struct address));
}

void address_destroy(Address a) {

    free(a);
}

void address_set(Address a) {

    printf("State postal abreviattion: ");
    scanf("%s%*c", a->state);

    printf("Street: ");
    scanf("%[^\n]", a->street);

    printf("Number: ");
    scanf("%d", &a->number);

    printf("ZIP code: ");
    scanf("%d", &a->zipCode);
}