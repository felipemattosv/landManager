#include "person.h"
#include "date.h"
#include <stdlib.h>
#include <stdio.h>

struct person {

    char name[64];
    int id;
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

void person_set(Person p) {

    printf("Name: ");
    scanf("%[^\n]", p->name);

    printf("ID: ");
    scanf("%d%*c", &p->id);

    printf("Sex (M or F): ");
    scanf("%c", &p->sex);

    printf("Date of birth:\n");
    date_set(p->birth);
}

void person_print(Person p) {

    printf("Name: %s |", p->name);
    printf(" ID: %d |", p->id);
    printf(" Sex: %c |", p->sex);
    printf(" Birth: ");
    date_print(p->birth);
}

void person_fprint(Person p, FILE * f) {

    fprintf(f, "Name: %s |", p->name);
    fprintf(f, " ID: %d |", p->id);
    fprintf(f, " Sex: %c |", p->sex);
    fprintf(f, " Birth: ");
    date_fprint(p->birth, f);
}