#ifndef __RANBIT_H__
/* 
     Function prototypes for state.c
*/
#define  __RANBIT_H__

void ranbit1_init(int r1, int s1);
void ranbit1_seed(int seed);
void ranbit1_show();
void ranbit1_step1();
void ranbit1_steps();
int ranbit1_get_state();
int  ranbit1();


#endif
