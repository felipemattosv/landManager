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

Address terrain_getAddres(Terrain t) {

    return t->address;
}

void terrain_print(Terrain t) {

    printf("Owner:\n");
    person_print(t->owner);
    printf("\n");

    printf("Last cleaning: ");
    date_print(t->lastCleaning);
    printf("\n");

    printf("Address: ");
    address_print(t->address);
    printf("\n");

    printf("Area: %.2f\n", t->area);

    printf("Associated broker: %s\n", t->broker);
}

int terrain_compareArea(const void *p1, const void *p2) {

    Terrain t1 = *(Terrain *)p1;
    Terrain t2 = *(Terrain *)p2;

    if (t2->area > t1->area) return 1;
    else if (t1->area > t2->area) return -1;
    else return 0;
}

char * terrain_getBroker(Terrain t) {

    return t->broker;
}

int terrain_compareDate(const void *p1, const void *p2) {

    Terrain t1 = *(Terrain *)p1;
    Terrain t2 = *(Terrain *)p2;

    return date_compare(t1->lastCleaning, t2->lastCleaning);    
}