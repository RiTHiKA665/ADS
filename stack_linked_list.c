#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int data;
	struct stack *lnk;
}stack;

stack *top=NULL,*tmp;
int elm,i;

void push(int);
int pop();
void display();
int peek();
int IsEmpty();
int IsFull();

main()
{
	int ch;
	while(1)
	{
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Dispaly");
		printf("\n 4. Peek");
		printf("\n 5. IsEmpty");
		printf("\n 6. IsFull");
		printf("\n 7. Exit");
		printf("\n Enter your choice");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:  
				    tmp=(stack*)malloc(sizeof(stack));
				    if(tmp==NULL)
				    	printf("Stack Overflows");
				    else
				    {
				    	printf("Enter the value to push");
				    	scanf("%d",&elm);
				    	push(elm);
					}
					break;

			case 2:
					elm=pop();
					if(elm==-1)
						printf("Stack Underflows");
					else
						printf("%d popped from stack successfully",elm);
				    break;

			case 3: 
					display();
					break;

			case 4:
					elm=peek();
					if(elm==-1)
						printf("Stack is Empty");
					else
						printf("%d is the top element of the stack",elm);
					break;

			case 5:
					if(IsEmpty())
						printf("Yes, Stack is Empty");
					else
						printf("No, Stack is not Empty");
					break;

			case 6:
					if(IsFull())
					   printf("Yes, the stack is Full");
					else
					   printf("No, the stack is not Full");
					break;

			case 7: exit(0);

			default:
					printf("Invalid choice");
		}	
	}
}

void push(int n)
{
	tmp->data=n;
	tmp->lnk=NULL;

	if(top==NULL)
		top=tmp;
	else
	{
		tmp->lnk=top;
		top=tmp;
	}

	printf("%d pushed into the stack successfully",n);
}

void display()
{
	if(top==NULL)
	{
		printf("Stack is Empty");
		return;
	}

	stack *dsp=top;
	printf("List is ... ");

	while(dsp!=NULL)
	{
		printf("%d ",dsp->data);
		dsp=dsp->lnk;
	}

	free(dsp);
}

int pop()
{
	if(top==NULL)
		return -1;
	else
	{
		tmp=top;
		top=top->lnk;
		elm=tmp->data;
		free(tmp);
		return elm;
	}	 	
}

int peek()
{
	if(top==NULL)
		return -1;
	else
		return top->data;
}

int IsEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int IsFull()
{   
	tmp=(stack*)malloc(sizeof(stack));

	if(tmp==NULL)
		return 1;
	else
	    return 0;
}
