#pragma once

typedef struct date * Date;

//Memory functions:
Date date_create();
void date_destroy(Date);

//Set functions:
void date_set(Date);

//Printf functions:
void date_print(Date);

//Compare functions:
int date_compare(Date, Date);