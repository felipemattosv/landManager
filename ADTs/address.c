#include "address.h"
#include <stdlib.h>

struct address {

    char street[64];
    char state[3];
    int number;
    int zipCode[5];
};

Address address_create() {

    return (Address)calloc(1, sizeof(struct address));
}

void address_destroy(Address a) {

    free(a);
}