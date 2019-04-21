/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ranlxs.h"
#include "viscek.h"

#define PI 3.14159265358979
#define DEF_NUM 10
#define DELTA 0.01


static double p_dt,p_l,p_v0,p_r0,p_ni,p_ksi=0;
static double p_x[DEF_NUM], p_y[DEF_NUM], p_teta[DEF_NUM];
static int p_num;

/*******************************************************************************
        int_init(double dt): initializes integrator 
*******************************************************************************/
void int_init(double dt) {
   p_dt=dt;
}

/*******************************************************************************
        num_init(int n): initializes number of particles 
*******************************************************************************/
void num_init(int n) {
   p_num=n;
}


/*******************************************************************************
        side_init(double l): initializes side length 
*******************************************************************************/
void side_init(double l) {
  p_l=l;
}  

/*******************************************************************************
                v0_init(v0): initializes speed
*******************************************************************************/
void v0_init(double v0) {
  p_v0=v0;
}  

/*******************************************************************************
        r0_init(r0): initializes neighborhood radius 
*******************************************************************************/
void r0_init(double r0) {
  p_r0=r0;
}  

/*******************************************************************************
        ni_init(r0): initializes noise intensity
*******************************************************************************/
void ni_init(double ni) {
  p_ni=ni;
}  

/*******************************************************************************
      state_init(): initializes positions and velocities directions 
*******************************************************************************/
void state_init() {
  float rvec[1];
  int i;
  rlxs_init(2,1);
  for (i=0; i<p_num; i++) {
    ranlxs(rvec,1);
    p_x[i]= p_l*rvec[0];
    ranlxs(rvec,1);
    p_y[i]=p_l*rvec[0];
    ranlxs(rvec,1);
    p_teta[i]=2*PI*rvec[0];
  }
}

/*******************************************************************************
                 noise(): produces a random noise
*******************************************************************************/
float noise() {
  float rvec[1];
  ranlxs(rvec,1);
  return 2*PI*rvec[0];
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
                ex_up: computes the new state system in extrinsic mode
*******************************************************************************/
void ex_up() {
  int i,j,kn;
  float vx,vy,newtet[DEF_NUM],newx[DEF_NUM],newy[DEF_NUM];
  for (i=0; i<p_num; i++) {
    newtet[i]=0;
    newx[i]=0;
    newy[i]=0;
  }
  for (i=0; i<p_num; i++) {
    vx=0;
    vy=0;
    kn=0;
    for (j=0; j<p_num; j++) {
      if (j!=i) {
        if ( dst(p_x[i],p_y[i],p_x[j],p_y[j]) < p_r0) {
          kn=kn+1;
          vx=vx+p_v0*cos(p_teta[j]);
          vy=vy+p_v0*sin(p_teta[j]);
        }  
      }
    }
    
    if (kn!=0) { 
      vx=vx/kn;
      vy=vy/kn;
      if ( (vy==0) && (vx==0) ) {
        newx[i]= p_x[i];
        newy[i]= p_y[i];
      }
      else {
        
        vx=vx+p_ni*cos(noise());
        vy=vy+p_ni*sin(noise());
        if ( (vy>0) && (vx>0) ) newtet[i]=atan(vy/vx);
        if ( (vy<0) && (vx<0) ) newtet[i]=PI+atan(vy/vx);
        if ( (vy>0) && (vx<0) ) newtet[i]=PI-atan(-vy/vx);
        if ( (vy<0) && (vx>0) ) newtet[i]=2*PI-atan(-vy/vx);
        if ( (vy>0) && (vx==0) ) newtet[i]=PI/2;
        if ( (vy<0) && (vx==0) ) newtet[i]=-PI/2; 
        if ( (vy==0) && (vx>0) ) newtet[i]=0;
        if ( (vy==0) && (vx<0) ) newtet[i]=PI;
        newx[i]= p_x[i]+p_dt*p_v0*cos(newtet[i]);
        newy[i]= p_y[i]+p_dt*p_v0*sin(newtet[i]);
      }  
    } 
    else {
      newtet[i]=p_teta[i];
      newx[i]= p_x[i]+p_dt*p_v0*cos(newtet[i]);
      newy[i]= p_y[i]+p_dt*p_v0*sin(newtet[i]);
      
    }
  } 
  for (i=0; i<p_num; i++) {
    if (newx[i]>=p_l) newx[i]=newx[i]-p_l;
    if (newy[i]>=p_l) newy[i]=newy[i]-p_l; 
    if (newy[i]<0) newy[i]=newy[i]+p_l;
    if (newx[i]<0) newx[i]=newx[i]+p_l; 
    p_x[i]=newx[i];
    p_y[i]=newy[i];
    p_teta[i]=newtet[i];
  }
}

void in_up() {
  int i,j,kn;
  float vx,vy,newtet[DEF_NUM],newx[DEF_NUM],newy[DEF_NUM];
  for (i=0; i<p_num; i++) {
    newtet[i]=0;
    newx[i]=0;
    newy[i]=0;
  }
  for (i=0; i<p_num; i++) {
    vx=0;
    vy=0;
    kn=0;
    for (j=0; j<p_num; j++) {
      if (j!=i) {
        if ( dst(p_x[i],p_y[i],p_x[j],p_y[j]) < p_r0) {
          kn=kn+1;
          vx=vx+p_v0*cos(p_teta[j]);
          vy=vy+p_v0*sin(p_teta[j]);
        }  
      }
    }
    
    if (kn!=0) { 
      vx=vx/kn;
      vy=vy/kn;
      if ( (vy==0) && (vx==0) ) {
        newx[i]= p_x[i];
        newy[i]= p_y[i];
      }
      else {
        
        
        if ( (vy>0) && (vx>0) ) newtet[i]=atan(vy/vx)+p_ni*noise();
        if ( (vy<0) && (vx<0) ) newtet[i]=PI+atan(vy/vx)+p_ni*noise();
        if ( (vy>0) && (vx<0) ) newtet[i]=PI-atan(-vy/vx)+p_ni*noise();
        if ( (vy<0) && (vx>0) ) newtet[i]=2*PI-atan(-vy/vx)+p_ni*noise();
        if ( (vy>0) && (vx==0) ) newtet[i]=PI/2+p_ni*noise();
        if ( (vy<0) && (vx==0) ) newtet[i]=-PI/2+p_ni*noise(); 
        if ( (vy==0) && (vx>0) ) newtet[i]=0+p_ni*noise();
        if ( (vy==0) && (vx<0) ) newtet[i]=PI+p_ni*noise();
        newx[i]= p_x[i]+p_dt*p_v0*cos(newtet[i]);
        newy[i]= p_y[i]+p_dt*p_v0*sin(newtet[i]);
      }  
    } 
    else {
      newtet[i]=p_teta[i]+p_ni*noise();
      newx[i]= p_x[i]+p_dt*p_v0*cos(newtet[i]);
      newy[i]= p_y[i]+p_dt*p_v0*sin(newtet[i]);
      
    }
  } 
  for (i=0; i<p_num; i++) {
    if (newx[i]>=p_l) newx[i]=newx[i]-p_l;
    if (newy[i]>=p_l) newy[i]=newy[i]-p_l; 
    if (newy[i]<0) newy[i]=newy[i]+p_l;
    if (newx[i]<0) newx[i]=newx[i]+p_l; 
    p_x[i]=newx[i];
    p_y[i]=newy[i];
    p_teta[i]=newtet[i];
  }
}
float station() {
  int i;
  float sumx=0,sumy=0;
  for (i=0; i<p_num; i++) {
    sumx=sumx+p_v0*cos(p_teta[i]);
    sumy=sumy+p_v0*sin(p_teta[i]);
  }
  p_ksi=(sqrt(sumx*sumx+sumy*sumy))/(p_num*p_v0);
  return p_ksi;
}
    
    

void show() {
  int i;
  FILE *f1 = fopen( "f1.txt" , "wb" );
  FILE *f2 = fopen( "f2.txt" , "wb" );
  FILE *f3 = fopen( "f3.txt" , "wb" );
  FILE *f4 = fopen( "f4.txt" , "wb" );
  FILE *f5 = fopen( "f5.txt" , "wb" );
  FILE *f6 = fopen( "f6.txt" , "wb" );
  FILE *f7 = fopen( "f7.txt" , "wb" );
  FILE *f8 = fopen( "f8.txt" , "wb" );
  FILE *f9 = fopen( "f9.txt" , "wb" );
  FILE *f10 = fopen( "f10.txt" , "wb" ); 
  printf("%f\n",station());
  for (i=0; i<p_num; i++) {
    /*fprintf(stderr,"x= %f  y= %f  theta= %f\n",p_x[i],p_y[i],p_teta[i]);*/
    /*printf("%f %f\n",p_x[i],p_y[i]);*/
    
    if (i==0) {
      fprintf(f1,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f1,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f1,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f1,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f1,"\n");
    }
    if (i==1) {
      fprintf(f2,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f2,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f2,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f2,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f2,"\n");
    }
    if (i==2) {
      fprintf(f3,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f3,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f3,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f3,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f3,"\n");
    }
    if (i==3) {
      fprintf(f4,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f4,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f4,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f4,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f4,"\n");
    }
    if (i==4) {
      fprintf(f5,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f5,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f5,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f5,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f5,"\n");
    }
    if (i==5) {
      fprintf(f6,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f6,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f6,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f6,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f6,"\n");
    }
    if (i==6) {
      fprintf(f7,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f7,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f7,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f7,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f7,"\n");
    }
    if (i==7) {
      fprintf(f8,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f8,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f8,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f8,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f8,"\n");
    }
    if (i==8) {
      fprintf(f9,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f9,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f9,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f9,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f9,"\n");
    }
    if (i==9) {
      fprintf(f10,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f10,"%f %f\n",(-sin(p_teta[i]))*DELTA+p_x[i],(cos(p_teta[i]))*DELTA+p_y[i]);
      fprintf(f10,"%f %f\n",(-sin(p_teta[i]))*DELTA*(-1)+p_x[i],(cos(p_teta[i]))*DELTA*(-1)+p_y[i]);
      fprintf(f10,"%f %f\n",(cos(p_teta[i]))*4*DELTA+p_x[i],(sin(p_teta[i]))*4*DELTA+p_y[i]);
      fprintf(f10,"\n");
    }
  }
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  fclose(f5);
  fclose(f6);
  fclose(f7);
  fclose(f8); 
  fclose(f9);
  fclose(f10); 
  
}


float get_int_init() { return p_dt; }

int get_num_init() { return p_num; }

float get_side_init() { return p_l; }

float get_v0_init() { return p_v0; }

float get_r0_init() { return p_r0; }

float get_ni_init() { return p_ni; }

/*******************************************************************************
                            EOF
*******************************************************************************/
