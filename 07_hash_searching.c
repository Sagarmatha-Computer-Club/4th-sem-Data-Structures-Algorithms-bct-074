#include<stdio.h>
#include<stdlib.h>
int h[100];
void insert(int);
void search(int);
void display();
int main()
{
    FILE *file;
    file=fopen("hash_search.txt","w");
    int ch,value,i;
    for(i=0;i<100;i++)
    {
        h[i]=-1;
    }

    while(1)
    {
		printf("\nImplementation of Hashing as a searching algorithm\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
    fprintf(file,"\nImplementation of Hashing as a searching algorithm\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("\n>>");
        fprintf(file,"\nEnter your choice: ");
        scanf("%d",&ch);
        fprintf(file,"%d",ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter a value to insert:");
                fprintf(file,"\nEnter a value to insert:");
                scanf("%d",&value);
                fprintf(file,"%d",value);
                insert(value);
            break;
            case 2:
                printf("\nEnter a value to search:");
                fprintf(file,"\nEnter a value to search:");
                scanf("%d",&value);
                fprintf(file,"%d",value);
                search(value);
            break;
            case 3:
                display();
            break;
            case 4:
                exit(0);
        }
    }
    printf("\n");
    fclose(file);
}
void insert(int value)
{
    FILE *file;
    file=fopen("hash_search.txt","a");
    int index,i;
    index=(value%103)+1;
    for(i=index;i<100;i++)
    {
        if(h[i]==-1)
        {
            h[i]=value;
            break;
        }
    }
    if(i==100)
    {
        printf("\nHash table over flow!\n");
        fprintf(file,"\nHash table over flow!\n");
    }
    fclose(file);
}
void search(int value)
{
    FILE *file;
    file=fopen("hash_search.txt","a");
    int index,i;
    index=(value%103)+1;
    for(i=index;i<100;i++)
    {
        if(h[i]==value)
        {
            printf("\n%d found at index %d\n",value,i);
            fprintf(file,"\n%d found at index %d\n",value,i);
            break;
        }
    }
    if(i==100)
    {
        printf("\n%d not found in the hash table!\n",value);
        fprintf(file,"\n%d not found in the hash table!\n",value);
    }
    fclose(file);
}
void display()
{
    FILE *file;
    file=fopen("hash_search.txt","a");
    int i;
    for(i=0;i<100;i++)
    {
        if(h[i]!=-1)
        {
            printf("\nh[%d]=%d",i,h[i]);
            fprintf(file,"\nh[%d]=%d",i,h[i]);
        }
    }
    fclose(file);
}

