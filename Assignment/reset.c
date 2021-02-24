#include "bitmask.h"

int reset(int number,int key)
{
    return(number&(~(1 < <(key-1))));
}