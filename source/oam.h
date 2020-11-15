/*
Bunch of helper functions and useful bits for working with Object Attribute Memory (OAM).
*/
#include <stdlib.h>

// Start of OAM memory.
#define MEM_OAM  ((volatile ObjectAttributes *)0x07000000)

// Block of OAM as expected by the GBA.
typedef struct {
    unsigned short attr0;
    unsigned short attr1;
    unsigned short attr2;
    unsigned short padding;
} __attribute__((packed, aligned(4))) ObjectAttributes;