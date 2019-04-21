/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "3par.h"

#define G 1

static double p_x3,p_y3,p_x1,p_y1,p_x2,p_y2,p_vx3,p_vy3,p_vx1,p_vy1,p_vx2,p_vy2;
static double p_ax3,p_ay3,p_ax1,p_ay1,p_ax2,p_ay2,p_m1,p_m2,p_m3,g=G;
static double p_dt;

/*******************************************************************************
        int_init(double dt): initialize integrator 
*******************************************************************************/
void int_init(double dt) {
  p_dt=dt;
}
  
/*******************************************************************************
        mass_init(double m1, double m2, double m3): initialize masses 
*******************************************************************************/
void mass_init(double m1, double m2, double m3) {
  p_m1=m1;
  p_m2=m2;
  p_m3=m3;
}

/*******************************************************************************
    pos_init(double x1, double y1, double x2, double y2, double x3, double y3): 
                         initializes postions 
*******************************************************************************/
void pos_init(double x1, double y1, double x2, double y2, double x3, double y3) {
  p_x1=x1;
  p_x2=x2;
  p_x3=x3;
  p_y1=y1;
  p_y2=y2;
  p_y3=y3;
}

/*******************************************************************************
    vel_init(double vx1, double vy1, double vx2, double vy2, double vx3, double vy3): 
                         initializes velocities 
*******************************************************************************/
void vel_init(double vx1, double vy1, double vx2, double vy2, double vx3, double vy3) {
  p_vx1=vx1;
  p_vx2=vx2;
  p_vx3=vx3;
  p_vy1=vy1;
  p_vy2=vy2;
  p_vy3=vy3;
}
 
/*******************************************************************************
             Function dst to return distance between two points
                         (x1,y1) and (x2,y2) 
*******************************************************************************/
double dst(double x1,double y1,double x2, double y2) {
  double rx,ry;
  rx=x2-x1;
  ry=y2-y1;
  return sqrt(rx*rx+ry*ry);
}


/*******************************************************************************
         Function aclx to return calculate acceleration of each particle
*******************************************************************************/ 
void acl() {
  double r12,r13,r23,f12x,f12y,f13x,f13y,f23x,f23y;  /* fij is the force has been felt by particle i in gravity of particle j */
  double f1x,f1y,f2x,f2y,f3x,f3y;                    /* fijx= x-component of fij; fijy= y-component of fij */  
  
  
  /* calculating distance between each pair of particles */
  r12=dst(p_x1,p_y1,p_x2,p_y2);
  r13=dst(p_x1,p_y1,p_x3,p_y3);
  r23=dst(p_x2,p_y2,p_x3,p_y3);

  /* computing x and y components of forces */
  f12x=(g*p_m1*p_m2)*(p_x2-p_x1)/(r12*r12*r12);             
  f12y=(g*p_m1*p_m2)*(p_y2-p_y1)/(r12*r12*r12);      
  f13x=(g*p_m1*p_m2)*(p_x3-p_x1)/(r13*r13*r13);
  f13y=(g*p_m1*p_m2)*(p_y3-p_y1)/(r13*r13*r13);
  f23x=(g*p_m2*p_m3)*(p_x3-p_x2)/(r23*r23*r23); 
  f23y=(g*p_m2*p_m3)*(p_y3-p_y2)/(r23*r23*r23); 
  f1x=f12x+f13x;
  f1y=f12y+f13y;
  f2x=f23x-f12x;
  f2y=f23y-f12y;
  f3x=-1*f13x-f23x;
  f3y=-1*f13y-f23y;
  
  /* computing x and y acceleration components */
  p_ax1=f1x/p_m1;
  p_ay1=f1y/p_m1;
  p_ax2=f2x/p_m2;
  p_ay2=f2y/p_m2;
  p_ax3=f3x/p_m3;
  p_ay3=f3y/p_m3;  
}       

/*******************************************************************************
                    Update function: computes the new state system
*******************************************************************************/
void up_3par() {
 
 acl();
 p_vx1=p_vx1+(p_dt/2)*p_ax1; 
 p_vy1=p_vy1+(p_dt/2)*p_ay1;
 p_vx2=p_vx2+(p_dt/2)*p_ax2;
 p_vy2=p_vy2+(p_dt/2)*p_ay2;
 p_vx3=p_vx3+(p_dt/2)*p_ax3;
 p_vy3=p_vy3+(p_dt/2)*p_ay3;            
 p_x1=p_x1+p_dt*p_vx1;
 p_y1=p_y1+p_dt*p_vy1;
 p_x2=p_x2+p_dt*p_vx2;
 p_y2=p_y2+p_dt*p_vy2;
 p_x3=p_x3+p_dt*p_vx3;
 p_y3=p_y3+p_dt*p_vy3; 
 acl();
 p_vx1=p_vx1+(p_dt/2)*p_ax1; 
 p_vy1=p_vy1+(p_dt/2)*p_ay1;
 p_vx2=p_vx2+(p_dt/2)*p_ax2;
 p_vy2=p_vy2+(p_dt/2)*p_ay2;
 p_vx3=p_vx3+(p_dt/2)*p_ax3;
 p_vy3=p_vy3+(p_dt/2)*p_ay3; 

}

/*******************************************************************************
          Different "get" functions to return the state of each partticle 
*******************************************************************************/
double get_posx_1() {return p_x1;}

double get_posy_1() {return p_y1;}

double get_posx_2() {return p_x2;}

double get_posy_2() {return p_y2;}

double get_posx_3() {return p_x3;}

double get_posy_3() {return p_y3;}

double get_velx_1() {return p_vx1;}

double get_vely_1() {return p_vy1;}

double get_velx_2() {return p_vx2;}

double get_vely_2() {return p_vy2;}

double get_velx_3() {return p_vx3;}

double get_vely_3() {return p_vy3;}

double get_aclx_1() {return p_ax1;}

double get_acly_1() {return p_ay1;}

double get_aclx_2() {return p_ax2;}

double get_acly_2() {return p_ay2;}

double get_aclx_3() {return p_ax3;}

double get_acly_3() {return p_ay3;}

double get_int_init() {return p_dt;} 

double get_energy() {
  double r12,r13,r23,k,u;
  k= 0.5*(p_m1*(p_vx1*p_vx1+p_vy1*p_vy1)+p_m2*(p_vx2*p_vx2+p_vy2*p_vy2)+p_m3*(p_vx3*p_vx3+p_vy3*p_vy3));
  r12=dst(p_x1,p_y1,p_x2,p_y2);
  r13=dst(p_x1,p_y1,p_x3,p_y3);
  r23=dst(p_x2,p_y2,p_x3,p_y3); 
  u= -g*( (p_m1*p_m2)/(r12) + (p_m1*p_m3)/(r13) + (p_m2*p_m3)/(r23) );
  return (k+u);
}

double get_pot_energy() {
  double r12,r13,r23,u;
  r12=dst(p_x1,p_y1,p_x2,p_y2);
  r13=dst(p_x1,p_y1,p_x3,p_y3);
  r23=dst(p_x2,p_y2,p_x3,p_y3); 
  u= -g*( (p_m1*p_m2)/(r12) + (p_m1*p_m3)/(r13) + (p_m2*p_m3)/(r23) );
  return (u);
}

double get_kin_energy() {
  double k;
  k= 0.5*(p_m1*(p_vx1*p_vx1+p_vy1*p_vy1)+p_m2*(p_vx2*p_vx2+p_vy2*p_vy2)+p_m3*(p_vx3*p_vx3+p_vy3*p_vy3)); 
  return (k);
}



/*******************************************************************************
                leader function: main function which 
           initialize state of the system and call update 
*******************************************************************************/
void leader() {
  
  up_3par();
  /*return get_energy();*/
}


/*******************************************************************************
                            EOF
*******************************************************************************/
