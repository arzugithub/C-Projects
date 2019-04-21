/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>


static int r,s,state,k;
static char x[32];
static char flag;
static int init;


/*******************************************************************************
       ranbit1_init(int r, int s): initialize parameters (r and s) 
*******************************************************************************/
void ranbit1_init(int r1, int s1) {
  s=s1;
  r=r1;
}

/*******************************************************************************
       void ranbit1_seed(int seed): initialize state with seed 
*******************************************************************************/
void ranbit1_seed(int seed) {
  state=seed;
  int j;
  
  for (j=0;j<s;j++) {
    x[j]=(state&1);
    state>>=1;
  }
}
/*******************************************************************************
       void ranbit1_show(): print individual bits of current state 
*******************************************************************************/
void ranbit1_show() {
  int j;
  printf("Binary state = ");
  for (j=s-1;j>-1;j--) printf("%d",x[j]);  
  printf("\n\n");
}
/*******************************************************************************
       void ranbit1_step1(): update single bit according to
        x_k = x_{k-r} XOR x_{k-s}      (k = s, s+1, ... )
*******************************************************************************/
void ranbit1_step1() {

  x[k-s]= x[(k-r) % s] ^ x[k-s];
}
/*******************************************************************************
       void ranbit1_steps(): update s bits according to
        x_k = x_{k-r} XOR x_{k-s}      (k = s, s+1, ... )
*******************************************************************************/
void ranbit1_steps() {
  for (k=s; k<2*s; k++) 
    ranbit1_step1();
}
/*******************************************************************************
int  ranbit1_get_state():return integer value which encodes current (macro-)state 
*******************************************************************************/
int ranbit1_get_state() {
  int j;
  int temp=1;
  int u=0;
  
  for (j=0; j<s; j++) {
    u=u+temp*x[j];
    temp=temp*2;
  }
  return u;
}
/*******************************************************************************
           int  ranbit1(): update s bits and return state as int 
*******************************************************************************/
int  ranbit1() {
  if (!flag)
    ranbit1_seed(init);
  flag=1;
  ranbit1_steps();
  return ranbit1_get_state();
}
