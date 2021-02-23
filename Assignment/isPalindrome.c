#include "myutils.h"


int pal_indrome(int n)
{
    int rev = 0, remainder, original;

    original = n;

  
    // reversed integer is stored in reversedN

    while (n != 0) 
    {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }

    // palindrome if orignalN and reversedN are equal

    if (original == rev)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);

    return 0;
}
