/*******************************************************************************
*****************************Addition of two numbers****************************
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
  int a, b;
  if (argc!=3) {
    printf("Usage: You should enter 2 numbers!");
  }
  if (argc==3) {
    a = atoi(argv[1]);//atof
    b = atoi(argv[2]);
    printf(" first number = %d \n", a); 
    printf(" second number = %d \n", b);
    printf(" a + b = %d \n", a+b);
  }
  return 0;
}
/*******************************************************************************
                            EOF
*******************************************************************************/
