#include "myutils.h"


int factorial(int num)    
{    
 int i,factorial=1;    
   
    for(i=1;i<=num;i++)
    {    
      factorial=factorial*i;    
    }    
  printf("Factorial of %d is: %d",num,factorial);    

}
