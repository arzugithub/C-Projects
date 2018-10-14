/*******************************************************************************
**********Arithmatic operations for two given numbers in the terminal***********
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Functions

/*******************************************************************************
                            Main 
*******************************************************************************/

int main(int argc , char **argv) {

  /*
  printf("\n");
  printf("Hello World!\n");
  printf("\n");
  */
  float a, b;
  if (argc!=3) {
    printf("Usage: You should enter 2 numbers!");
  }
  if (argc==3) {
    a = atof(argv[1]);//atof
    b = atof(argv[2]);
    printf(" first number = %f \n", a); 
    printf(" second number = %f \n", b);
    printf(" a + b = %f \n", a+b);
    printf(" a*b = %f \n " ,a*b);
    printf(" a-b = %f \n " ,a-b);
    printf(" a/b = %f \n " ,a/b);

  }
  return 0;
}
/*******************************************************************************
                            EOF
*******************************************************************************/
