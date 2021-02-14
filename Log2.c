#include <stdio.h> 
#include<math.h>
  
void product(int a, int b) 
{ 
   double result;
   result=log(a)+log(b);
    printf("result of product is=%d ",result); 
} 
void ratios(int a, int b) 
{ 
   double result;
   result=log(a)-log(b);
    printf("result of ratios is=%d ",result); 
} 

int main(void) 
{ 
    float x= 5, y = 7; 
  
    // Passing parameters 
    product(x, y); 
    ratios(x,y);

    return 0; 
}


