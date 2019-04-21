/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define MAXITER 1000 
#define MAXNORM 1e6

/*******************************************************************************
            int map(double cr, double ci, double zr, double zi)
performs at most MAXITER update steps according to the above evolution starting 
      from z = zr + i * zi and with given parameter c = cr + i * ci.
*******************************************************************************/
int map(double cr, double ci, double zr, double zi) {
  int i,n_itir,rtrn,flag=0;
  double tmpr,tmpi,normz;
  for (i=1; i<=MAXITER; i++) {
    tmpr=zr*zr-zi*zi+cr;
    tmpi=2*zr*zi+ci;
    zr=tmpr;
    zi=tmpi;
    normz=zr*zr+zi*zi;
    /*printf("zr= %f,zi= %f\n",zr,zi);*/
    if (normz>MAXNORM) {
      n_itir=i;
      i=MAXITER+1;
      flag=1;
    }
  }
  if (flag) rtrn=n_itir;
  else rtrn=0;
  return rtrn;  
}    


/*******************************************************************************
                            Main 
*******************************************************************************/
int main(int argc , char **argv) {
  int i=0,j=0,s=0;
  float log_cr=-2.0,log_ci=-1.0,log_zi=0,log_zr=0;
  int log_n_itir;
  float step1,step2;
  step1=3.0/400.0;
  step2=2.0/400.0;
  FILE *gh = fopen( "file.txt" , "wb" );           /* opening file.txt to save points */
  do {                                 /*double loop to sample the values of the parameter c in the complex plane*/
    log_cr=-2.0;
    i=0;
    do {                                           
      log_n_itir= map(log_cr,log_ci,log_zr,log_zi);
      if (log_n_itir==0) { 
        printf("%f %f\n", log_cr, log_ci);
        fprintf(gh,"%f %f\n",log_cr, log_ci); 
      }
      /*s++;*/
      i++; 
      log_cr=log_cr+step1;
    } while (i<400);
    log_ci=log_ci+step2;;
    j++;
  } while (j<400);
  /*printf("%d\n",s);*/
  fclose(gh);
  return 0;
}
/*******************************************************************************
                            EOF
 gcc log.c -o log
./log | graph -T X -m 0

graph -T png -m 0 file.txt > plot.png

1)log_cr=-2,log_ci=-1; 
step1=3.0/400.0; step2=2.0/400.0;
2)log_cr=-0.4,log_ci=-0.9; 
step1=0.5/400.0; step2=0.5/400.0;
3)log_cr=-0.2,log_ci=-0.7
step1=0.2/400.0; step2=0.2/400.0;
4)log_cr=-0.2,log_ci=-0.65
step1=0.1/400.0; step2=0.1/400.0;

antenna
int main(int argc , char **argv) {
  int i=0,j=0,s=0;
  float log_cr=-1.78,log_ci=-0.1,log_zi=0,log_zr=0;
  int log_n_itir;
  float step1,step2;
  step1=0.03/800.0;
  step2=0.2/800.0;
  FILE *gh = fopen( "file.txt" , "wb" );          
  do {                                 
    log_cr=-1.78;
    i=0;
    do {                                           
      log_n_itir= map(log_cr,log_ci,log_zr,log_zi);
      if (log_n_itir==0) { 
        printf("%f %f\n", log_cr, log_ci);
        fprintf(gh,"%f %f\n",log_cr, log_ci); 
      }
      
      i++; 
      log_cr=log_cr+step1;
    } while (i<1200);
    log_ci=log_ci+step2;;
    j++;
  } while (j<1200);
 
  fclose(gh);
  return 0;
}

*******************************************************************************/
