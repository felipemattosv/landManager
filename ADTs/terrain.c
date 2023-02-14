#include "terrain.h"
#include "person.h"
#include "date.h"
#include "address.h"
#include <stdlib.h>
#include <stdio.h>

struct terrain {

    Person owner;
    Date lastCleaning;
    Address address;
    float area;
    char broker[64];
};

Terrain terrain_create() {

    Terrain t = (Terrain)calloc(1, sizeof(struct terrain));
    t->owner = person_create();
    t->lastCleaning = date_create();
    t->address = address_create();

    return t;
}

void terrain_destroy(Terrain t) {

    person_destroy(t->owner);
    date_destroy(t->lastCleaning);
    address_destroy(t->address);
    free(t);
}

void terrain_set(Terrain t) {

    printf("Type owner's information:\n");
    person_set(t->owner);

    printf("Type date of last cleaning:\n");
    date_set(t->lastCleaning);

    printf("Type terrain's address:\n");
    address_set(t->address);

    printf("Type terrain's area: ");
    scanf("%f%*c", &t->area);

    printf("Type terrain's associated broker: ");
    scanf("%[^\n]", t->broker);

    printf("Terrain registred!\n\n");
}