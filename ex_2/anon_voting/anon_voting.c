#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include <math.h>
#include <ctype.h>

unsigned long function(int *y,int x){

    unsigned long sum=0;
    int i;

    for(i=0; i<3; i++){
        sum= sum + (y[i] * pow(x,i));
        

    }
    return sum;
}

unsigned long *voters_func(int *x){

    unsigned long *voters=malloc(5*sizeof(unsigned long));
    
    int i;

    for(i=1; i<4; i++){
        voters[i]=function(x,i); //pairnei a(1) athroisma, a(2) ... klp

    }

    return voters;
}


int main(int argc, char** argv){

    int A[3];
    int B[3];
    int C[3];
    int D[3];
    float x,sum=0;
    int co1[3];
    int co2[3];
    int co3[3];
    int d0;
    int i=0;
    int vote1,vote2,vote3;
    vote1=atoi(argv[1]);
    vote2=atoi(argv[2]);
    vote3=atoi(argv[3]);
    
    d0=vote1+vote2+vote3;
    printf("d0 is %d\n", d0);

    static unsigned long *voters_split_A;
    static unsigned long *voters_split_B;
    static unsigned long *voters_split_C;
    unsigned long *voters_split_D=malloc(sizeof(unsigned long)* 4);

    srand(time(0));

    co1[0]=vote1;
    co2[0]=vote2;
    co3[0]=vote3;
    for(i=1; i<4; i++){
        co1[i]=rand();
        co2[i]=rand();
        co3[i]=rand();
        
    }

    for(i=0; i<4; i++){
        
        printf("Random x for A is x[%d] is %d\n",i, co1[i]);
        printf("Random x for B is x[%d] is %d\n",i, co2[i]);
        printf("Random x for C is x[%d] is %d\n",i, co3[i]);
    }

    voters_split_A=voters_func(co1);
    voters_split_B=voters_func(co2);
    voters_split_C=voters_func(co3);

    printf("Points after voting:\n");
	for(int i=1; i<4; i++) {
		printf(" A(%d) = %lu\n",i, voters_split_A[i]);
        printf(" B(%d) = %lu\n",i, voters_split_B[i]);
        printf(" C(%d) = %lu\n",i, voters_split_C[i]);
        voters_split_D[i]=voters_split_A[i]+voters_split_B[i]+voters_split_C[i];
        
    }

    for(int i=1; i<4; i++){
        printf("(%d, D(%d)) = %lu\n",i,i, voters_split_D[i]);

    }

    printf("D(x)= %lu * x^2+ %lu * x + %d\n",voters_split_D[2],voters_split_D[1],d0);

    return 0;
}