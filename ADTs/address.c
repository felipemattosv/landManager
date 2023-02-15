#include "address.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int address_compare(Address a, Address b) {

    if (strcmp(a->state, b->state)==0 && strcmp(a->street, b->street)==0 && a->number == b->number) return 1;
    
    else return 0;
}

void address_print(Address a) {

    printf("%s n.%d, %s %d", a->street, a->number, a->state, a->zipCode);
}

void address_fprint(Address a, FILE * f) {

    fprintf(f, "%s n.%d, %s %d", a->street, a->number, a->state, a->zipCode);
}