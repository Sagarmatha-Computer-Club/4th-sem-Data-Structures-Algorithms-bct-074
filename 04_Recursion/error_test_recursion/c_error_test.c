#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("error_out.txt","a");
    static int counter=0;
	printf("this is direct recursion\n");
	fprintf(fp,"this is direct recursion\n");
	if(counter<5){
    counter++;
    /*infinite time,if this statement removed */
	main();
	fclose(fp);
    }
}
