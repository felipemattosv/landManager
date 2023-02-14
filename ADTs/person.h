#pragma once

typedef struct person * Person;

//Memory functions:
Person person_create();
void person_destroy(Person);