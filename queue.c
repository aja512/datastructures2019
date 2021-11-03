/*
AMANDA JUDY ANDRDADE
SE-IT 2
Practical 8A
Write a menu driven program to implement QUEUE ADT using array and perform the following operation
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

int front=-1,rear=-1;
int queue[MAX];
void enqueue();
void dequeue();
void peek();
void display();

int main()
{
	int ch,p;
	do
	{
		printf("\n********************MENU*********************\n");
		printf("\n1. Insert an Element\n2. Delete an Element\n3. Peek\n4. Display Queue\n5. EXIT\n\n");	
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
					break;
			case 2:dequeue();
					break;
			case 3:peek();
					break;
			case 4:display();
					break;
			case 5:exit(0);
					break;
			default:printf("Invalid Input!!!\n");;
					break;
			
		}
		printf("\nDo you wish to continue?\nPress 1 for Yes & 0 for No\n");
		scanf("%d",&p);
	}
	while(p!=0);
	return 0;
}
void enqueue()
{
	int x;
	printf("Enter data for insertion:");
	scanf("%d",&x);
	if(rear==MAX-1)
	{
		printf("\nOVERFLOW!!!!\n");
	}
	else
	if((front==-1)&&(rear==-1))
	{
		front=0;
		rear=0;
	}
	else 
	rear++;
	queue[rear]=x;
	display();
}
void dequeue()
{
	int x;
	if((front==-1)||(front>rear))
	{	
		printf("\nUNDERFLOW!!!\n");
	}
	else
	{
		printf("Element deleted:%d",queue[front]);
		front++;
		if(front>rear)
		front=rear=-1;
	}
	display();
}
void peek()
{
	if((front==-1)||(front>rear))
	{	
		printf("\nUNDERFLOW!!!\n");
	}
	else
	{
		printf("Element present at the front:%d\n",queue[front]);
	}
}
void display()
{
	int i;
	printf("\nQueue:\n");
	if((front==-1)||(front>rear))
	{	
		printf("\nUNDERFLOW!!!\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		printf("\t%d ",queue[i]);
	}
}
/*
O/P:-
1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:1

Queue:
        1
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 2
Element deleted:1
Queue:

UNDERFLOW!!!

Do you wish to continue?
Press 1 for Yes & 0 for No
1
********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:1

Queue:
        1
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:2

Queue:
        1       2
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:3

Queue:
        1       2       3
Do you wish to continue?
Press 1 for Yes & 0 for No
14

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:14

Queue:
        1       2       3       14
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:5

Queue:
        1       2       3       14      5
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 1
Enter data for insertion:55

OVERFLOW!!!!

Queue:
        1       2       3       14      55
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 2
Element deleted:1
Queue:
        2       3       14      55
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 3
Element present at the front:2

Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 2
Element deleted:2
Queue:
        3       14      55
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 2
Element deleted:3
Queue:
        14      55
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 2
Element deleted:14
Queue:
        55
Do you wish to continue?
Press 1 for Yes & 0 for No
1

********************MENU*********************

1. Insert an Element
2. Delete an Element
3. Peek
4. Display Queue
5. EXIT

Enter your choice: 2
Element deleted:55
Queue:

UNDERFLOW!!!

Do you wish to continue?
Press 1 for Yes & 0 for No
0

--------------------------------
Process exited after 201.9 seconds with return value 0
Press any key to continue . . .
*/
