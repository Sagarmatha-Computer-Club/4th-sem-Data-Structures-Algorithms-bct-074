//Array implementation of list
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
int list[SIZE];
int no_of_val;
int ins(int , int);
void del(int);
void trv();
FILE * fp;

int main(){
  no_of_val=0;
  fp = fopen("lab2_list_out.txt", "w");
    int choice,pos,val;
    while(1){
    printf("CHOOSE THE MENU \n 1.INSERT\n 2.DELETE\n 3.DISPLAY (TRAVERSE)\n 4.EXIT\n:");
    fprintf(fp,"CHOOSE THE MENU \n 1.INSERT\n 2.DELETE\n 3.DISPLAY (TRAVERSE)\n 4.EXIT\n:");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("\nPosition: ");
        fprintf(fp,"\nPosition: ");
        scanf("%d",&pos);
        printf("\nvalue: ");
        fprintf(fp,"\nvalue: ");
        scanf("%d",&val);

        ins(pos,val);
        break;

        case 2:
        printf("\nValue: ");
        fprintf(fp,"\nValue: ");
        scanf("%d",&val);
        del(val);
        break;

        case 3:
        trv();
        break;

        case 4:
        default:
        fclose(fp);
        exit(0);
        break;
    }
    }
    fclose(fp);
    return 0;
}

int ins(int pos,int val){
    int i;
    if (no_of_val==0) {
		printf("Empty list so %d will be first element.\n\n" ,
    val);
    fprintf(fp,"Empty list so %d will be first element.\n\n" ,
    val);
        list[0] = val;
        no_of_val++;
    }
    else if (no_of_val+1 < pos) {
        printf("You cannot insert.\n\n");
        fprintf(fp,"You cannot insert.\n\n");
    }
	else if (no_of_val+1==pos){
		list[pos-1]=val;
		no_of_val++;
		printf("Inserted at last\n\n");
    fprintf(fp,"Inserted at last\n\n");
		}
  else{
    for( i = no_of_val-1; i >= pos-1; i--)
    {
        list[i+1] = list[i];   
    }

    list[pos-1]=val;
    no_of_val++;
    printf("Inserted\n\n");
    fprintf(fp,"Inserted\n\n");
  }
    return 0;
}
void del(val){
    int i,pos,j;
    pos = -1;
    // for( i = 0; i < no_of_val; i++)
    // {
    //     if (list[i]==val) {
    //         pos = i;
    //         for(j= pos;j<no_of_val;j++){
    //             list[j]=list[j+1];
    //         }
    //         no_of_val--;
    //     }
    // } // below shows why while is useful.
    //can't update i
    i=0;
    while(i<no_of_val){
      if (list[i]==val) {
            pos = i;
            for(j= pos;j<no_of_val;j++){
                list[j]=list[j+1];
            }
            no_of_val--;
            i=-1;//re-running from beginning. updated i.
        }
      i++;
    }
    if (pos == -1 ){
       printf("nothing to delete\n");
       fprintf(fp,"nothing to delete\n");
    }
    }
void trv(){
    int i;
    if (no_of_val==0) {
        printf("\n Nothing to display:\n");
        fprintf(fp,"\n Nothing to display:\n");
    }
    else{
    printf("\n[ ");
    fprintf(fp,"\n[ ");
    for( i = 0; i < no_of_val; i++)
    {
        printf("%d , ",list[i]);
        fprintf(fp,"%d ",list[i]);

    }
    printf("\b\b]\n\n");
    fprintf(fp,"]\n\n");

    }
  
        
}

