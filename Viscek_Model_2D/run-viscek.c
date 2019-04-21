#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ranlxs.h"
#include "viscek.h"

#define PI 3.14159265358979
#define DEF_DT 1
#define DEF_NUM 10
#define DEF_L 1
#define DEF_V0 0.1
#define DEF_R0 0.05
#define DEF_NI 0
#define NSTEP 1

/*******************************************************************************
                            Main 
*******************************************************************************/
int main(int argc , char **argv) {
  if (argc!=2) {
    fprintf(stderr,"WARNING!!! You must enter the dt and nsteps repectively!!!");
    exit(0);
  }
  int i;
  FILE *trs = fopen( "trs.txt" , "wb" );
  float psi=0,ni=0;
  int_init(DEF_DT);
  num_init(DEF_NUM);
  side_init(DEF_L);
  v0_init(DEF_V0);
  r0_init(DEF_R0);
  ni_init(DEF_NI);
  state_init();
  fprintf(stderr,"dt= %f  num= %d  l= %f\n",get_int_init(),get_num_init(),get_side_init());
  fprintf(stderr,"v0= %f  r0= %f  ni= %f\n",get_v0_init(),get_r0_init(),get_ni_init());
  
  /* plotting statianary state graph versus noise intensity */ 
  /*do {                                       
    for (i=100; i<atoi(argv[1]); i++) {*/
      /*ex_up();*/
      /*in_up(); 
      psi=psi+station();
    */
      /*show();*/
    /*}*/ 
    /*fprintf(trs,"%f %f\n",ni,psi/(i-100));
    ni=ni+0.05;
    ni_init(ni);
    psi=0;
  } while (ni<1);*/

  /* showing the results using files */
  for (i=0; i<atoi(argv[1]); i++) {
    ex_up();
  }
  show(); 
  return 0;
}


/*******************************************************************************
                            EOF
gcc -c viscek.c
gcc run-viscek.c viscek.o ranlxs.o -o run-viscek
./run-viscek 1 | graph -T X -C -m 1
graph -T png -C -m 3 f1.txt  -m 1 f2.txt  -m 2 f3.txt -m 4 f4.txt  > 25.png 
graph -T png -C -m 3 f1.txt  -m 1 f2.txt  -m 2 f3.txt -m 4 f4.txt -m 3 f5.txt  -m 1 f6.txt  -m 2 f7.txt -m 4 f8.txt -m 2 f9.txt -m 4 f10.txt  > 4.png   

trs.png: phase diagram for extrinsic noise
trs1.png: phase diagram for intrensic noise
#define PI 3.14159265358979
#define DEF_DT 1
#define DEF_NUM 400
#define DEF_L 10
#define DEF_V0 1.0
#define DEF_R0 1.0
#define DEF_NI 0
#define NSTEP 1
resolution=0.05
./run-viscek 8000 | graph -T X -m 1
graph -T png -C -m 3 trs.txt > trs.png

  
*******************************************************************************/
