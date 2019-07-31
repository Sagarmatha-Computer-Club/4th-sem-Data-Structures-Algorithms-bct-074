#include<stdio.h>
int move=0;
int toh(int n, char s, char d, char i)
{
    FILE *file;
    file=fopen("Tower_of_hanoi.txt","a");
	if(n==1)
	{
		printf("Move disk 1 from %c to %c\n\n",s,d);
        fprintf(file,"-Move disk 1 from %c to %c\n\n",s ,d);
		move++;
	}
	else
	{
		toh(n-1,s,i,d);
		printf("Move disk %d from %c to %c\n\n",n,s,d);
        fprintf(file,"-Move disk %d from %c to %c\n\n",n,s,d);
		move++;
		toh(n-1,i,d,s);
	}
    fclose(file);
    return 0;
}
int main()
{
    FILE *file;
    file=fopen("tower_of_hanoi.txt","w");
	int n;
	printf("Enter number of disks: ");
    fprintf(file,"Enter number of disks: ");
	scanf("%d",&n);
    fprintf(file,"%d\n",n);
	toh(n, 's', 'd', 'i');
	printf("No of moves is %d",move);
    fprintf(file,"\nNo. of moves is %d",move);
    fclose(file);
    printf("\n");
	return 0;
}


