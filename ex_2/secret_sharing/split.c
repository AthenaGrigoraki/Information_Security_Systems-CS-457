
#include <stdio.h>
#include <math.h>
#include <fcntl.h> //need for open file
#include <unistd.h>

int main()
{
	int i;
	long long int password,a8,a7,a6,a5,a4,a3,a2,a1,a0,p,x;
	printf("give me password:\n");
	scanf("%lli",&password);

	//some intiate values, these will change according to urandom
	a8=8;a7=7;a6=6;a5=5;a4=4;a3=3;a2=2;a1=1;
	a0=password;
	/** call dev/random to create coefficients **/
	__uint8_t buffer[64];//max 8 digit is our coefficient-- 8digit x 8coeff.
	long long int tmp;// coefficient > 0
	int file=open("/dev/urandom",O_RDONLY);
	read(file,buffer,64);
	close(file);


	/** Assumption -- Aggregation of random numbers is a random number**/

/*** DECLARATION OF COEFFICIENTS a8-a1 ***/

	/**coefficient a8**/
	for(i=0;i<3;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a8=a8+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a8=a8-tmp;
		}
	}
	printf("a8=%lli\n",a8);



	/**coefficient a7**/
	for(i=3;i<6;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a7=a7+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a7=a7-tmp;
		}
	}
	printf("a7=%lli\n",a7);





	/**coefficient a6**/
	for(i=6;i<9;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a6=a6+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a6=a6-tmp;
		}
	}
	printf("a6=%lli\n",a6);



	/**coefficient a5**/
	for(i=9;i<12;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a5=a5+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a5=a5-tmp;
		}
	}
	printf("a5=%lli\n",a5);

	/**coefficient a4**/
	for(i=12;i<15;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a4=a4+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a4=a4-tmp;
		}
	}
	printf("a4=%lli\n",a4);


	/**coefficient a3**/
	for(i=15;i<18;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a3=a3+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a3=a3-tmp;
		}
	}
	printf("a3=%lli\n",a3);

	/**coefficient a2**/
	for(i=24;i<27;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a2=a2+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];

			a2=a2-tmp;
		}
	}
	printf("a2=%lli\n",a2);


	/**coefficient a1**/
	for(i=21;i<24;i++)
	{
		if(buffer[i]>0)
		{
			tmp=(long long int)buffer[i];
			a1=a1+tmp;
		}
		else if(buffer[i]<0)
		{
			tmp=(long long int)buffer[i];
			a1=a1-tmp;
		}
	}
	printf("a1=%lli\n",a1);


/**** END OF DECLARATION OF COEFFICIENTS  ***/



	x=1;

	//p=(a8*pow(x,8.0))+(a7*pow(x,7.0))+(a6*pow(x,6.0))+(a5*pow(x,5.0))+(a4*pow(x,4.0))+(a3*pow(x,3.0))+(a2*pow(x,2.0))+a1*x+a0;

	for (i=0;i<10;i++)
	{
	p=(a8*pow(x,8.0))+(a7*pow(x,7.0))+(a6*pow(x,6.0))+(a5*pow(x,5.0))+(a4*pow(x,4.0))+(a3*pow(x,3.0))+(a2*pow(x,2.0))+a1*x+a0;
	printf("The %d friend  will take this couple %lli,f(%lli)=%lli\n",i+1,x,x,p);
	x++;
	}

return 0;

}
