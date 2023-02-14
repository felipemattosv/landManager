#include "terrain.h"
#include "person.h"
#include "date.h"
#include "address.h"

struct terrain {

    Person owner;
    Date lastCleaning;
    Address address;
    float area;
    char broker[64];
};