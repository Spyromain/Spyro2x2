#include "Sp2.h"


void Sp2x2Swap(void *restrict first, void *restrict second, int count)
{
    unsigned char buffer[count];

    Sp2MemCpy(&buffer, first, count);
    Sp2MemCpy(first, second, count);
    Sp2MemCpy(second, &buffer, count);
}
