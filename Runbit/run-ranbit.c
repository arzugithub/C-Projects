/*******************************************************************************
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "ranbit.h"
static char flag;
static int r,s,state;
static int init=1;
static char x[32];

/*******************************************************************************
                            Main 
*******************************************************************************/
int main(int argc , char **argv) {
  if (argc<=2) printf("You must enter at least two numbers for r and s\n");
  else{
  flag=0;
  int j,v,lag1,lag2;
  
  lag1=atoi(argv[1]);             /* lag1 is the value of r */
  lag2=atoi(argv[2]);             /* lag2 is the value of s */

  if ((lag1>=lag2) | (lag2>32)) 
    printf("The numbers you have entered are not suitable!!! r must be less than s!!!\n");
  else {
    for (j=0; j<s; j++) 
      x[j]=0;     /* set the values of the array equal to zero */
    ranbit1_init(lag1,lag2);        /* initializing the values of r and s with lag1 and lag2 respectively */
    printf("r= %d, s= %d\n",lag1,lag2);
    j=0;
    int jmax; 
    if (argv[3]==0) { 
      jmax=3;
    }
    else {
      jmax=atoi(argv[3]);
    } 
    do {                                      /* computing the period + 1 and printing jmax first random numbers */         
      v=ranbit1();
      if (j<jmax) {
        printf("random number: %d  ",v);
        ranbit1_show();
      } 
      j++; } while (v!=init);
    printf("period for r= %d, s= %d, seed= %d is %d \n\n",lag1,lag2,init,j);


    /*j=0;
    int jmax; 
    if (argv[3]==0) { 
      jmax=0;
    }
    else {
      jmax=atoi(argv[3]);
    } 
    int l,m,p;

  
    for (l=2; l<=lag2; l++) {*/   
      /*do { */                                         /* To run this part: ./ranbit 1 s */                                      
                                                    /* computing the period  and printing periods for different values of r & s */         
       /* v=ranbit1();
        if (j<jmax) {*/
          /*printf("random number: %d  ",v);*/
         /* ranbit1_show();*/
        /*} 
        j++; 
      } while (v!=1);
  
      printf("period  for r= %d, s= %d, is %d \n\n",l-1,lag2,j);
      for (m=0; m<32; m++) x[m]=0;
      ranbit1_init(l,lag2);
      j=0;
    }*/

  }
  }
  return 0;
}
/*******************************************************************************
                            EOF
Results:
1. For default r=29 & s=23:
MacBook-Pro:w3 user$ ./run-ranbit 9 23 7
s= 23, r= 9
random number: 262657  Binary state = 00001000000001000000001

random number: 4464657  Binary state = 10001000010000000010001

random number: 140033  Binary state = 00000100010001100000001

random number: 6304009  Binary state = 11000000011000100001001

random number: 2433673  Binary state = 01001010010001010001001

random number: 1382429  Binary state = 00101010001100000011101

random number: 100937  Binary state = 00000011000101001001001

period  for r= 9, s= 23, is 8388607 

2. Perids for different values of r and s: 
Some funny relations for seed=1 : Perior(r,s) = period(s-r,s) 
                                  If m is a positive ineger period(r,s)=period(m*r,m*s)
                                  If n and m are positive integers and a is a prime number: period(r=a^m,s=a^n)=a^(2*n-2*m) - a + 1  
                                                                

s= 2:
period + 1 for r= 1, s= 2, is 4

s= 3:
period + 1 for r= 1, s= 3, is 8

period + 1 for r= 2, s= 3, is 8

s= 4:
period + 1 for r= 1, s= 4, is 16

period + 1 for r= 2, s= 4, is 4

period + 1 for r= 3, s= 4, is 16

s= 5:
period + 1 for r= 1, s= 5, is 22

period + 1 for r= 2, s= 5, is 32 

period + 1 for r= 3, s= 5, is 32 

period + 1 for r= 4, s= 5, is 22 

s= 6:
period + 1 for r= 1, s= 6, is 22 

period + 1 for r= 2, s= 6, is 8

period + 1 for r= 3, s= 6, is 4 

period + 1 for r= 4, s= 6, is 8 

period + 1 for r= 5, s= 6, is 22

s= 7:
period + 1 for r= 1, s= 7, is 128 

period + 1 for r= 2, s= 7, is 94

period + 1 for r= 3, s= 7, is 128 

period + 1 for r= 4, s= 7, is 128 

period + 1 for r= 5, s= 7, is 94

period + 1 for r= 6, s= 7, is 128 

s= 8:
period + 1 for r= 1, s= 8, is 64

period + 1 for r= 2, s= 8, is 16 

period + 1 for r= 3, s= 8, is 218 

period + 1 for r= 4, s= 8, is 4

period + 1 for r= 5, s= 8, is 218 

period + 1 for r= 6, s= 8, is 16

period + 1 for r= 7, s= 8, is 64 

s= 9:
period + 1 for r= 1, s= 9, is 74 

period + 1 for r= 2, s= 9, is 156 

period + 1 for r= 3, s= 9, is 8

period + 1 for r= 4, s= 9, is 512 

period + 1 for r= 5, s= 9, is 512 

period + 1 for r= 6, s= 9, is 8

period + 1 for r= 7, s= 9, is 156 

period + 1 for r= 8, s= 9, is 74 

s= 10:
period + 1 for r= 1, s= 10, is 890 

period + 1 for r= 2, s= 10, is 22

period + 1 for r= 3, s= 10, is 1024 

period + 1 for r= 4, s= 10, is 32

period + 1 for r= 5, s= 10, is 4

period + 1 for r= 6, s= 10, is 32 

period + 1 for r= 7, s= 10, is 1024 

period + 1 for r= 8, s= 10, is 22 

period + 1 for r= 9, s= 10, is 890 

s= 11:
period + 1 for r= 1, s= 11, is 1534 

period + 1 for r= 2, s= 11, is 2048 

period + 1 for r= 3, s= 11, is 1954 

period + 1 for r= 4, s= 11, is 1534 

period + 1 for r= 5, s= 11, is 596

period + 1 for r= 6, s= 11, is 596 

period + 1 for r= 7, s= 11, is 1534 

period + 1 for r= 8, s= 11, is 1954 

period + 1 for r= 9, s= 11, is 2048 

period + 1 for r= 10, s= 11, is 1534 

s= 12:
period + 1 for r= 1, s= 12, is 1086

period + 1 for r= 2, s= 12, is 22

period + 1 for r= 3, s= 12, is 16 

period + 1 for r= 4, s= 12, is 8 

period + 1 for r= 5, s= 12, is 274 

period + 1 for r= 6, s= 12, is 4

period + 1 for r= 7, s= 12, is 274 

period + 1 for r= 8, s= 12, is 8

period + 1 for r= 9, s= 12, is 16 

period + 1 for r= 10, s= 12, is 22 

period + 1 for r= 11, s= 12, is 1086 

s= 13:
period + 1 for r= 1, s= 13, is 7906

period + 1 for r= 2, s= 13, is 1786 

period + 1 for r= 3, s= 13, is 8002 

period + 1 for r= 4, s= 13, is 7162 

period + 1 for r= 5, s= 13, is 6142 

period + 1 for r= 6, s= 13, is 7666 

period + 1 for r= 7, s= 13, is 7666 

period + 1 for r= 8, s= 13, is 6142 

period + 1 for r= 9, s= 13, is 7162 

period + 1 for r= 10, s= 13, is 8002 

period + 1 for r= 11, s= 13, is 1786 

period + 1 for r= 12, s= 13, is 7906 

s= 14:
period + 1 for r= 1, s= 14, is 11812 

period + 1 for r= 2, s= 14, is 128

period + 1 for r= 3, s= 14, is 5116 

period + 1 for r= 4, s= 14, is 94

period + 1 for r= 5, s= 14, is 5462 

period + 1 for r= 6, s= 14, is 128

period + 1 for r= 7, s= 14, is 4

period + 1 for r= 8, s= 14, is 128 

period + 1 for r= 9, s= 14, is 5462 

period + 1 for r= 10, s= 14, is 94

period + 1 for r= 11, s= 14, is 5116 

period + 1 for r= 12, s= 14, is 128

period + 1 for r= 13, s= 14, is 11812 

s= 15:
period + 1 for r= 1, s= 15, is 32768

period + 1 for r= 2, s= 15, is 1534

period + 1 for r= 3, s= 15, is 22

period + 1 for r= 4, s= 15, is 32768 

period + 1 for r= 5, s= 15, is 8

period + 1 for r= 6, s= 15, is 32 

period + 1 for r= 7, s= 15, is 32768 

period + 1 for r= 8, s= 15, is 32768 

period + 1 for r= 9, s= 15, is 32

period + 1 for r= 10, s= 15, is 8 

period + 1 for r= 11, s= 15, is 32768 

period + 1 for r= 12, s= 15, is 22

period + 1 for r= 13, s= 15, is 1534 

period + 1 for r= 14, s= 15, is 32768 

s= 16:
period + 1 for r= 1, s= 16, is 256

period + 1 for r= 2, s= 16, is 64 

period + 1 for r= 3, s= 16, is 57338 

period + 1 for r= 4, s= 16, is 16

period + 1 for r= 5, s= 16, is 16384 

period + 1 for r= 6, s= 16, is 218

period + 1 for r= 7, s= 16, is 63458 

period + 1 for r= 8, s= 16, is 4

period + 1 for r= 9, s= 16, is 63458 

period + 1 for r= 10, s= 16, is 218 

period + 1 for r= 11, s= 16, is 16384 

period + 1 for r= 12, s= 16, is 16

period + 1 for r= 13, s= 16, is 57338 

period + 1 for r= 14, s= 16, is 64 

period + 1 for r= 15, s= 16, is 256 

s= 17:
period + 1 for r= 1, s= 17, is 274

period + 1 for r= 2, s= 17, is 114682 

period + 1 for r= 3, s= 17, is 131072 

period + 1 for r= 4, s= 17, is 1024

period + 1 for r= 5, s= 17, is 131072 

period + 1 for r= 6, s= 17, is 131072 

period + 1 for r= 7, s= 17, is 4600

period + 1 for r= 8, s= 17, is 35806 

period + 1 for r= 9, s= 17, is 35806 

period + 1 for r= 10, s= 17, is 4600 

period + 1 for r= 11, s= 17, is 131072 

period + 1 for r= 12, s= 17, is 131072 

period + 1 for r= 13, s= 17, is 1024

period + 1 for r= 14, s= 17, is 131072 

period + 1 for r= 15, s= 17, is 114682 

period + 1 for r= 16, s= 17, is 274

s= 18:
period + 1 for r= 1, s= 18, is 253922 

period + 1 for r= 2, s= 18, is 74

period + 1 for r= 3, s= 18, is 22 

period + 1 for r= 4, s= 18, is 156 

period + 1 for r= 5, s= 18, is 32768 

period + 1 for r= 6, s= 18, is 8

period + 1 for r= 7, s= 18, is 29128 

period + 1 for r= 8, s= 18, is 512

period + 1 for r= 9, s= 18, is 4

period + 1 for r= 10, s= 18, is 512 

period + 1 for r= 11, s= 18, is 29128 

period + 1 for r= 12, s= 18, is 8

period + 1 for r= 13, s= 18, is 32768 

period + 1 for r= 14, s= 18, is 156

period + 1 for r= 15, s= 18, is 22

period + 1 for r= 16, s= 18, is 74 

period + 1 for r= 17, s= 18, is 253922

s= 19:
period + 1 for r= 1, s= 19, is 413386

period + 1 for r= 2, s= 19, is 129922 

period + 1 for r= 3, s= 19, is 491506 

period + 1 for r= 4, s= 19, is 91750

period + 1 for r= 5, s= 19, is 393214 

period + 1 for r= 6, s= 19, is 520066 

period + 1 for r= 7, s= 19, is 520066 

period + 1 for r= 8, s= 19, is 47524

period + 1 for r= 9, s= 19, is 174252 

period + 1 for r= 10, s= 19, is 174252 

period + 1 for r= 11, s= 19, is 47524

period + 1 for r= 12, s= 19, is 520066 

period + 1 for r= 13, s= 19, is 520066 

period + 1 for r= 14, s= 19, is 393214 

period + 1 for r= 15, s= 19, is 91750

period + 1 for r= 16, s= 19, is 491506 

period + 1 for r= 17, s= 19, is 129922 

period + 1 for r= 18, s= 19, is 413386

s= 20:
period + 1 for r= 1, s= 20, is 761764

period + 1 for r= 2, s= 20, is 890

period + 1 for r= 3, s= 20, is 209716 

period + 1 for r= 4, s= 20, is 22

period + 1 for r= 5, s= 20, is 16 

period + 1 for r= 6, s= 20, is 1024 

period + 1 for r= 7, s= 20, is 779908 

period + 1 for r= 8, s= 20, is 32

period + 1 for r= 9, s= 20, is 26062 

period + 1 for r= 10, s= 20, is 4

period + 1 for r= 11, s= 20, is 26062 

period + 1 for r= 12, s= 20, is 32

period + 1 for r= 13, s= 20, is 779908 

period + 1 for r= 14, s= 20, is 1024

period + 1 for r= 15, s= 20, is 16

period + 1 for r= 16, s= 20, is 22 

period + 1 for r= 17, s= 20, is 209716 

period + 1 for r= 18, s= 20, is 890

period + 1 for r= 19, s= 20, is 761764 

s= 21:
period + 1 for r= 1, s= 21, is 5462

period + 1 for r= 2, s= 21, is 299594 

period + 1 for r= 3, s= 21, is 128

period + 1 for r= 4, s= 21, is 1354 

period + 1 for r= 5, s= 21, is 5462 

period + 1 for r= 6, s= 21, is 94

period + 1 for r= 7, s= 21, is 8

period + 1 for r= 8, s= 21, is 655356

period + 1 for r= 9, s= 21, is 128

period + 1 for r= 10, s= 21, is 696236

period + 1 for r= 11, s= 21, is 696236 

period + 1 for r= 12, s= 21, is 128

period + 1 for r= 13, s= 21, is 655356 

period + 1 for r= 14, s= 21, is 8

period + 1 for r= 15, s= 21, is 94 

period + 1 for r= 16, s= 21, is 5462 

period + 1 for r= 17, s= 21, is 135440 

period + 1 for r= 18, s= 21, is 128

period + 1 for r= 19, s= 21, is 299594 

period + 1 for r= 20, s= 21, is 5462

s= 22:
period + 1 for r= 1, s= 22, is 4194304 

period + 1 for r= 2, s= 22, is 1534

period + 1 for r= 3, s= 22, is 3670010 

period + 1 for r= 4, s= 22, is 2048

period + 1 for r= 5, s= 22, is 2752492 

period + 1 for r= 6, s= 22, is 1954

period + 1 for r= 7, s= 22, is 4063202 

period + 1 for r= 8, s= 22, is 1534

period + 1 for r= 9, s= 22, is 3899536 

period + 1 for r= 10, s= 22, is 596

period + 1 for r= 11, s= 22, is 4

period + 1 for r= 12, s= 22, is 596 

period + 1 for r= 13, s= 22, is 3899536

period + 1 for r= 14, s= 22, is 1534

period + 1 for r= 15, s= 22, is 4063202 

period + 1 for r= 16, s= 22, is 1954

period + 1 for r= 17, s= 22, is 2752492 

period + 1 for r= 18, s= 22, is 2048

period + 1 for r= 19, s= 22, is 3670010 

period + 1 for r= 20, s= 22, is 1534

period + 1 for r= 21, s= 22, is 4194304 

s= 23
period + 1 for r= 1, s= 23, is 2088706

period + 1 for r= 2, s= 23, is 7864306 

period + 1 for r= 3, s= 23, is 32768

period + 1 for r= 4, s= 23, is 2088706 

period + 1 for r= 5, s= 23, is 8388608 

period + 1 for r= 6, s= 23, is 458746

period + 1 for r= 7, s= 23, is 91048

period + 1 for r= 8, s= 23, is 2728342 

period + 1 for r= 9, s= 23, is 8388608 

period + 1 for r= 10, s= 23, is 87382

period + 1 for r= 11, s= 23, is 126946 

period + 1 for r= 12, s= 23, is 126946 

period + 1 for r= 13, s= 23, is 87382

period + 1 for r= 14, s= 23, is 8388608 

period + 1 for r= 15, s= 23, is 2728342 

period + 1 for r= 16, s= 23, is 91048

period + 1 for r= 17, s= 23, is 458746 

period + 1 for r= 18, s= 23, is 8388608 

period + 1 for r= 19, s= 23, is 2088706 

period + 1 for r= 20, s= 23, is 32768

period + 1 for r= 21, s= 23, is 7864306 

period + 1 for r= 22, s= 23, is 2088706 

s= 24:
period + 1 for r= 1, s= 24, is 2097152

period + 1 for r= 2, s= 24, is 1086

period + 1 for r= 3, s= 24, is 64

period + 1 for r= 4, s= 24, is 22 

period + 1 for r= 5, s= 24, is 16766978

period + 1 for r= 6, s= 24, is 16

period + 1 for r= 7, s= 24, is 349526 

period + 1 for r= 8, s= 24, is 8

period + 1 for r= 9, s= 24, is 218 

period + 1 for r= 10, s= 24, is 274 

period + 1 for r= 11, s= 24, is 1862202 

period + 1 for r= 12, s= 24, is 4

period + 1 for r= 13, s= 24, is 1862202 

period + 1 for r= 14, s= 24, is 274

period + 1 for r= 15, s= 24, is 218 

period + 1 for r= 16, s= 24, is 8

period + 1 for r= 17, s= 24, is 349526 

period + 1 for r= 18, s= 24, is 16

period + 1 for r= 19, s= 24, is 16766978 

period + 1 for r= 20, s= 24, is 22

period + 1 for r= 21, s= 24, is 64 

period + 1 for r= 22, s= 24, is 1086 

period + 1 for r= 23, s= 24, is 2097152 

s= 25:
period + 1 for r= 1, s= 25, is 2192338 

period + 1 for r= 2, s= 25, is 25165822 

period + 1 for r= 3, s= 25, is 33554432 

period + 1 for r= 4, s= 25, is 431614

period + 1 for r= 5, s= 25, is 22

period + 1 for r= 6, s= 25, is 4185602 

period + 1 for r= 7, s= 25, is 33554432 

period + 1 for r= 8, s= 25, is 1664590

period + 1 for r= 9, s= 25, is 32247968 

period + 1 for r= 10, s= 25, is 32

period + 1 for r= 11, s= 25, is 8257474 

period + 1 for r= 12, s= 25, is 4161410 

period + 1 for r= 13, s= 25, is 4161410 

period + 1 for r= 14, s= 25, is 8257474 

period + 1 for r= 15, s= 25, is 32

period + 1 for r= 16, s= 25, is 32247968 

period + 1 for r= 17, s= 25, is 1664590

period + 1 for r= 18, s= 25, is 33554432 

period + 1 for r= 19, s= 25, is 4185602

period + 1 for r= 20, s= 25, is 22

period + 1 for r= 21, s= 25, is 431614 

period + 1 for r= 22, s= 25, is 33554432 

period + 1 for r= 23, s= 25, is 25165822 

period + 1 for r= 24, s= 25, is 2192338

s= 26:
period + 1 for r= 1, s= 25, is 2192337 

period + 1 for r= 2, s= 25, is 25165821 

period + 1 for r= 3, s= 25, is 33554431 

period + 1 for r= 4, s= 25, is 431613 

period + 1 for r= 5, s= 25, is 21 

period + 1 for r= 6, s= 25, is 4185601 

period + 1 for r= 7, s= 25, is 33554431 

period + 1 for r= 8, s= 25, is 1664589 

period + 1 for r= 9, s= 25, is 32247967 

period + 1 for r= 10, s= 25, is 31 

period + 1 for r= 11, s= 25, is 8257473 

period + 1 for r= 12, s= 25, is 4161409 

period + 1 for r= 13, s= 25, is 4161409 

period + 1 for r= 14, s= 25, is 8257473 

period + 1 for r= 15, s= 25, is 31 

period + 1 for r= 16, s= 25, is 32247967 

period + 1 for r= 17, s= 25, is 1664589 

period + 1 for r= 18, s= 25, is 33554431 

period + 1 for r= 19, s= 25, is 4185601 

period + 1 for r= 20, s= 25, is 21 

period + 1 for r= 21, s= 25, is 431613 

period + 1 for r= 22, s= 25, is 33554431 

period + 1 for r= 23, s= 25, is 25165821 

period + 1 for r= 24, s= 25, is 2192337 

s= 27:
period + 1 for r= 1, s= 27, is 41943035 

period + 1 for r= 2, s= 27, is 152915 

period + 1 for r= 3, s= 27, is 73 

period + 1 for r= 4, s= 27, is 1864135 

period + 1 for r= 5, s= 27, is 8877935 

period + 1 for r= 6, s= 27, is 155 

period + 1 for r= 7, s= 27, is 44564395 

period + 1 for r= 8, s= 27, is 44564395 

period + 1 for r= 9, s= 27, is 7 

period + 1 for r= 10, s= 27, is 43341131 

period + 1 for r= 11, s= 27, is 36408995 

period + 1 for r= 12, s= 27, is 511 

period + 1 for r= 13, s= 27, is 43341131 

period + 1 for r= 14, s= 27, is 43341131 

period + 1 for r= 15, s= 27, is 511 

period + 1 for r= 16, s= 27, is 36408995 

period + 1 for r= 17, s= 27, is 43341131 

period + 1 for r= 18, s= 27, is 7 

period + 1 for r= 19, s= 27, is 44564395 

period + 1 for r= 20, s= 27, is 44564395 

period + 1 for r= 21, s= 27, is 155 

period + 1 for r= 22, s= 27, is 8877935 

period + 1 for r= 23, s= 27, is 1864135 

period + 1 for r= 24, s= 27, is 73 

period + 1 for r= 25, s= 27, is 152915 

period + 1 for r= 26, s= 27, is 41943035 

s= 28:
period + 1 for r= 1, s= 28, is 17895697 

period + 1 for r= 2, s= 28, is 11811 

period + 1 for r= 3, s= 28, is 268435455 

period + 1 for r= 4, s= 28, is 127 

period + 1 for r= 5, s= 28, is 3011805 

period + 1 for r= 6, s= 28, is 5115 

period + 1 for r= 7, s= 28, is 15 

period + 1 for r= 8, s= 28, is 93 

period + 1 for r= 9, s= 28, is 268435455 

period + 1 for r= 10, s= 28, is 5461 

period + 1 for r= 11, s= 28, is 199753347 

period + 1 for r= 12, s= 28, is 127 

period + 1 for r= 13, s= 28, is 268435455 

period + 1 for r= 14, s= 28, is 3 

period + 1 for r= 15, s= 28, is 268435455 

period + 1 for r= 16, s= 28, is 127 

period + 1 for r= 17, s= 28, is 199753347 

period + 1 for r= 18, s= 28, is 5461 

period + 1 for r= 19, s= 28, is 268435455 

period + 1 for r= 20, s= 28, is 93 

period + 1 for r= 21, s= 28, is 15 

period + 1 for r= 22, s= 28, is 5115 

period + 1 for r= 23, s= 28, is 3011805 

period + 1 for r= 24, s= 28, is 127 

period + 1 for r= 25, s= 28, is 268435455 

period + 1 for r= 26, s= 28, is 11811 

period + 1 for r= 27, s= 28, is 17895697 

s= 29:
period + 1 for r= 1, s= 29, is 402653181 

period + 1 for r= 2, s= 29, is 536870911 

period + 1 for r= 3, s= 29, is 426636105 

period + 1 for r= 4, s= 29, is 398532477 

period + 1 for r= 5, s= 29, is 3088995 

period + 1 for r= 6, s= 29, is 536797185 

period + 1 for r= 7, s= 29, is 389260893 

period + 1 for r= 8, s= 29, is 178781867 

period + 1 for r= 9, s= 29, is 534773505 

period + 1 for r= 10, s= 29, is 349566357 

period + 1 for r= 11, s= 29, is 503316465 

period + 1 for r= 12, s= 29, is 469762041 

period + 1 for r= 13, s= 29, is 402653181 

period + 1 for r= 14, s= 29, is 178607275 

period + 1 for r= 15, s= 29, is 178607275 

period + 1 for r= 16, s= 29, is 402653181 

period + 1 for r= 17, s= 29, is 469762041 

period + 1 for r= 18, s= 29, is 503316465 

period + 1 for r= 19, s= 29, is 349566357 

period + 1 for r= 20, s= 29, is 534773505 

period + 1 for r= 21, s= 29, is 178781867 

period + 1 for r= 22, s= 29, is 389260893 

period + 1 for r= 23, s= 29, is 536797185 

period + 1 for r= 24, s= 29, is 3088995 

period + 1 for r= 25, s= 29, is 398532477 

period + 1 for r= 26, s= 29, is 426636105 

period + 1 for r= 27, s= 29, is 536870911 

period + 1 for r= 28, s= 29, is 402653181 

s= 30:
period + 1 for r= 1, s= 30, is 10845877 

period + 1 for r= 2, s= 30, is 32767 

period + 1 for r= 3, s= 30, is 889 

period + 1 for r= 4, s= 30, is 1533 

period + 1 for r= 5, s= 30, is 21 

period + 1 for r= 6, s= 30, is 21 

period + 1 for r= 7, s= 30, is 1073215489 

period + 1 for r= 8, s= 30, is 32767 

period + 1 for r= 9, s= 30, is 1023 

period + 1 for r= 10, s= 30, is 7 

period + 1 for r= 11, s= 30, is 33554431 

period + 1 for r= 12, s= 30, is 31 

period + 1 for r= 13, s= 30, is 303387917 

period + 1 for r= 14, s= 30, is 32767 

period + 1 for r= 15, s= 30, is 3 

period + 1 for r= 16, s= 30, is 32767 

period + 1 for r= 17, s= 30, is 303387917 

period + 1 for r= 18, s= 30, is 31 

period + 1 for r= 19, s= 30, is 33554431 

period + 1 for r= 20, s= 30, is 7 

period + 1 for r= 21, s= 30, is 1023 

period + 1 for r= 22, s= 30, is 32767 

period + 1 for r= 23, s= 30, is 1073215489 

period + 1 for r= 24, s= 30, is 21 

period + 1 for r= 25, s= 30, is 21 

period + 1 for r= 26, s= 30, is 1533 

period + 1 for r= 27, s= 30, is 889 

period + 1 for r= 28, s= 30, is 32767 

period + 1 for r= 29, s= 30, is 10845877

s= 31:
period + 1 for r= 1, s= 31, is 2097151 

period + 1 for r= 2, s= 31, is 22362795 

period + 1 for r= 3, s= 31, is 2147483647 

period + 1 for r= 4, s= 31, is 670965765 

period + 1 for r= 5, s= 31, is 107359437 

period + 1 for r= 6, s= 31, is 2147483647 

period + 1 for r= 7, s= 31, is 2147483647 

period + 1 for r= 8, s= 31, is 469762041 

period + 1 for r= 9, s= 31, is 805035 

period + 1 for r= 10, s= 31, is 22975755 

period + 1 for r= 11, s= 31, is 536606721 

period + 1 for r= 12, s= 31, is 94371795 

period + 1 for r= 13, s= 31, is 2147483647 

period + 1 for r= 14, s= 31, is 17316831 

period + 1 for r= 15, s= 31, is 2097151 

period + 1 for r= 16, s= 31, is 2097151 

period + 1 for r= 17, s= 31, is 17316831 

period + 1 for r= 18, s= 31, is 2147483647 

period + 1 for r= 19, s= 31, is 94371795 

period + 1 for r= 20, s= 31, is 536606721 

period + 1 for r= 21, s= 31, is 22975755 

period + 1 for r= 22, s= 31, is 805035 

period + 1 for r= 23, s= 31, is 469762041 

period + 1 for r= 24, s= 31, is 2147483647 

period + 1 for r= 25, s= 31, is 2147483647 

period + 1 for r= 26, s= 31, is 107359437 

period + 1 for r= 27, s= 31, is 670965765 

period + 1 for r= 28, s= 31, is 2147483647 

period + 1 for r= 29, s= 31, is 22362795 

period + 1 for r= 30, s= 31, is 2097151 

s= 32:
period + 1 for r= 1, s= 32, is 1023 

period + 1 for r= 2, s= 32, is 255

period + 1 for r= 3, s= 32, is 1409286123 

period + 1 for r= 4, s= 32, is 63 

period + 1 for r= 5, s= 32, is inf.

period + 1 for r= 6, s= 32, is 57337

period + 1 for r= 7, s= 32, is 97612893 

period + 1 for r= 8, s= 32, is 15

period + 1 for r= 9, s= 32, is 268435455 

period + 1 for r= 10, s= 32, is 16383 

period + 1 for r= 11, s= 32, is 1431562923 

period + 1 for r= 12, s= 32, is 217 

period + 1 for r= 13, s= 32, is 910163751

period + 1 for r= 14, s= 32, is 63457 

period + 1 for r= 15, s= 32, is inf.

period + 1 for r= 16, s= 32, is 3

period + 1 for r= 17, s= 32, is inf.

period + 1 for r= 18, s= 32, is 63457 

period + 1 for r= 19, s= 32, is 910163751

period + 1 for r= 20, s= 32, is 217 

period + 1 for r= 21, s= 32, is 1431562923

period + 1 for r= 12, s= 32, is 16383

period + 1 for r= 23, s= 32, is 268435455 

period + 1 for r= 24, s= 32, is 15

period + 1 for r= 25, s= 32, is 97612893

period + 1 for r= 26, s= 32, is 57337

period + 1 for r= 27, s= 32, is inf.

period + 1 for r= 28, s= 32, is 63 

period + 1 for r= 29, s= 32, is 1409286123 

period + 1 for r= 30, s= 31, is 255

period + 1 for r= 31, s= 32, is 1023


3. period for different seeds are not maximum possible value, some examples for r=1, s=5:
period for r= 1, s= 5, seed= 1 is 21 

period  for r= 1, s= 5, seed= 2 is 21 

period  for r= 1, s= 5, seed= 3 is 21 

period  for r= 1, s= 5, seed= 4 is 21 

period  for r= 1, s= 5, seed= 5 is 21 

period  for r= 1, s= 5, seed= 6 is 21 

period for r= 1, s= 5, seed= 7 is 7 

period for r= 1, s= 5, seed= 8 is 21 

period  for r= 1, s= 5, seed= 9 is 7 

period  for r= 1, s= 5, seed= 10 is 21 

period for r= 1, s= 5, seed= 11 is 21 

period  for r= 1, s= 5, seed= 12 is 21 

period  for r= 1, s= 5, seed= 13 is 3 

period  for r= 1, s= 5, seed= 14 is 7 

period  for r= 1, s= 5, seed= 15 is 21 

period  for r= 1, s= 5, seed= 16 is 21 

period  for r= 1, s= 5, seed= 17 is 21 

period for r= 1, s= 5, seed= 18 is 21 

period  for r= 1, s= 5, seed= 19 is 7 

period  for r= 1, s= 5, seed= 20 is 7 

period  for r= 1, s= 5, seed= 21 is 21 

period  for r= 1, s= 5, seed= 22 is 3 

period  for r= 1, s= 5, seed= 23 is 21 

period  for r= 1, s= 5, seed= 24 is 21 

period  for r= 1, s= 5, seed= 25 is 21 

period  for r= 1, s= 5, seed= 26 is 7 

period  for r= 1, s= 5, seed= 27 is 3 

period  for r= 1, s= 5, seed= 28 is 21 

period  for r= 1, s= 5, seed= 29 is 7 

period  for r= 1, s= 5, seed= 30 is 21 

period  for r= 1, s= 5, seed= 31 is 21 

another example for r=2 and s=7:
period for r= 2, s= 7, seed= 1 is 93 

period for r= 2, s= 7, seed= 2 is 93 

period for r= 2, s= 7, seed= 3 is 93 

period for r= 2, s= 7, seed= 4 is 93 

period for r= 2, s= 7, seed= 5 is 93 

period for r= 2, s= 7, seed= 6 is 93 

period for r= 2, s= 7, seed= 7 is 31 

period for r= 2, s= 7, seed= 8 is 93 

period for r= 2, s= 7, seed= 9 is 31 

period for r= 2, s= 7, seed= 10 is 93 

period for r= 2, s= 7, seed= 11 is 93 

period for r= 2, s= 7, seed= 12 is 93 

period for r= 2, s= 7, seed= 13 is 93 

period for r= 2, s= 7, seed= 14 is 31 

period for r= 2, s= 7, seed= 15 is 93 

period for r= 2, s= 7, seed= 16 is 93 

period for r= 2, s= 7, seed= 17 is 93 

period for r= 2, s= 7, seed= 18 is 31 

period for r= 2, s= 7, seed= 19 is 93 

period for r= 2, s= 7, seed= 20 is 93 

period for r= 2, s= 7, seed= 21 is 31 

period for r= 2, s= 7, seed= 22 is 93 

period for r= 2, s= 7, seed= 23 is 93 

period for r= 2, s= 7, seed= 24 is 93 

period for r= 2, s= 7, seed= 25 is 93 

period for r= 2, s= 7, seed= 26 is 93 

period for r= 2, s= 7, seed= 27 is 31 

period for r= 2, s= 7, seed= 28 is 31 

period for r= 2, s= 7, seed= 29 is 93 

period for r= 2, s= 7, seed= 30 is 93 

period for r= 2, s= 7, seed= 31 is 93 

period for r= 2, s= 7, seed= 32 is 93 

period for r= 2, s= 7, seed= 33 is 93 

period for r= 2, s= 7, seed= 34 is 31 

period for r= 2, s= 7, seed= 35 is 93 

period for r= 2, s= 7, seed= 36 is 93 

period for r= 2, s= 7, seed= 37 is 31 

period for r= 2, s= 7, seed= 38 is 93 

period for r= 2, s= 7, seed= 39 is 93 

period for r= 2, s= 7, seed= 40 is 93 

period for r= 2, s= 7, seed= 41 is 93 

period for r= 2, s= 7, seed= 42 is 93 

period for r= 2, s= 7, seed= 43 is 31 

period for r= 2, s= 7, seed= 44 is 31 

period for r= 2, s= 7, seed= 45 is 93 

period for r= 2, s= 7, seed= 46 is 93 

period for r= 2, s= 7, seed= 47 is 93 

period for r= 2, s= 7, seed= 48 is 31 

period for r= 2, s= 7, seed= 49 is 93 

period for r= 2, s= 7, seed= 50 is 93 

period for r= 2, s= 7, seed= 51 is 93 

period for r= 2, s= 7, seed= 52 is 93 

period for r= 2, s= 7, seed= 53 is 93 

period for r= 2, s= 7, seed= 54 is 3 

period for r= 2, s= 7, seed= 55 is 31 

period for r= 2, s= 7, seed= 56 is 93 

period for r= 2, s= 7, seed= 57 is 31 

period for r= 2, s= 7, seed= 58 is 93 

period for r= 2, s= 7, seed= 59 is 93 

period for r= 2, s= 7, seed= 60 is 93 

period for r= 2, s= 7, seed= 61 is 93 

period for r= 2, s= 7, seed= 62 is 31 

period for r= 2, s= 7, seed= 63 is 93 

period for r= 2, s= 7, seed= 64 is 93 

period for r= 2, s= 7, seed= 65 is 93 

period for r= 2, s= 7, seed= 66 is 93 

period for r= 2, s= 7, seed= 67 is 31 

period for r= 2, s= 7, seed= 68 is 31 

period for r= 2, s= 7, seed= 69 is 93 

period for r= 2, s= 7, seed= 70 is 93 

period for r= 2, s= 7, seed= 71 is 93 

period for r= 2, s= 7, seed= 72 is 93 

period for r= 2, s= 7, seed= 73 is 93 

period for r= 2, s= 7, seed= 74 is 31 

period for r= 2, s= 7, seed= 75 is 93 

period for r= 2, s= 7, seed= 76 is 93 

period for r= 2, s= 7, seed= 77 is 31 

period for r= 2, s= 7, seed= 78 is 93 

period for r= 2, s= 7, seed= 79 is 93 

period for r= 2, s= 7, seed= 80 is 93 

period for r= 2, s= 7, seed= 81 is 31 

period for r= 2, s= 7, seed= 82 is 93 

period for r= 2, s= 7, seed= 83 is 93 

period for r= 2, s= 7, seed= 84 is 93 

period for r= 2, s= 7, seed= 85 is 93 

period for r= 2, s= 7, seed= 86 is 31 

period for r= 2, s= 7, seed= 87 is 93 

period for r= 2, s= 7, seed= 88 is 31 

period for r= 2, s= 7, seed= 89 is 93 

period for r= 2, s= 7, seed= 90 is 93 

period for r= 2, s= 7, seed= 91 is 3 

period for r= 2, s= 7, seed= 92 is 93 

period for r= 2, s= 7, seed= 93 is 93 

period for r= 2, s= 7, seed= 94 is 93 

period for r= 2, s= 7, seed= 95 is 31 

period for r= 2, s= 7, seed= 96 is 93 

period for r= 2, s= 7, seed= 97 is 31 

period for r= 2, s= 7, seed= 98 is 93 

period for r= 2, s= 7, seed= 99 is 93 

period for r= 2, s= 7, seed= 100 is 93 

period for r= 2, s= 7, seed= 101 is 93 

period for r= 2, s= 7, seed= 102 is 31 

period for r= 2, s= 7, seed= 103 is 93 

period for r= 2, s= 7, seed= 104 is 31 

period for r= 2, s= 7, seed= 105 is 93 

period for r= 2, s= 7, seed= 106 is 93 

period for r= 2, s= 7, seed= 107 is 93 

period for r= 2, s= 7, seed= 108 is 93 

period for r= 2, s= 7, seed= 109 is 3 

period for r= 2, s= 7, seed= 110 is 93 

period for r= 2, s= 7, seed= 111 is 31 

period for r= 2, s= 7, seed= 112 is 93 

period for r= 2, s= 7, seed= 113 is 93 

period for r= 2, s= 7, seed= 114 is 93 

period for r= 2, s= 7, seed= 115 is 31 

period for r= 2, s= 7, seed= 116 is 31 

period for r= 2, s= 7, seed= 117 is 93 

period for r= 2, s= 7, seed= 118 is 93 

period for r= 2, s= 7, seed= 119 is 93 

period for r= 2, s= 7, seed= 120 is 93 

period for r= 2, s= 7, seed= 121 is 93 

period for r= 2, s= 7, seed= 122 is 31 

period for r= 2, s= 7, seed= 123 is 93 

period for r= 2, s= 7, seed= 124 is 93 

period for r= 2, s= 7, seed= 125 is 31 

period for r= 2, s= 7, seed= 126 is 93 

period for r= 2, s= 7, seed= 127 is 93 
 


 

*******************************************************************************/
