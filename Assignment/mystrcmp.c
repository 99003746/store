#include "string.h"


int string_comp()
{

    char str1[10]="Hello";
    char str2[10]="Hello";



    if(strcmp(str1, str2)==0)
    {
        printf("\n Both the strings are same");
    }

    else
    {
        printf("\n Both the strings are different");
    }

    // signal to operating system program ran fine
    return 0;
}
}