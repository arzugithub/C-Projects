#ifndef __VISCEK_H__
/* 
     Function prototypes for viscek.c
*/
#define  __VISCEK_H__

void int_init(double dt);
void num_init(int n);
void side_init(double l);
void v0_init(double v0);
void r0_init(double r0);
void ni_init(double ni);
void state_init();
float noise();
double dst(double x1,double y1,double x2, double y2);
void ex_up();
void in_up();
float station();
void show();
float get_int_init();
int get_num_init();
float get_side_init();
float get_v0_init();
float get_r0_init();
float get_ni_init();



#endif
