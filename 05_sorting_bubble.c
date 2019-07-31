#include<stdio.h>
int random[1000];
void increasing_order(int);
void decreasing_order(int);
void display(int);
int main()
{
	FILE *file;
	file=fopen("sorting_file.txt","w");
	int i,a,b,m,n,choice;
	random[0]=5;
	m=600;
	
	printf("Enter value of a: ");
	fprintf(file,"Enter value of a: ");
	scanf("%d",&a);
	fprintf(file,"%d\nEnter value of b: ",a);
	printf("Enter value of b: ");
	scanf("%d",&b);
	fprintf(file,"%d\nEnter a value of n: ",b);
	printf("Enter a value of n: ");
	scanf("%d",&n);
	fprintf(file,"%d\n",n);
	//Random numbers generation
	for(i=1; i<n; ++i)
	{
		random[i]=(a*random[i-1]+b)%m;
		printf("%d\t",random[i]);
		fprintf(file,"%d\t",random[i]);
		if((i%10)==0)
		{
			printf("\n");
			fprintf(file,"\n");
		}
	}
	printf("\n\nChoose if you want to sort in ascending or decending\n");
	printf("\n(1)Ascending order\n(2)Desending order\n\n");
	fprintf(file,"\n\nChoose if you want to sort in ascending or decending\n");
	fprintf(file,"\n1.Ascending order\n2.Desending order\n\n");
	scanf("%d",&choice);
	fprintf(file,"%d\n",choice);
	switch(choice)
	{
		case 1: increasing_order(n);
	            display(n);
	    break;
		case 2: decreasing_order(n);
	            display(n);
		break;
	}
	printf("\n");
	fprintf(file,"\n");
	fclose(file);
	return 0;
}
//sorting the numbers generated from the random number generator in asending order
void increasing_order(int n)
{
	int i, j, temp;
	for(i=0; i<n;i++)
	{
		for(j=i; j<n;j++)
		{
			if(random[i]>random[j])
			{
				temp=random[i];
				random[i]=random[j];
				random[j]=temp;
			}
		}
	}
}
//sorting the numbers generated from the random number generator in desending order
void decreasing_order(int n)
{
	int i, j, temp;
	for(i=0; i<n;i++)
	{
		for(j=i; j<n;j++)
		{
			if(random[i]<random[j])
			{
				temp=random[i];
				random[i]=random[j];
				random[j]=temp;
			}
		}
	}
}
//display of sorted array
void display(int n)
{
	FILE *file;
	file=fopen("sorting_file.txt","a");
	int i;
	printf("\n\nSorted list of random generated numbers:  \n\n");
	fprintf(file,"\n\nSorted list of random generated numbers: \n\n)");
	for(i=0; i<n;i++)
	{
		printf("%d\t",random[i]);
		fprintf(file,"%d\t",random[i]);
		if((i+1)%10==0)
		{
			printf("\n");
			fprintf(file,"\n");
		}
	}
	//fclose(file);
}
