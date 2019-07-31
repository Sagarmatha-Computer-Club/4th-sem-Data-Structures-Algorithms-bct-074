//NABIN-022-BCT
#include <stdio.h>
#include <ctype.h>


#define SIZE 50

void pop();
void push(char);
int prec(char);


char inexp[SIZE];
char stack[SIZE];
char postexp[SIZE],ch;

int TOP,in,pin,i;
	in=0;
	pin=0;
	TOP=-1;


int main(){
	FILE * fp;
	fp = fopen("inf2post.txt","w");
	printf("Infix Expression\n");
	scanf("%s",inexp);
	printf("\nInfix to postfix conversion for %s\n",inexp);
	printf("*****************************************\n\n");
	
	printf(" %-11s%-12s%-12s \n\n","Symbol","Stack","Expression");
	fprintf(fp,"\nInfix to postfix conversion for %s\n",inexp);
	fprintf(fp,"*****************************************\n\n");
	
	fprintf(fp," %-11s%-12s%-12s \n\n","Symbol","Stack","Expression");

	while(inexp[in]!='\0'){
        ch=inexp[in];
        
		if (ch=='(') {

        push(ch);
        }
        else if (ch==')'){
			do{
				pop();
			}while(stack[TOP]!='(');
			
			TOP--;
		}
		else if (isalpha(ch))
		{
			postexp[pin] = ch;
			pin++;
			
		}

		else {
                
                while(prec(stack[TOP])>=prec(ch)){
                pop();}
				push(ch);
			}
            
	//Displaying the table row
	printf(" %-11c ",ch); // symbol
    printf("%-12s",stack);//stack
    printf("%s\n",postexp);//postfix expression
    
    fprintf(fp," %-11c ",ch); // symbol
    fprintf(fp,"%-12s",stack);//stack
    fprintf(fp,"%s\n",postexp);//postfix expression
   
	in++;

	}
	while(TOP!=-1){
		pop();
	}
	
	printf("\nThe postfix Expression is:\n %s",postexp);
	fprintf(fp,"\nThe postfix Expression is:\n %s",postexp);
	fclose(fp);
	return 0;
}

int prec(char x){
	switch(x){
	    case '(':return 0;
		case '$': return 4;
		case '/': return 3;
		case '*': return 2;
		case '+':
        case '-': return 1;
	}
}

void pop(){
	postexp[pin] = stack[TOP];
	pin++;
	TOP--;
}
void push(char c){
	if (TOP == SIZE)
	{
		printf("Stack Overflow\n");
	}
	TOP++;
	stack[TOP] = c;
}
