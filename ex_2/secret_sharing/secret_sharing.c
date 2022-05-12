#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include <math.h>
#include <ctype.h>

typedef struct points{
    int index;
    unsigned long values;
}points;

/*split*/
unsigned long function(int *y,int x){

    unsigned long sum=0;
    int i;

    for(i=0; i<3; i++){
        sum= sum + (y[i] * pow(x,i));
        

    }
    return sum;
}

unsigned long *points_func(int password,int *x){

    unsigned long *points=malloc(5*sizeof(unsigned long));
    points[0]=password;
    int i;

    for(i=1; i<4; i++){
        points[i]=function(x,i);

    }

    return points;
}
/*end of split*/

/*join*/

points* get_values(char **argv){
    int i;
    int j;
    int *indexes=malloc(sizeof(int) * 5);
    points *points = malloc(sizeof(points)*4);
    const char delim[2]=",";
    unsigned long *values=malloc(sizeof(unsigned long) * 5);
    char *tokens;

    for(i=2; i<5; i++){ /*arxizei apo 2 gia na agnoisei to prwto token join*/

        
        tokens= strtok(argv[i], delim);
        
        
        points[i-2].index=atoi(tokens);
       
        


        while(tokens != NULL){
            
           
            tokens=strtok(NULL,delim);
          
           if(tokens != NULL){
             
            points[i-2].values=strtoll(tokens,0,10);
            
            
           }
            
        }

    }
    return points;

}

double join_func(points *points){
    double **matrix=malloc(sizeof(double)*4);
    int i,j;
    double *x=malloc(sizeof(double)*4);
    int k;
    double final;
    double middle;
    double y;
    double end; 

    for(i=0; i<3; i++){

        matrix[i]=malloc(sizeof(double)*4);
    }

    y=2.0;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            if(j == 3){
                matrix[i][j]=(double)points[i].values;
               // printf("matrix in %d,%d is %f\n",i,j,matrix[i][j]);
            }else{
            matrix[i][j]=pow(points[i].index,y);
            y-= 1.0;
           // printf("matrix in %d,%d is %f\n",i,j,matrix[i][j]);
            }
            
        }
        
    }


    for(i=0; i<2; i++){
        
        for(j=i+1; j<3; j++){
            
            final=matrix[j][i]/matrix[i][i];
           // printf("final  in %d,%d is %lf\n",i,j,final);
            for(k=1; k<4; k++){
                matrix[j][k]=matrix[j][k] - (final * matrix[i][k]);

               // printf("matrix in %d,%d is %lf\n",j,k,matrix[i][j]);
                }
            

        }
    }
   // printf("1. %lf, 2. %lf\n",matrix[2][3],matrix[2][2]);
   for(i=0; i<3; i++){
       for(j=0; j<4; j++){
           printf("matrix %d %d is %f\n",i,j,matrix[i][j]);
       }
   }

    
    

    middle=matrix[2][3]/matrix[2][2];
   // printf("middle value is %f\n",middle);

    end=(double)middle;

    return end;

 /*   for(i=0; i<3; i++){

        y=2.0;
        for(j=0; j<3; j++){
            if(j == 2){
                k=(double)points[i].values;
                matrix[i][j]=k;
            }else{
                k=(double)points[i].index;
                matrix[i][j]=pow(k,y);
                y=y-1.0;
            }
        }
    }
    int c;

    for(i=0; i<3; i++){
        for(j=i+1; j<4; j++){
            final=matrix[j][i]/matrix[i][i];
            for(c=0; c<3; c++){
                matrix[j][c]=matrix[j][c]-final*matrix[i][c];
            }
        }
    }

    k=matrix[2][3]/matrix[3][3];

    return k;*/

}

/*end of join*/

int main(int argc, char** argv){

    int x[4];
    int i;

    unsigned long password;
    double k;
    static unsigned long *points_split;
    points *points_join;
    char* text=malloc(sizeof(char) * 10);
    
    text=argv[1];
    printf("text is %s\n", text);
   



    /*printf("Enter password(number):\n");

    scanf("%lu", &password);
    fseek(stdin,0,SEEK_END);*/

    

    if(strstr(text,"split")){

    password= strtol(argv[2],0,10);
    printf("password is %lu\n", password); 

    srand(time(0));

    x[0]=password;
    for(i=1; i<4; i++){
        x[i]=rand();
        
    }

    for(i=1; i<4; i++){
        
        printf("Random x is x[%d] is %d\n",i, x[i]);
    }

    points_split=points_func(password,x);

    printf("Points after split:\n");
	for(int i=0; i<3; i++) {
		printf("( %d, f(%d)) = %lu\n",i,i, points_split[i]);
    }
    
    }else if(strstr(text,"join")){
        int i;
        printf("mpainei\n");
       
        points_join=get_values(argv);
        printf("Points passed from command line:\n"); /*join 1,2 2,3 3,4*/
        for(int i=0; i<3; i++) {

		    printf(" f(%d) = %lu\n", points_join[i].index, points_join[i].values);

            
        }
        k=join_func(points_join);
        printf("k is %f\n", k);
        password=(unsigned long)k;
        printf("password is %lu\n", password);

    }


    free(points_split);
    free(text);

    return 0;
}