/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Functions

/*******************************************************************************
                            Main 
*******************************************************************************/

int main(int argc , char **argv) {  // argc = number of words in the command line, argv: each command word

  /*
  printf("\n");
  printf("Hello World!\n");
  printf("\n");
  */
  int n, m;
  int i, j;

  printf("\n");
  if (argc!=3)
    printf("Usage: Enter only two integer numbers, e.g. ./mat_agv 4 3 \n");
  else {
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    printf("number of rows = %d \n", n); 
    printf("number of columns = %d \n", m);
  }
  float mat[n][m];
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) {
      mat[i][j] = 0;
    }
  }
  ////////////////////////////
  ////////Get mat////////////
  //////////////////////////
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) {
      scanf("%e", &mat[i][j]);
      printf("%e \n", mat[i][j]);
    }
  }

  ////////////////////////////
  /////////Print mat//////////
  ////////////////////////////
  for (i=0; i<n; i++) {
    printf("|");
    for (j=0; j<m; j++) {
      //printf("mat[%d][%d] ", i,j);
      printf("%e ", mat[i][j]);
    }
    printf("|");
    printf("\n");
  }
  float sum=0;
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      sum = sum + mat[i][j];
  printf("Average = %f \n", sum/n/m);
  
  printf("\n");
  
  return 0;
}
/*******************************************************************************
                            EOF
*******************************************************************************/
