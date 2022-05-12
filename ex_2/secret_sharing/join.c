

#include <string.h> //strtok is defined here
#include <stdio.h>
#include <stdlib.h> // strtoll is defined here
#include <math.h> //define pow





int main(int argc, char *argv[])
{

	if (argc<10)
	{
		printf("Not enough points!\n");
		return 0;
	}



	char  *ptr;// a pointer to string
	long long int x,fx;
	double M[10][11],transform,cnt,tmp;
	// 9 iterations to make our table
	int i;
	for (i=1;i<10;i++)
	{
		/** The string is decomposed to tokens based on the delimeter we define, in our app  is coma ','**/
		ptr=strtok(argv[i],",");


		/** covert string to long long int using strtoll **/

		x= strtoll(ptr,NULL,10);
		printf("x= %lli,",x);


		ptr=strtok(NULL,",");
		fx = strtoll(ptr,NULL,10);

		printf("fx= %lli\n",fx);



		//Create the Matrix 9x10 --- last column (10th)  is the fx
		cnt=8.0;// a counter that represent the power  of x
		int j;
		for(j=1;j<11;j++)
		{
			if(j==10)
			{
				tmp=(double)fx;
				M[i][j]=tmp;
			}
			else
			{
				tmp=(double)x;
				M[i][j]=pow(tmp,cnt);
				cnt=cnt-1.0;
			}
			printf("%lf",M[i][j]);
		}


	}

	/**Gaus Elimination - common technique - i had a guide code found in codesansar.com
		All calculations are done using double numbers because of divisions	 **/
	for (i=1;i<9;i++)
	{
		int j;
		for(j=i+1;j<10;j++)
		{
			transform=M[j][i]/M[i][i];
			int k;
			for(k=1;k<11;k++)
			{
				M[j][k]=M[j][k]-transform*M[i][k];
			}
		}

	}
	long long int password;
	tmp=M[9][10]/M[9][9];

	password=(long long int)tmp;
	printf("\n");
	printf( " Password is  %lli\n",password);




	return 0;
}
