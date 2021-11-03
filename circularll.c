#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *getnode(void);
void display(struct node*);
struct node *create();
void insert_beg( );
void insert_end( );
void delete_beg( );
void delete_end( );
void search_node( );
void insert_loc( );
void delete_node( );
void split_node( );
void copy( );
void reverse( );
void count( );
void merge_node( );

struct node *getnode(void)
{
	return ((struct node*)malloc(sizeof(struct node)));
}

int main()
{
	 int ch,p;

	 do
	 {
	 	printf("\n\n MENU \n\n1.Create a List\n2.Insert at Beginning\n3.Insert at end\n4.Insert at location\n5.Delete at beginning\n6.Delete at end\n7.Delete at location\n8.Search\n9.Display\n10.Reverse\n11.Count\n12.Split\n13.Merge\n14.Copy\n15.Exit\n\n");
	 	printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:start=create();
					break;
			case 2:insert_beg();
					break;
			case 3:insert_end();
					break;
			case 4:insert_loc();
					break;
			case 5:delete_beg();
					break;
			case 6:delete_end();
					break;
			case 7:delete_node();
					break;
			case 8:search_node();
					break;
			case 9:display(start);
					break;
			case 10:reverse(start);
					break;
			case 11:count();
					break;
			case 12:split_node();
					break;
			case 13:merge_node();
					break;
			case 14:copy();
					break;
			case 15:exit(0);
					break;
			default:printf("Invalid Input!!!\n");
					break;

		}
		printf("Do you wish to continue?\nPress 1 for Yes & 0 for no\n");
		scanf("%d",&p);
	 }
	 while(p!=0);
	 return 0;
}

void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		printf("List:\n");
		while(ptr->next!=start)
		{
			printf("Node =\t%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("Node =\t%d\t",ptr->data);
	}
}
struct node *create(struct node *start)
{
	struct node *newnode;  /*Last Pointer points to previous node*/
	int i,n;
	printf("Enter no. of nodes:\n");
	scanf("%d",&n);
	newnode=getnode();
	start=newnode;    /*Assign newnode address to start*/
	for(i=0;i<n;i++)
	{
		printf("Enter value of Node %d: ",i+1);
		scanf("%d",&(newnode->data));
		if(i<(n-1))/*Check whether no of nodes to create is less than no.of nodes-1 as we have already created one node and we have to create n-1 nodes*/
        {
            newnode->next=getnode();
            newnode=newnode->next;
        }
	}
	newnode->next=start;
	display(start);
	return(start);
	
}
void insert_beg()
{
	struct node *newnode,*ptr;
	int x;
	printf("Enter data:\n");
	scanf("%d",&x);
	newnode=getnode();
	newnode->data=x;
	newnode->next=start;
	ptr=start;                 /*Assigning address of start to temporary pointer*/
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	start=newnode;
	ptr->next=start;
	display(start);
}
void insert_end()
{
	struct node *newnode,*ptr;
	int x;
	printf("Enter data:\n");
	scanf("%d",&x);
	newnode=getnode();
	newnode->data=x;
	ptr=start;                /*Assigning address of start to temporary pointer*/
	while((ptr->next)!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=start;
	display(start);
}
void delete_beg()
{
	struct node *ptr;
	ptr=start;            /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while((ptr->next)==start)
		{
			ptr=ptr->next;
		}
		ptr->next=start->next;
		start=ptr->next;
		free(ptr);
	}
	display(start);
}
void delete_end()
{
	struct node *ptr,*preptr;
	ptr=start;               /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while((ptr->next)!=start)
		{
			preptr=ptr;        /*Assigning address of pointer to another temporary pointer*/
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		display(start);
	}
}
void search_node()
{
	struct node *ptr;
	int count=1;
	ptr=start;      /*Assigning address of start to temporary pointer*/
	int val;
	printf("Enter value to be searched:\n");
	scanf("%d",&val);
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while(ptr->next!=start)
		{
			count++;
			ptr=ptr->next;
			if((ptr->data)==val)
			printf("Value %d is at %d",val,count);
		}
		display(start);
	}
}
void insert_loc()
{
	struct node *ptr,*preptr,*newnode;
	int loc,val,jump;
	printf("Enter the data & location for insertion:\n");
	scanf("%d%d",&val,&loc);
	newnode=getnode();
	newnode->data=val;
	ptr=start;      /*Assigning address of start to temporary pointer*/
	preptr=ptr;     /*Assigning address of pointer to another temporary pointer*/
	if(ptr==NULL)
	printf("\nList is empty.Create one!!\n");
	else
	{
		for(jump=1;jump<loc;jump++)
		{
			preptr=ptr;      /*Assigning address of pointer to another temporary pointer*/
			ptr=ptr->next;
		}
		newnode->next=ptr;
		preptr->next=newnode;
		display(start);
	}	
}
void delete_node()
{
	struct node *ptr,*preptr;
	int loc,jump;
	printf("Enter the location for deletion:\n");
	scanf("%d",&loc);
	ptr=start;               /*Assigning address of start to temporary pointer*/
	preptr=ptr;              /*Assigning address of ptr to another temporary pointer*/
	if(ptr==NULL)
	printf("\nList is empty.Create one!!\n");
	else
	{
		for(jump=1;jump<loc;jump++)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		display(start);
	}	
}
void split_node()
{
	struct node *ptr,*preptr,*start2=NULL;
	int loc,jump;
	printf("Enter the location for splitting:\n");
	scanf("%d",&loc);
	ptr=start;     /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		for(jump=1;jump<=loc-2;jump++)
		{
			if(ptr->next==start)
			{
				printf("List is Shorter\n");
				break;
			}
			preptr=ptr;            /*Assigning address of ptr to another temporary pointer*/
			ptr=ptr->next;
		}
		if(jump==loc-1)
		{
			start2=ptr->next;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=start2;
			preptr=preptr->next;
			preptr->next=start;
		}
		display(start);
		display(start2);
	}
}
void copy()
{
	struct node *newnode, *start2, *ptr,*preptr;
    start2=NULL;
    ptr=start;           /*Assigning address of start to temporary pointer*/
    if (ptr==NULL)
        printf("The list does not exist. Please create one.\n");
    else
    {
        ptr=start;        /*Assigning address of start to temporary pointer*/
        do
        {
            newnode=getnode();
            newnode->data=ptr->data;
            if(start2==NULL)
            {
            	start2=newnode;   /*Assigning start2 the address of newly created node.*/
                preptr=start2;   /*Assigning address of start to temporary pointer*/
            }
            else
            {
              preptr->next=newnode;
              preptr=preptr->next;
            }
         	ptr=ptr->next;
       }
       while(ptr!=start);
       preptr->next=start2;
       printf("Original list \n");
       display(start);
       printf("Copied list \n");
       display(start2);	
	}
}
 void merge_node()
{
	struct node *ptr,*preptr,*start1,*start2;
	start1=NULL;
	start2=NULL;
	start1=create(start);
	start2=create(start);
	preptr=start1;        /*Assigning address of start to temporary pointer*/
	ptr=start2;          /*Assigning address of start to temporary pointer*/
	while(preptr->next!=start1)
		preptr=preptr->next;
	preptr->next=start2;
	while(ptr->next!=start2)
		ptr=ptr->next;
	ptr->next=start1;
	display(start1);		
}
void count()
{
	struct node *ptr;
	int count=1;
	ptr=start;          /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while(ptr->next!=start)
		{
			count++;
			ptr=ptr->next;
		}
		printf("Count:%d",count);
	}
}
void reverse(struct node *start)
{
	struct node *newnode, *start2,*ptr;
	ptr=start;          /*Assigning address of start to temporary pointer*/
	start2=NULL;
	if(ptr==NULL)
        printf("The list does not exist. Please create one.\n");
	else
	{
	    do
		{
		   newnode=getnode();
		   newnode->data=ptr->data;
		   newnode->next=start2;
		   start2=newnode;
		   ptr=ptr->next;
		}
		while(ptr!=start);
		
		ptr=start2;    /*Assigning address of start to temporary pointer*/
		while(ptr->next!=NULL)
		    ptr=ptr->next;
		ptr->next=start2;
		
		printf("Original list\n");
		display(start);
		
		printf("Reversed list\n");
		display(start2);
		
	}
	
}
/*
O/P:-
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
9
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5  
dbit@it7-50:~/Desktop$ gcc circularll.c
dbit@it7-50:~/Desktop$ ./a.out


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
3
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
List:
Node =	1	Node =	2	Node =	3	Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
2
Enter data:
11
List:
Node =	11	Node =	1	Node =	2	Node =	3	Do you wish to continue?
Press 1 for Yes & 0 for no
1
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
5
List:
Node =  2       Node =  3       Node =  4       Node =  5


dbit@it7-50:~/Desktop$ gcc circularll.c
dbit@it7-50:~/Desktop$ ./a.out


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
3
Enter data:
11
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Node =	11	Do you wish to continue?
Press 1 for Yes & 0 for no

 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
6
List:
Node =  1       Node =  2       Node =  3       Node =  4       Do you wish to continue?
Press 1 for Yes & 0 for no
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
7
Enter the location for deletion:
3
List:
Node =  1       Node =  2       Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
1
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
8
Enter value to be searched:
2
Value 2 is at 2List:
Node =  1       Node =  2       Node =  3       Node =  4       Do you wish to continue?
Press 1 for Yes & 0 for no
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
11
Count:5
MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 34
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =  1       Node =  2       Node =  34      Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
12
Enter the location for splitting:
3
List:
Node =  1       Node =  2       List:
Node =  34      Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
 MENU

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
13
Enter no. of nodes:
3
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
List:
Node =  1       Node =  2       Node =  3       Enter no. of nodes:
2
Enter value of Node 1: 111
Enter value of Node 2: 222
List:
Node =  111     Node =  222     List:
Node =  1       Node =  2       Node =  3       Node =  111     Node =  222     Do you wish to continue?
Press 1 for Yes & 0 for no
dbit@it6-44:~/Desktop$ gcc circularll.c
dbit@it6-44:~/Desktop$ ./a.out


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
14
Original list 
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Copied list 
List:
Node =	1	Node =	2	Node =	3	Node =	4	Do you wish to continue?
Press 1 for Yes & 0 for no
dbit@it6-44:~/Desktop$ gcc circularll.c
dbit@it6-44:~/Desktop$ ./a.out


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
1
Enter no. of nodes:
5
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
Enter value of Node 4: 4
Enter value of Node 5: 5
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Do you wish to continue?
Press 1 for Yes & 0 for no
1


 MENU 

1.Create a List
2.Insert at Beginning
3.Insert at end
4.Insert at location
5.Delete at beginning
6.Delete at end
7.Delete at location
8.Search
9.Display
10.Reverse
11.Count
12.Split
13.Merge
14.Copy
15.Exit

Enter your choice:
10
Original list
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Reversed list
List:
Node =	5	Node =	4	Node =	3	Node =	2	Node =	1	Do you wish to continue?
Press 1 for Yes & 0 for no

*/
