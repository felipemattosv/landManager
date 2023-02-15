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

void date_print(Date d) {

    printf("%d/%d/%d", d->month, d->day, d->year);
}

int date_compare(Date d1, Date d2) {

    if (d1->year < d2->year) {
        return -1;
    } 
    else if (d1->year > d2->year) {
        
        return 1;
    } 
    else {

        if (d1->month < d2->month) {
            
            return -1;
        } 
        else if (d1->month > d2->month) {
            
            return 1;
        } 
        else {

            if (d1->day < d2->day) {
                
                return -1;
            } 
            else if (d1->day > d2->day) {
                
                return 1;
            } 
            else {
                
                return 0;
            }
        }
    }
}