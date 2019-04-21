/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "3par.h"

#define M_1 1       
#define M_2 1  
#define M_3 1        
#define INIT_X_1  -1      
#define INIT_Y_1  0              
#define INIT_X_2  1
#define INIT_Y_2  0       
#define INIT_X_3  0     
#define INIT_Y_3  0
#define INIT_VX_1 0.080584  
#define INIT_VY_1 0.588836        
#define INIT_VX_2 0.080584  
#define INIT_VY_2 0.588836       
#define INIT_VX_3 -0.161168     
#define INIT_VY_3 -1.177672

#define DEBUGx

/*******************************************************************************
                            Main 
*******************************************************************************/
int main(int argc , char **argv) {
  int i,j,nsteps;
  double dt;
  /*double phi0[43500][12],phi1[43500][12];*/
  if (argc!=3) {
    fprintf(stderr,"WARNING!!! You must enter the dt and nsteps repectively!!!");
    exit(0);
  }
  dt=atof(argv[1]);
  nsteps=atoi(argv[2]);
  
  int_init(dt);
  mass_init(M_1,M_2,M_3);
  pos_init(INIT_X_1,INIT_Y_1,INIT_X_2,INIT_Y_2,INIT_X_3,INIT_Y_3);
  vel_init(INIT_VX_1,INIT_VY_1,INIT_VX_2,INIT_VY_2,INIT_VX_3,INIT_VY_3);
 
  fprintf(stderr,"x1= %f,y1= %f,x2= %f,y2= %f,x3= %f,y3= %f\n", get_posx_1(), get_posy_1(),get_posx_2(),get_posy_2(),get_posx_3(),get_posy_3());
  fprintf(stderr,"vx1= %f,vy1= %f,vx2= %f,vy2= %f,vx3= %f,vy3= %f\n", get_velx_1(), get_vely_1(),get_velx_2(),get_vely_2(),get_velx_3(),get_vely_3());
  fprintf(stderr,"ax1= %f,ay1= %f,ax2= %f,ay2= %f,ax3= %f,ay3= %f\n", get_aclx_1(), get_acly_1(),get_aclx_2(),get_acly_2(),get_aclx_3(),get_acly_3());
  fprintf(stderr,"TOTAL ENERGY=%f\n", get_energy());
  FILE *f1 = fopen( "f1.txt" , "wb" );
  FILE *f2 = fopen( "f2.txt" , "wb" );
  FILE *f3 = fopen( "f3.txt" , "wb" );
  FILE *f4 = fopen( "f4.txt" , "wb" );
  FILE *f5 = fopen( "f5.txt" , "wb" );
  FILE *f6 = fopen( "f6.txt" , "wb" );
  for (i=1; i<=nsteps; i++) {
    leader();
    fprintf(f1,"%f %f\n", get_posx_1(), get_posy_1());
    
    fprintf(f2,"%f %f\n", get_posx_2(), get_posy_2());
    
    fprintf(f3,"%f %f\n", get_posx_3(), get_posy_3());
    
    printf("%f %f\n", get_posx_1(), get_posy_1());
    printf("%f %f\n", get_posx_2(), get_posy_2());
    printf("%f %f\n", get_posx_3(), get_posy_3());
    /*phi0[i][0]=get_posx_1();
    phi0[i][1]=get_posy_1();
    phi0[i][2]=get_posx_2();
    phi0[i][3]=get_posy_2();
    phi0[i][4]=get_posx_3();
    phi0[i][5]=get_posy_3();
    phi0[i][6]=get_velx_1();
    phi0[i][7]=get_vely_1();
    phi0[i][8]=get_velx_2(); 
    phi0[i][9]=get_vely_2();
    phi0[i][10]=get_velx_3();
    phi0[i][11]=get_vely_3();*/
    /*printf("#m=0,S=6\n%f %f\n", get_posx_1(), get_posy_1());
    printf("#m=0,S=3\n%f %f\n", get_posx_2(), get_posy_2());
    printf("#m=0,S=4\n%f %f\n", get_posx_3(), get_posy_3());*/
#ifdef DEBUG
    fprintf(stderr,"x1= %f,y1= %f,x2= %f,y2= %f,x3= %f,y3= %f\n", get_posx_1(), get_posy_1(),get_posx_2(),get_posy_2(),get_posx_3(),get_posy_3());
    fprintf(stderr,"vx1= %f,vy1= %f,vx2= %f,vy2= %f,vx3= %f,vy3= %f\n", get_velx_1(), get_vely_1(),get_velx_2(),get_vely_2(),get_velx_3(),get_vely_3());
#endif
    fprintf(f4,"%f %f\n", i*get_int_init(), get_energy());
    
    fprintf(f5,"%f %f\n", i*get_int_init(), get_pot_energy());
    
    fprintf(f6,"%f %f\n", i*get_int_init(), get_kin_energy());
    
    
  }
int k;
double eps=0.0;
for (k=0; k<-1; k++) {
  eps=eps+0.01;
  pos_init(INIT_X_1,INIT_Y_1,INIT_X_2+eps,INIT_Y_2,INIT_X_3,INIT_Y_3);
  vel_init(INIT_VX_1,INIT_VY_1,INIT_VX_2,INIT_VY_2,INIT_VX_3,INIT_VY_3);
  fprintf(stderr,"x1= %f,y1= %f,x2= %f,y2= %f,x3= %f,y3= %f\n", get_posx_1(), get_posy_1(),get_posx_2(),get_posy_2(),get_posx_3(),get_posy_3());
  fprintf(stderr,"vx1= %f,vy1= %f,vx2= %f,vy2= %f,vx3= %f,vy3= %f\n", get_velx_1(), get_vely_1(),get_velx_2(),get_vely_2(),get_velx_3(),get_vely_3());
  fprintf(stderr,"ax1= %f,ay1= %f,ax2= %f,ay2= %f,ax3= %f,ay3= %f\n", get_aclx_1(), get_acly_1(),get_aclx_2(),get_acly_2(),get_aclx_3(),get_acly_3());
  fprintf(stderr,"TOTAL ENERGY=%f\n", get_energy());
  
  for (i=1; i<=nsteps; i++) {
    leader();
    /*fprintf(f1,"%f %f\n", get_posx_1(), get_posy_1());
    fprintf(f2,"%f %f\n", get_posx_2(), get_posy_2());
    fprintf(f3,"%f %f\n", get_posx_3(), get_posy_3());*/
    /*printf("%f %f\n", get_posx_1(), get_posy_1());
    printf("%f %f\n", get_posx_2(), get_posy_2());
    printf("%f %f\n", get_posx_3(), get_posy_3());*/
    /*phi1[i][0]=get_posx_1();
    phi1[i][1]=get_posy_1();
    phi1[i][2]=get_posx_2();
    phi1[i][3]=get_posy_2();
    phi1[i][4]=get_posx_3();
    phi1[i][5]=get_posy_3();
    phi1[i][6]=get_velx_1();
    phi1[i][7]=get_vely_1();
    phi1[i][8]=get_velx_2(); 
    phi1[i][9]=get_vely_2();
    phi1[i][10]=get_velx_3();
    phi1[i][11]=get_vely_3();*/
    /*printf("#m=0,S=6\n%f %f\n", get_posx_1(), get_posy_1());
    printf("#m=0,S=3\n%f %f\n", get_posx_2(), get_posy_2());
    printf("#m=0,S=4\n%f %f\n", get_posx_3(), get_posy_3());*/
#ifdef DEBUG
    fprintf(stderr,"x1= %f,y1= %f,x2= %f,y2= %f,x3= %f,y3= %f\n", get_posx_1(), get_posy_1(),get_posx_2(),get_posy_2(),get_posx_3(),get_posy_3());
    fprintf(stderr,"vx1= %f,vy1= %f,vx2= %f,vy2= %f,vx3= %f,vy3= %f\n", get_velx_1(), get_vely_1(),get_velx_2(),get_vely_2(),get_velx_3(),get_vely_3());
#endif
    /*fprintf(f4,"%f %f\n", i*get_int_init(), get_energy());
    fprintf(f5,"%f %f\n", i*get_int_init(), get_pot_energy());
    fprintf(f6,"%f %f\n", i*get_int_init(), get_kin_energy());*/
    
  }
  
  
  float norm=0;
  float flag=0;
  for (i=1; i<=nsteps; i++) {
    for (j=0; j<=11; j++) {
     /* norm=norm + (phi1[i][j]-phi0[i][j])*(phi1[i][j]-phi0[i][j]);*/
    }
    
    norm=sqrt(norm);
    /*printf("%f %f\n", i*get_int_init(),log(norm/0.01));*/
   
    if (norm>flag) flag=norm;
    
      /*printf("%f %f\n", INIT_X_2+eps,log(norm));
      printf("\n");*/  
      norm=0;    
  } 
  /*printf("%f %f",INIT_X_2+eps, flag);
  printf("\n");*/ 
   
}
 
  
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  fclose(f5); 
  fclose(f6);    
  return 0;
}
/*******************************************************************************
USAGE:
MacBook-Pro:gravity user$ gcc -c 3par.c
MacBook-Pro:gravity user$ gcc run-3par.c 3par.o -o run-3par
MacBook-Pro:gravity user$ ./run-3par
graph -T png -C -m 3 f1.txt  -m 1 f2.txt  -m 2 f3.txt > output.png    to see trajectories
graph -T png -C -m 3 f4.txt  -m 1 f5.txt  -m 2 f6.txt > output.png    to see energy plot


SORT OF SOLAR SYSTEM: SUN + 2 PLANET
#define M_1 400       
#define M_2 10  
#define M_3 0.1        
#define INIT_X_1  0        
#define INIT_Y_1  0              
#define INIT_X_2  160
#define INIT_Y_2  0       
#define INIT_X_3  150          
#define INIT_Y_3  0
#define INIT_VX_1 0
#define INIT_VY_1 0    
#define INIT_VX_2 0
#define INIT_VY_2 1       
#define INIT_VX_3 0             
#define INIT_VY_3 5.3

Some funny initial states for M_1=M_2=M_3=1:(http://suki.ipb.ac.rs/3body/ )  

NAME: DRAGONFLY : M. Šuvakov and V. Dmitrašinović, Three Classes of Newtonian Three-Body Planar Periodic Orbits, Phys. Rev. Lett. 110, 114301 (2013)

DISCOVERED: 2012 

PERIOD: 21.270975

ENERGY: -1.440335 

ANGULAR MOMENTUM: ZERO 

INITIAL POSITIONS: (-1,0), (1,0), (0,0) 

INITIAL VELOCITIES: (p1,p2), (p1,p2), (-2p1,-2p2) 

p_vx1=p_vx2: 0.080584      -2*p_vx1=p_vx3=-0.161168 

p_vy1=p_vy2: 0.588836      -2*p_vy1=p_vy3=-1.177672
./run-3par 0.0001 220000 | graph -T X -m 0

NAME: FIGURE 8 C. Moore, Braids in classical gravity , Phys. Rev. Lett. 70, 3675 (1993).

DISCOVERED: 1993 

PERIOD: 6.324449

ENERGY: -1.287146 

ANGULAR MOMENTUM: ZERO 

INITIAL POSITIONS: (-1,0), (1,0), (0,0) 

INITIAL VELOCITIES: (p1,p2), (p1,p2), (-2p1,-2p2) 

p_vx1=p_vx2: 0.347111        -2*p_vx1=p_vx3=-0.694222 

p_vy1=p_vx2: 0.532728        -2*p_vy1=p_vy3=-1.065456
./run-3par 0.0001 30000 | graph -T X -m 0

NAME: BUTTERFLY IV: M. Šuvakov and V. Dmitrašinović, Three Classes of Newtonian Three-Body Planar Periodic Orbits, Phys. Rev. Lett. 110, 114301 (2013)

DISCOVERED: 2012 

PERIOD: 79.475875

ENERGY: -2.113380 

ANGULAR MOMENTUM: ZERO 

INITIAL POSITIONS: (-1,0), (1,0), (0,0) 

INITIAL VELOCITIES: (p1,p2), (p1,p2), (-2p1,-2p2) 

p_vx1=p_vx2: 0.350112        -2*p_vx1=p_vx3=-0.700224

p_vy1=p_vx2: 0.079339        -2*p_vy1=p_vy3= -0.158678
./run-3par 0.000001 12000000 | graph -T X -m 0 

NAME: BUTTERFLY III:  M. Šuvakov and V. Dmitrašinović, Three Classes of Newtonian Three-Body Planar Periodic Orbits, Phys. Rev. Lett. 110, 114301 (2013) 

DISCOVERED: 2012  

PERIOD: 13.865763

ENERGY: -1.846772 

ANGULAR MOMENTUM: ZERO 

INITIAL POSITIONS: (-1,0), (1,0), (0,0) 

INITIAL VELOCITIES: (p1,p2), (p1,p2), (-2p1,-2p2) 

p_vx1=p_vx2: 0.405916         -2*p_vx1=p_vx3=-0.811832

p_vy1=p_vx2: 0.230163         -2*p_vy1=p_vy3=-0.460326
./run-3par 0.0001 153000 | graph -T X -m 0

NAME: GOGGLES: M. Šuvakov and V. Dmitrašinović, Three Classes of Newtonian Three-Body Planar Periodic Orbits, Phys. Rev. Lett. 110, 114301 (2013)

DISCOVERED: 2012  

PERIOD: 10.466818

ENERGY: -2.430116 

ANGULAR MOMENTUM: ZERO 

INITIAL POSITIONS: (-1,0), (1,0), (0,0) 

INITIAL VELOCITIES: (p1,p2), (p1,p2), (-2p1,-2p2) 

p_vx1=p_vx2: 0.083300          -2*p_vx1=p_vx3=-0.166600 

p_vy1=p_vy2: 0.127889          -2*p_vy1=p_vy3=-0.255778
./run-3par 0.00001 2000000 | graph -T X -m 0

Broucke A16 R. Broucke, On relative periodic solutions of the planar general three-body problem, Celest. Mech. 12, 439 (1975).
DISCOVERED: 1975 

DISCOVERED: 1975

FREE GROUP ELEMENT: a 

PERIOD: 90.871196

ENERGY: -0.468864 

ANGULAR MOMENTUM: 1.093094

INITIAL POSITIONS: 

(-0.7283341038,0.0000000000),
(2.8989177778,0.0000000000),
(-2.1705836741,0.0000000000) 

INITIAL VELOCITIES: 

(0.0000000000,0.8475982451),
(0.0000000000,-0.0255162097),
(0.0000000000,-0.8220820354)
./run-3par 0.001 91000 | graph -T X -m 0

NAME: Broucke R13 R. Broucke, On relative periodic solutions of the planar general three-body problem, Celest. Mech. 12, 439 (1975).

DISCOVERED: 1975 

FREE GROUP ELEMENT: a 

PERIOD: 22.764421

ENERGY: -1.572851 

ANGULAR MOMENTUM: 1.842111

INITIAL POSITIONS: 

(0.9017748598,0.0000000000),
(-0.6823433302,0.0000000000),
(-0.2194315296,0.0000000000) 

INITIAL VELOCITIES: 

(0.0000000000,0.9526089117),
(0.0000000000,-1.6721104565),
(0.0000000000,0.7195015448)
./run-3par 0.001 13000 | graph -T X -m 0

NAME: Broucke R 1 R. Broucke, On relative periodic solutions of the planar general three-body problem, Celest. Mech. 12, 439 (1975).

DISCOVERED: 1975  

PERIOD: 5.226525

ENERGY: -1.464959 

ANGULAR MOMENTUM: 1.606147

INITIAL POSITIONS: 

(0.8083106230,0.0000000000),
(-0.4954148566,0.0000000000),
(-0.3128957664,0.0000000000) 

INITIAL VELOCITIES: 

(0.0000000000,0.9901979166),
(0.0000000000,-2.7171431768),
(0.0000000000,1.7269452602) 
./run-3par 0.0001 53000 | graph -T X -m 0

NAME: Henon 41 M. Henon, A family of periodic solutions of the planar three-body problem, and their stability, Celest. Mech. 13, 267 (1976).

DISCOVERED: 1975  

PERIOD: 2.204722

ENERGY: -1.040042 

ANGULAR MOMENTUM: 1.560063

INITIAL POSITIONS: 

(0.8008933013,0.0000000000),
(1.4695233462,0.0000000000),
(-2.2704166475,0.0000000000) 

INITIAL VELOCITIES: 

(0.0000000000,1.1815913872),
(0.0000000000,-0.5532095521),
(0.0000000000,-0.6283818352) 
./run-3par 0.001 22800 | graph -T X -m 0

NAME: Henon 31 M. Henon, A family of periodic solutions of the planar three-body problem, and their stability, Celest. Mech. 13, 267 (1976).

DISCOVERED: 1975 

PERIOD: 3.538330

ENERGY: -1.040042 

ANGULAR MOMENTUM: 0.748830

INITIAL POSITIONS: 

(-0.1184831386,0.0000000000),
(1.1644627554,0.0000000000),
(-1.0459796167,0.0000000000) 

INITIAL VELOCITIES: 

(0.0000000000,1.2002882491),
(0.0000000000,-0.1648687837),
(0.0000000000,-1.0354194654) 
./run-3par 0.001 4500 | graph -T X -m 0








*******************************************************************************/
