
/*******************************************************************************
****************************Average of n given numbers**************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*******************************************************************************
                            Main 
*******************************************************************************/

int main()
{
int i,n;
float sum,Avg=0, numbers;
printf("Enter the number of elements that you want make an average ?\n");
scanf("%d",&n);
printf("\nPlease Enter the elements one by one\n");
for (i=0; i<n; i++)
  {

   scanf("%f",&numbers);
     sum = sum +numbers;
   }

Avg =sum /n;
printf("Sum of %d Numbers = %f \n", n, sum);
printf("\n Avg of Numbers= %f ", Avg);

return 0;

}


