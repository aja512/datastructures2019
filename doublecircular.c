#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
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
		do
		{
			printf("Node =\t%d\t",ptr->data);
			ptr=ptr->next;
		}
		while(ptr!=start);
	}
}
struct node *create(struct node *start)
{
	struct node *newnode,*last;  /*Last Pointer points to previous node*/
	int i,n;
	printf("Enter no. of nodes:\n");
	scanf("%d",&n);
	newnode=getnode();        /*Create a new node.*/
	newnode->prev=NULL;
	start=newnode;          /*Assign newnode address to start*/
	last=start;             /*Last is initialized to start*/
	for(i=0;i<n;i++)
	{
		printf("Enter value of Node %d: ",i+1);
		scanf("%d",&(newnode->data));
		if(i<(n-1))
		/*Check whether no of nodes to create is less than no.of nodes-1 as we have already created one node and we have to create n-1 nodes*/
        {
            newnode->next=getnode();
			newnode->prev=last;    //linking newnode with the previous node i.e back linking
			newnode=newnode->next;
            last->next=newnode;    //linking previous node to newnode i.e forward link 
            last=newnode;
        }
	}
	newnode->next=start;       /*Last node next part holds the address of start*/
	start->prev=newnode;       /*Previous part of 1st node is linked with the last node*/
	display(start);
	return(start);
	
}
void insert_beg()
{
	struct node *newnode,*ptr;
	int x;
	printf("Enter data:\n");
	scanf("%d",&x);
	newnode=getnode();    /*Calling getnode & creating a newnode*/
	newnode->data=x;      /*Assigning data of newnode to user entered value*/
	start->prev=newnode;    /*linking newnode with the 1st node i.e back linking*/
	newnode->next=start;    /*linking 1st node to newnode i.e forward link */
	ptr=start;              /*Assigning address of start to temporary pointer*/
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	newnode->prev=ptr;   /*linking newnode with the last node i.e back linking*/
	ptr->next=newnode;    /*linking last node to newnode i.e forward link */
	start=newnode;        /*Making the newnode as 1st node*/
	display(start);
}
void insert_end()
{
	struct node *newnode,*ptr;
	int x;
	printf("Enter data:\n");
	scanf("%d",&x);
	newnode=getnode();        /*Calling getnode & creating a newnode*/
	newnode->data=x;          /*Assigning data of newnode to user entered value*/
	ptr=start;                /*Assigning the address of start to temporary pointer*/
	while((ptr->next)!=start)   /*Traverse through the list till while condition is true.*/
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;    /*linking last node to newnode i.e back linking */
	newnode->prev=ptr;   /*linking newnode with the last node i.e forward linking*/
	newnode->next=start;   /*linking 1st node to newnode(last node) i.e forward link */
	start->prev=newnode;    /*linking newnode(last node) with the 1st node i.e back linking*/
	display(start);
}
void delete_beg()
{
	struct node *ptr;
	ptr=start;              /*Assigning the address of start to temporary pointer*/ 
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while((ptr->next)==start)   /*Traverse through the list till while condition is true.*/
		{
			ptr=ptr->next;
		}
		ptr->next=start->next;       /*Point the address of 2nd node to last node.*/
		start=start->next;           /*Move start to 2nd node.*/
		start->prev=ptr;             /*Point previous part of start to last node.*/
		free(ptr);
		display(start);
	}
}
void delete_end()
{
	struct node *ptr;
	ptr=start;             /*Assigning the address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while((ptr->next)!=start)   /*Traverse through the list till while condition is true.*/
		{
			ptr=ptr->next;
		}
		start->prev=ptr;  /*Point previous part of start to 2nd last node.*/
		ptr->next=start;  /*Point 2nd last node to start*/
		free(ptr);
		display(start);
	}
}
void search_node()
{
	struct node *ptr;
	int count=1;     /*Initialize count to 1*/
	ptr=start;      /*Assigning the address of start to temporary pointer*/
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
	ptr=start;         /*Assigning the address of start to temporary pointer*/
	preptr=ptr;        /*Assigning the address of pointer to  another temporary pointer*/
	if(ptr==NULL)
	printf("\nList is empty.Create one!!\n");
	else
	{
		for(jump=1;jump<loc;jump++)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		newnode->next=ptr;
		ptr->prev=newnode;
		newnode->prev=preptr;
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
	ptr=start;  /*Assigning the address of start to temporary pointer*/
	preptr=ptr;   /*Assigning the address of pointer to another temporary pointer*/
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
		ptr->next->prev=preptr;
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
	ptr=start;          /*Assigning the address of start to temporary pointer*/
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
			preptr=ptr;
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
			start2->prev=ptr;
			preptr=preptr->next;
			preptr->next=start;
			start->prev=preptr;
		}
		display(start);
		display(start2);
	}
}
void copy()
{
	struct node *newnode, *start2, *ptr,*preptr;
    start2=NULL;
    ptr=start;     /*Assigning the address of start to temporary pointer*/
    if (ptr==NULL)
        printf("The list does not exist. Please create one.\n");
    else
    {
        ptr=start;
        do
        {
            newnode=getnode();        /*Create a new node*/
            newnode->data=ptr->data;   /*Assign data of 1st node of original list to 1st node of copy list.*/
            if(start2==NULL)
            {
            	start2=newnode;        /*Assign start2 the address of newly created node.*/
                preptr=start2;         /*Assigning the address of start2 to temporary pointer preptr*/
            }
            else
            {
              preptr->next=newnode;    /*Assign the next part of preptr to newnode*/
              newnode->prev=preptr;
              preptr=preptr->next;      /*Move the preptr to newnode.*/
            }
         	ptr=ptr->next;              /*Move pointer to the next value of the original list*/
       }
       while(ptr!=start);
       preptr->next=start2;             /*Assign last node of copy list the start2 address.*/
		start2->prev=preptr;
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
	start1=create(start);   /*start1 will hold 1st list*/
	start2=create(start);   /*start2 will hold 2nd list*/
	preptr=start1;          /*Assigning the address of start1 to temporary pointer ptr*/
	ptr=start2;             /*Assigning the address of start2 to temporary pointer preptr*/
	while(preptr->next!=start1)
		preptr=preptr->next;    /*Traverse through the 1st list.*/
	preptr->next=start2;        /*Last node of 1st list will point to the 2nd start pointer*/
	while(ptr->next!=start2)    /*Traverse through the 2nd list.*/
		ptr=ptr->next;
	ptr->next=start1;        /*Link last node of 2nd list to 1st start pointer.*/
	start1->prev=ptr;
	display(start1);		
}
void count()
{
	struct node *ptr;
	int count=1;            /*Initialize count to 1.*/
	ptr=start;
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while(ptr->next!=start)
		{
			count++;         /*Increment count by 1 everytime we go in while condition */
			ptr=ptr->next;
		}
		printf("Count:%d",count);
	}
}
void reverse(struct node *start)
{
	struct node *newnode, *start2,*ptr;
    ptr=start;
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
        ptr=start2;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=start2;
        printf("\nOriginal list\n");
        display(start);
        printf("\nReversed list\n");
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
2
Enter data:
11
List:
Node =  11      Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Do you wish to continue?
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
Node =  11      Node =  1       Node =  2       Node =  3       Node =  4       Node =  5      
Reversed list
List:
Node =  5       Node =  4       Node =  3       Node =  2       Node =  1       Node =  11
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
14
Original list
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       
Copied list
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5

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
3
Enter data:
45
List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Node =  45  
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
8
Enter value to be searched:
3
Value 3 is at 3List:
Node =  1       Node =  2       Node =  3       Node =  4       Node =  5       Node =  45      Do you wish to continue?
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
Count:6Do you wish to continue?
Press 1 for Yes & 0 for no
1
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
12
Enter the location for splitting:
3
List:
Node =  1       Node =  2       List:
Node =  3       Node =  4       Node =  5       Node =  45      Do you wish to continue?
Press 1 for Yes & 0 for no
13


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
3
Enter value of Node 1: 5
Enter value of Node 2: 12
Enter value of Node 3: 1999
List:
Node =  5       Node =  12      Node =  1999    List:
Node =  1       Node =  2       Node =  3       Node =  5       Node =  12      Node =  1999    Do you wish to continue?
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
3
Enter value of Node 1: 1
Enter value of Node 2: 2
Enter value of Node 3: 3
List:
Node =  1       Node =  2       Node =  3       Do you wish to continue?
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
Node =  1       Node =  2
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
Node =  1       Node =  2       Node =  3       Do you wish to continue?
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
4
Enter the data & location for insertion:
51
2
List:
Node =  1       Node =  51      Node =  2       Node =  3       Do you wish to continue?
Press 1 for Yes & 0 for no
0

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
7
Enter the location for deletion:
3
List:
Node =  1       Node =  2       Node =  4       Node =  5       Do you wish to continue?
Press 1 for Yes & 0 for no
*/
