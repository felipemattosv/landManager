#include "date.h"
#include <stdlib.h>
#include <stdio.h>

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

void date_set(Date d) {

    printf("Day: ");
    scanf("%d", &d->day);

    printf("Month: ");
    scanf("%d", &d->month);

    printf("Year: ");
    scanf("%d", &d->year);
}