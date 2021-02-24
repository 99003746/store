#include "bitmask.h"

int flip(int num)
{
    int  flipnum;

    /* Input number from user */
   

    flipnum = ~num;

    printf("Original number = %d (in decimal)\n", num);
    printf("Number after bits are flipped = %d (in decimal)", flipnum);

    return 0
}