#pragma once

typedef struct address * Address;

//Memory functions:
Address address_create();
void address_destroy(Address);