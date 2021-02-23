#include "myutils.h"


int main()    
{    
 int i,factorial=1,num=5;    
   
    for(i=1;i<=num;i++)
    {    
      factorial=factorial*i;    
    }    
  printf("Factorial of %d is: %d",num,factorial);    
return 0;  
}