#pragma once

#include <stdio.h>

typedef struct date * Date;

//Memory functions:
Date date_create();
void date_destroy(Date);

//Set functions:
void date_set(Date);

//Printf functions:
void date_print(Date);
void date_fprint(Date, FILE *);

//Compare functions:
int date_compare(Date, Date);