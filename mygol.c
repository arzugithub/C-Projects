/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>


#define CTYPE char
#define LENGTH 8

void show(CTYPE a[LENGTH][LENGTH]) {
  int i,j;
  for (i=0; i<=LENGTH-1; i++) {
    for (j=0; j<=LENGTH-1; j++) 
      printf("%d, ",a[i][j]);
    printf("\n");
  }
}  
/*******************************************************************************
                            Main 
*******************************************************************************/
int main(int argc , char **argv) {
  CTYPE next[LENGTH][LENGTH]=
                { 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0 };
  CTYPE current[LENGTH][LENGTH] = 
                { 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 1, 0, 0, 0, 0,
                  0, 1, 1, 1, 0, 0, 0, 0,
                  0, 0, 0, 1, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0 };
  int i,j;
  int total;
  CTYPE c;
  show(current);
  printf("\n");
  while(1) {
    total=0;
     /* loop over all cells */
    for (i=0; i<LENGTH; i++) {
      for (j=0; j<LENGTH; j++) {
        if ( i>0 && j>0 && i<LENGTH-1 && j<LENGTH-1)   
          total=current[i][j-1] + current[i][j+1] + current[i-1][j] + current[i+1][j] + 
                current[i-1][j-1] + current[i-1][j+1] + current[i+1][j-1] + current[i+1][j+1];
       
        if ( i==0 && j>0 && j<LENGTH-1 ) 
          total=current[i][j-1] + current[i][j+1]  + current[i+1][j] +  current[i+1][j-1] + current[i+1][j+1];
        
        if ( i==LENGTH-1 && j>0 && j<LENGTH-1)
          total=current[i][j-1] + current[i][j+1] + current[i-1][j] + current[i-1][j-1] + current[i-1][j+1];

        if ( j==0 && i>0 && i<LENGTH-1 ) 
          total=current[i][j+1] + current[i-1][j] + current[i+1][j] + current[i-1][j+1] + current[i+1][j+1]; 
 
        if ( j==LENGTH-1 && i>0 && i<LENGTH-1)
          total=current[i][j-1] + current[i-1][j] + current[i+1][j] + current[i-1][j-1] + current[i+1][j-1];
        
        if ( i==0 && j==0 )
          total=current[i][j+1] + current[i+1][j] + current[i+1][j+1];
        
        if ( i==0 && j==LENGTH-1)
          total=current[i][j-1] + current[i+1][j] + current[i+1][j-1];  
        
        if ( i==LENGTH-1 && j==0)
          total=current[i][j+1] + current[i-1][j] + current[i-1][j+1]; 
           
        if ( i==LENGTH-1 && j==LENGTH-1)
          total=current[i][j-1] + current[i-1][j] + current[i-1][j-1];
          
        if ( ((total==2 || total==3) && current[i][j]==1) || (total==3 && current[i][j]==0) ) next[i][j]=1; 
          else next[i][j]=0;

        
      }
    }


    /*for (i=1;i<LENGTH-1;i++) {
        for (j=1;i<LENGTH-1;j++) {
          total=current[i][j-1] + current[i][j+1] + current[i-1][j] + current[i+1][j] + 
                current[i-1][j-1] + current[i-1][j+1] + current[i+1][j-1] + current[i+1][j+1]; 
          if ( ((total==2 || total==3) && current[i][j]==1) || (total==3 && current[i][j]==0) ) next[i][j]=1; 
          else next[i][j]=0;
        } 
      }
      for (j=1; j<LENGTH-1; j++) {
        total=current[0][j-1] + current[0][j+1]  + current[1][j] +  current[1][j-1] + current[1][j+1]; 
	if ( ((total==2 || total==3) && current[i][j]==1) || (total==3 && current[i][j]==0) ) next[i][j]=1; 
        else next[i][j]=0;
      }
      for (j=1; j<LENGTH-1; j++) {
        total=current[LENGTH-1][j-1] + current[LENGTH-1][j+1]  + current[LENGTH-2][j] +  current[LENGTH-2][j-1] + current[LENGTH-2][j+1]; 
	if ( ((total==2 || total==3) && current[i][j]==1) || (total==3 && current[i][j]==0) ) next[i][j]=1; 
        else next[i][j]=0;
      }
      for (i=1; i<LENGHT-1; i++) {
        total=current[i][1] + current[i-1][0] + current[i+1][0] + current[i-1][1] + current[i+1][1]; 
        if ( ((total==2 || total==3) && current[i][j]==1) || (total==3 && current[i][j]==0) ) next[i][j]=1; 
        else next[i][j]=0;
      }
      for (i=1; i<LENGHT-1; i++) {
        total=current[i][LENGTH-2] + current[i-1][LENGTH-2] + current[i+1][LENGTH-2] + current[i-1][LENGTH-1] + current[i+1][LENGTH-1];
        if ( ((total==2 || total==3) && current[i][j]==1) || (total==3 && current[i][j]==0) ) next[i][j]=1; 
        else next[i][j]=0;
      }*/
   


 
     /* Copy cells from "next" to "current" */
    for (i=0; i<=7; i++) {
      for (j=0; j<=7; j++) 
        current[i][j]=next[i][j];
     }
     show(current);
     
     /* Wait for input from keyboard */
     c = fgetc(stdin);
     if ( c == 'q' || c == 'x') break;

  }

  
  return 0;
}
/*******************************************************************************
                            EOF
*******************************************************************************/
