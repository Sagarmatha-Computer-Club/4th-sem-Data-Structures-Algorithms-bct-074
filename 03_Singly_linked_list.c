#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
 struct node*next;
};
struct node *head;
void create();
void traverse();
void insert_beg();
void insert_spec();
void insert_end();
void delete_beg();
void delete_spec();
void delete_end();
FILE * fp;


int main()
{
	fp = fopen("linked_list.txt","w");
	int n;
	while(1)
	{
		
		printf("\n\n1.create\n2.traverse\n3.insert\n4.delete\n5. Exit");
		fprintf(fp,"\n\n1.create\n2.traverse\n3.insert\n4.delete\n5. Exit");
		printf("\nEnter your choice:");
		fprintf(fp,"\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				create();
			break;
			case 2:
				traverse();
			break;
			case 3:
				printf("\n1.Beg\n2. Specific\n3.End\n:");
				fprintf(fp,"\n1.Beg\n2. Specific\n3.End\n:");
				scanf("%d",&n);
				switch(n)
				{
					case 1:
						insert_beg();
					break;
					case 2:
						insert_spec();
					break;
					case 3:
						insert_end();
				}
			break;
			case 4:
				printf("\n1.Beg\n2. Specific\n3.End\n:");
				fprintf(fp,"\n1.Beg\n2. Specific\n3.End\n:");
				scanf("%d",&n);
				switch(n)
				{
					case 1:
						delete_beg();
					break;
					case 2:
						delete_spec();
					break;
					case 3:
						delete_end();
				}
			break;
			case 5:
			default:
				exit(0);
		}
	}
	fclose(fp);
}

void create()
{
struct node*p;
p=(struct node *) malloc (sizeof(struct node));
printf("Enter the value:");
fprintf(fp,"Enter the value:");
scanf("%d",&p->data);
head=p;
head->next=NULL;
printf("Successfully created..\n");
fprintf(fp,"Successfully created..\n");
}
void traverse()
{
	struct node *p;
	p=head;
	
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		fprintf(fp,"%d\t",p->data);
		p=p->next;
	}
	
	

}

 void insert_beg()
 {
	struct node *p;
	
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to insert:");
	fprintf(fp,"Enter value to insert:");
	scanf("%d",&p->data);
	p->next=head;
	head=p;
	printf("%d succesfully inserted\n",p->data);
	fprintf(fp,"%d succesfully inserted\n",p->data);
 }
void insert_spec()
{
	struct node *p,*t;
	int val,found=0;
	
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to insert:");
	fprintf(fp,"Enter value to insert:");
	scanf("%d",&p->data);
	printf("Enter value after which you want to insert:");
	fprintf(fp,"Enter value after which you want to insert:");
	scanf("%d",&val);
	t=head;
	while(t!=NULL)
	{
		if(t->data==val)
		{
			found=1;
			p->next=t->next;
			t->next=p;
			break;
		}
		else
			t=t->next;
	}
	if(found==0)
	{
		printf("Not Found\n");
		fprintf(fp,"Not Found\n");
	}
	else
	{
		printf("%d succesfully inserted\n",p->data);
		fprintf(fp,"%d succesfully inserted\n",p->data);
	}
}


void insert_end()
{
	struct node *p,*t;
	
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to insert:");
	fprintf(fp,"Enter value to insert:");
	scanf("%d",&p->data);
	t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=p;
	printf("%d succesfully inserted",p->data);
	fprintf(fp,"%d succesfully inserted",p->data);
	
	
}
void delete_beg()
{
	if(head==NULL)
	{
		printf("Under Flow!");
		fprintf(fp,"Under Flow!");
		
		
		
	}
	else
	{
		printf("%d succesfully inserted",head->data);
		fprintf(fp,"%d succesfully inserted",head->data);
		head=head->next;
		
		
		
	}
}

void delete_spec()
{ 	struct node *t,*d;
	int val,found=0;
	
	printf("Enter value after which you want to delete:");
	fprintf(fp,"Enter value after which you want to delete:");
	scanf("%d",&val);
	t=head;
	while(t!=NULL)
	{
		if(t->data==val)
		{
			found = 1;
			d=t->next;
			t->next=d->next;
			break;
		}
		else
		{
			t=t->next;
		}
	}
	if(found==0)
	{
		printf("Not Found");
		fprintf(fp,"Not Found");
		printf("Press enter to go back to main menu...");
		fprintf(fp,"Press enter to go back to main menu...");
		
		
	}
	else
	{
		printf("\nvalue after %d succesfully deleted",val);
		fprintf(fp,"\nvalue after %d succesfully deleted",val);
		
		
		
	}


}
void delete_end()
{
	struct node *t,*p;
	
	t=head;
	while(t->next!=NULL)
	{
		p=t;
		t=t->next;
	}
	
	p->next=NULL;
	printf("succesfully deleted");
	fprintf(fp,"succesfully deleted");
	
	
	
}
