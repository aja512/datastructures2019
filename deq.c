/*
Amanda Judy Andrade
SE-IT 2
Practical 10
Write a menu driven program to implement input and output restricted DEQUE. 
Assumption:
In input restricted deque insertion always happens in the left. 
In output restricted deque deletion always happens in the right.
*/
#include<stdio.h>
#include<stdlib.h>
#define size 10

int deque[size];
int left=-1,right=-1;

void input();
void output();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();

int main()
{
	int op;
	printf("\n*************** MAIN MENU ***************\n");
	printf("\n1. Input Restricted Deque\n2. Output Restricted Deque\n\n");
	printf("\nEnter your choice:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:input();
				break;
		case 2:output();
				break;
		default:printf("\nInvalid Input!\n");
				break;
	}
	return 0;
}

void input()
{
	int op;
	do
	{
		printf("\n*************** INPUT RESTRICTED DEQUE ***************\n");
		printf("\n1. Insert at Left\n2. Delete at Left\n3. Delete at Right\n4. Display\n5. EXIT\n\n");
		printf("\nEnter your choice:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:insert_left();
					break;
			case 2:delete_left();
					break;
			case 3:delete_right();
					break;
			case 4:display();
					break;
			default:printf("\nINVALID INPUT\n");
					break;
		}
	}
	while(op!=5);
}

void output()
{
	int op;
	do
	{
		printf("\n*************** OUTPUT RESTRICTED DEQUE ***************\n");
		printf("\n1. Insert at Left\n2. Insert at Right\n3. Delete at Right\n4. Display\n5. EXIT\n\n");
		printf("\nEnter your choice:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:insert_left();
					break;
			case 2:insert_right();
					break;
			case 3:delete_right();
					break;
			case 4:display();
					break;
			default:printf("\nINVALID INPUT\n");
					break;
		}
	}
	while(op!=5);
}

void insert_right()
{
	int val;
	printf("\nEnter the value for insertion:");
	scanf("%d",&val);
	if((left==0&&right==size-1)||(left==right+1))
	{
		printf("\nOVERFLOW!!!\n");
	}
	if(left==-1)                       /*If Queue is initially empty*/
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==size-1)    /*Right is at the last positon of the queue*/
		right=0;
		else
		right+=1;
	}
	deque[right]=val;
	display();
}

void insert_left()
{
	int val;
	printf("\nEnter the value for insertion:");
	scanf("%d",&val);
	if((left==0&&right==size-1)||(left==right+1))
	{
		printf("\nOVERFLOW!!!\n");
	}
	if(left==-1)                       /*If Queue is initially empty*/
	{
		left=0;
		right=0;
	}
	else
	{
		if(left==0)
		left=size-1;
		else
		left-=1;
	}
	deque[left]=val;
	display();
}

void delete_left()
{
	if(left==-1)
	{
		printf("\nUNDERFLOW\n");
	}
	printf("\nElement deleted:%d",deque[left]);
	if(left==right)         /*Queue has only 1 element*/
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(left==size-1)
		left=0;
		else
		left+=1;
	}
	display();
}

void delete_right()
{
	if(left==-1)
	{
		printf("\nUNDERFLOW\n");
	}
	printf("\nElement deleted:%d",deque[right]);
	if(left==right)         /*Queue has only 1 element*/
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(right==0)
		right=size-1;
		else
		right-=1;
	}
	display();
}

void display()
{
	int f=left,r=right;
	if(f==-1)
	printf("\nUNDERFLOW\n");
	printf("\nDEQUE:-\n");
	if(f<=r)
	{
		while(f<=r)
		{
			printf(" %d ",deque[f]);
			f++;
		}
	}
	else
	{
		while(f<size)
		{
			printf(" %d ",deque[f]);
			f++;	
		}
		f=0;
		while(f<=r)
		{
			printf(" %d ",deque[f]);
			f++;
		}
	}
	printf("\n");
}
/*
O/P:-

*************** MAIN MENU ***************

1. Input Restricted Deque
2. Output Restricted Deque


Enter your choice:1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:1

DEQUE:-
 1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:2

DEQUE:-
 2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:3

DEQUE:-
 3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:0

DEQUE:-
 0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:5

DEQUE:-
 5  0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:4

DEQUE:-
 4  5  0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:6

DEQUE:-
 6  4  5  0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:7

DEQUE:-
 7  6  4  5  0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:8

DEQUE:-
 8  7  6  4  5  0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:9

DEQUE:-
 9  8  7  6  4  5  0  3  2  1

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:10

OVERFLOW!!!

DEQUE:-
 10

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:11

DEQUE:-
 11  10

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:12

DEQUE:-
 12  11  10

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:15

DEQUE:-
 15  12  11  10

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:15

DEQUE:-
 15  15  12  11  10

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Element deleted:15
DEQUE:-
 15  12  11  10

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:3

Element deleted:10
DEQUE:-
 15  12  11

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Element deleted:15
DEQUE:-
 12  11

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:3

Element deleted:11
DEQUE:-
 12

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Element deleted:12
UNDERFLOW

DEQUE:-
 0

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:4

UNDERFLOW

DEQUE:-
 0

*************** INPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Delete at Left
3. Delete at Right
4. Display
5. EXIT


Enter your choice:5

INVALID INPUT

--------------------------------
Process exited after 86.05 seconds with return value 0
Press any key to continue . . .

*************** MAIN MENU ***************

1. Input Restricted Deque
2. Output Restricted Deque


Enter your choice:2

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:512

DEQUE:-
 512

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Enter the value for insertion:1999

DEQUE:-
 512  1999

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:15

DEQUE:-
 15  512  1999

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:28

DEQUE:-
 28  15  512  1999

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Enter the value for insertion:4

DEQUE:-
 28  15  512  1999  4

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Enter the value for insertion:26

DEQUE:-
 28  15  512  1999  4  26

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Enter the value for insertion:27

DEQUE:-
 28  15  512  1999  4  26  27

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:29

DEQUE:-
 29  28  15  512  1999  4  26  27

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Enter the value for insertion:1972

DEQUE:-
 29  28  15  512  1999  4  26  27  1972

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:55

DEQUE:-
 55  29  28  15  512  1999  4  26  27  1972

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:2

Enter the value for insertion:55

OVERFLOW!!!

DEQUE:-
 55

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:3

Element deleted:55
UNDERFLOW

DEQUE:-
 0

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:55

DEQUE:-
 55

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:1

Enter the value for insertion:44

DEQUE:-
 44  55

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:3

Element deleted:55
DEQUE:-
 44

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:3

Element deleted:44
UNDERFLOW

DEQUE:-
 0

*************** OUTPUT RESTRICTED DEQUE ***************

1. Insert at Left
2. Insert at Right
3. Delete at Right
4. Display
5. EXIT


Enter your choice:5

INVALID INPUT

--------------------------------
Process exited after 143.1 seconds with return value 0
Press any key to continue . . .
*/
