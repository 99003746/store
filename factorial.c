#include<stdio.h>
#include<math.h>

    void factorial(int n)
{
    int i,fact=1;
    
    if(n==1)
    {
	
    printf("Factorial of a number is 1");
    }
    else
    {
	
    for(i=1; i<=n; i++)
    {
        fact=fact*i;
    }
    printf("Factorial of a number is= %d",fact);
}
}

int main (void)
{
   int num=1;
   factorial(num);
   return 0;
 
}
