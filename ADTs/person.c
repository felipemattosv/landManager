#include "person.h"
#include "date.h"
#include <stdlib.h>

struct person {

    char name[64];
    int id[12];
    char sex;
    Date birth;
};

Person person_create() {

    Person p = (Person)calloc(1, sizeof(struct person));
    p->birth = date_create();

    return p;
}

void person_destroy(Person p) {

    date_destroy(p->birth);
    free(p);
}