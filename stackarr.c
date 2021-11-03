#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size],top=-1;

void push(int stack[],int val);
int pop(int stack[]);
void display(int stack[]);
int peek(int stack[]);

int main()
{
	int ch,p,val;
	do
	{
	 	printf("\n\n MENU \n\n1.PUSH\n\2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter value:\n");//Ask the user to enter position and value for the position he/she entered
			       scanf("%d",&val);
			       push(stack,val);
				   break;
			case 2:val=pop(stack);
			       if(val!=-1)
			       printf("\n%d is deleted\n",val);
				   break;
			case 3:display(stack);
				   break;
			case 4:val=peek(stack);
			       if(val!=-1)
			       printf("Value  stored at the top=%d",val);
				   break;
			case 5:exit(0);
				   break;	   
			default:printf("Invalid Input!!!\n");
				   break;				   				   				   	   
		}
		printf("\nDo you wish to continue?\nPress 1 for Yes & 0 for No\n");
		scanf("%d",&p);	
	}
   	while(p!=0);
	return 0;
}
void push(int stack[],int val)
{
	if(top==size-1)
	printf("\nStack Overflow\n");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	int val;
	if(top==-1)
	{
		printf("\nStack Underflow\n");	
		return -1;
	}
	else
	{
		val=stack[top];
		top--;
		return val;
	}
}
void display(int stack[])
{
	int i;
	if(top==-1)
	printf("\nStack Underflow\n");	
	else
	{
		printf("\nSTACK\n");
		for(i=top;i>=0;i--)
		{
			printf("\n%d\n",stack[i]);
		}
	}
}
int peek(int stack[])
{
	int val;
	if(top==-1)
	{
		printf("\nStack Underflow\n");	
		return -1;
	}
	else
	{
		return(stack[top]);
	}
}
/*
O/P:-

 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
2

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
3

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
4

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
5

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
5

Stack Overflow

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

STACK

5

4

3

2

1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

5 is deleted

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

STACK

4

3

2

1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

4 is deleted

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

STACK

3

2

1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

3 is deleted

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

STACK

2

1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

2 is deleted

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

STACK

1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

1 is deleted

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

Stack Underflow

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
2

1 is deleted

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

Stack Underflow

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
2

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
1

Enter value:
3

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
3

STACK

3

2

1

Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
4
Value  stored at the top=3
Do you wish to continue?
Press 1 for Yes & 0 for No
1


 MENU

1.PUSH
.POP
3.DISPLAY
4.PEEK
5.EXIT

Enter your choice:
5

--------------------------------
Process exited after 215.8 seconds with return value 0
Press any key to continue . . .
*/
