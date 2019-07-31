#include<stdio.h>
//#include<conio.h>
int fibo_series(int);
int main()
{
    FILE *file;
    file=fopen("fibonacci.txt","w");
	int n,i;
	fprintf(file,"Name: Nabin Dhakal\nRoll: 022\nProgram: BCT\n\n");
	printf("Enter number of terms: 	");
    fprintf(file,"Enter number of terms: ");
	scanf("%d",&n);
    fprintf(file,"%d\n",n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",fibo_series(i));
        fprintf(file,"%d ",fibo_series(i));
	}
    fclose(file);
    printf("\n");
	return 0;
}
int fibo_series(int n)
{
	if(n==1)
	{
			return 1;
	}
	else if(n==2)
	{
			return 1;
	}
	else
	{
			return (fibo_series(n-1)+fibo_series(n-2));
	}
}
