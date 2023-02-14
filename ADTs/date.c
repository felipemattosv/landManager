#include "date.h"
#include <stdlib.h>

struct date {

    int year;
    int month;
    int day;
};

Date date_create() {

    return (Date)calloc(1, sizeof(struct date));
}

void date_destroy(Date d) {

    free(d);
}