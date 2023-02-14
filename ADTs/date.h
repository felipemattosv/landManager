#pragma once

typedef struct date * Date;

//Memory functions:
Date date_create();
void date_destroy(Date);

//Set functions:
void date_set(Date);