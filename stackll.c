#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack
{
	int data;
	struct stack *next;
};
int count=0;
struct stack *top=NULL;
struct stack *getnode(void);
void push();
void pop();
void display(struct stack *);
void peek();

struct stack *getnode(void)
{
	return ((struct stack*)malloc(sizeof(struct stack)));
}
int main()
{
	int ch,p;
	do
	{
	 	printf("\n\n MENU \n\n1.PUSH\n\2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				   break;
			case 2:pop();
				   break;
			case 3:display(top);
				   break;
			case 4:peek();
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
void display(struct stack *start)
{
	struct stack *ptr;
	ptr=start;
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		printf("List:\n");
		while(ptr!=NULL)
		{
			printf("Node =\t%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
void push()
{
	struct stack *ptr;
	ptr=getnode();
	printf("Enter data:\n");
	scanf("%d",&ptr->data);
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
		count++;
	}
	else
	{
		if(count==size)
		printf("\nStack Overflow\n");
		else
		{
			ptr->next=top;
			top=ptr;
			count++;
		}
	}
	display(top);
}
void pop()
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		count--;
		top=top->next;
		printf("%d is deleted",ptr->data);
		free(ptr);
	}
	display(top);
}
void peek()
{
	if(top==NULL)
	printf("\nStack Underflow\n");
	else
	printf("\t%d\t",top->data);
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
Enter data:
1
List:
Node =  1
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
Enter data:
2
List:
Node =  2       Node =  1
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
Enter data:
3
List:
Node =  3       Node =  2       Node =  1
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
Enter data:
4
List:
Node =  4       Node =  3       Node =  2       Node =  1
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
Enter data:
5
List:
Node =  5       Node =  4       Node =  3       Node =  2       Node =  1
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
Enter data:
5

Stack Overflow
List:
Node =  5       Node =  4       Node =  3       Node =  2       Node =  1
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
5 is deletedList:
Node =  4       Node =  3       Node =  2       Node =  1
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
4 is deletedList:
Node =  3       Node =  2       Node =  1
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
3 is deletedList:
Node =  2       Node =  1
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
2 is deletedList:
Node =  1
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
1 is deletedList doesn't exist!!Please create one!!!

Do you wish to continue?
Press 1 for Yes & 0 for No
0
*/
