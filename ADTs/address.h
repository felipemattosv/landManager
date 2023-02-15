#pragma once

typedef struct address * Address;

//Memory functions:
Address address_create();
void address_destroy(Address);

//Set functions:
void address_set(Address);

//Compare functions:
int address_compare(Address, Address);

//Print functions:
void address_print(Address);