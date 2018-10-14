/*******************************************************************************
***********************Recursive Factorial Function*****************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Functions
int val;

int fact(int n) {
  //int val;
  if (n==1) 
    val = 1;
  else
    val = n*fact(n-1);
  return val;
}

/*******************************************************************************
                            Main 
*******************************************************************************/

int main(int argc , char **argv) {

  /*
  printf("\n");
  printf("Hello World!\n");
  printf("\n");
  */
  int x;
  //val = 5;
  //printf("val = %d\n", val);
  if (argc!=2) {
    printf("Usage: You should enter a number!");
  }
  if (argc==2) {
    x = atoi(argv[1]);//
    if (x<1) {
      printf(" Your number should be positive! \n");
      
    }
    else
      printf(" fact(%d) = %d \n", x,fact(x)); 
  }
  printf("val = %d\n", val);
  return 0;
}
/*******************************************************************************
                            EOF
*******************************************************************************/
