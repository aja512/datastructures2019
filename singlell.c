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
void reverse(struct node *);
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
		printf("Do you wish to continue?\nPress 1 for Yes & 0 for No\n");
		scanf("%d",&p);
	 }
	 while(p!=0);
	 return 0;
}

void display(struct node *start)
{
	struct node *ptr;
	ptr=start;        /*Assigning address of start to temporary pointer*/
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
struct node *create(struct node *start)
{
	struct node *newnode;
	int i,n;
	printf("Enter no. of nodes:\n");
	scanf("%d",&n);
	newnode=getnode();
	start=newnode;
	for(i=0;i<n;i++)
	{
		printf("Enter value of Node %d: ",i+1);
		scanf("%d",&(newnode->data));
		if(i<(n-1))//Check whether no of nodes to create is less than no.of nodes-1 as we have already created one node and we have to create n-1 nodes
        {
            newnode->next=getnode();
            newnode=newnode->next;
        }
	}
	if(i<(n-1))
	newnode->next=NULL;
	return(start);
	display(start);
}
void insert_beg()
{
	struct node *newnode;
	int x;
	printf("Enter data:\n");
	scanf("%d",&x);
	newnode=getnode();
	newnode->data=x;
	newnode->next=start;
	start=newnode;       /*Making the newnode as 1st node*/
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
	newnode->next=NULL;
	ptr=start;               /*Assigning address of start to temporary pointer*/
	while((ptr->next)!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	display(start);
}
void delete_beg()
{
	struct node *ptr;
	ptr=start;       /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		printf("Element %d deleted",ptr->data);
		start=ptr->next;
		free(ptr);
		display(start);
	}
}
void delete_end()
{
	struct node *ptr,*preptr;
	ptr=start;      /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while((ptr->next)!=NULL)
		{
			preptr=ptr;    /*Assigning address of pointer to another temporary pointer*/
			ptr=ptr->next;
		}
		preptr->next=NULL;
		free(ptr);
		display(start);
	}
}
void search_node()
{
	struct node *ptr;
	int count=1;
	ptr=start;   /*Assigning address of start to temporary pointer*/
	int val;
	printf("Enter value to be searched:\n");
	scanf("%d",&val);
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while(ptr!=NULL)
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
	struct node *newnode,*ptr,*preptr;
	int x,loc;
	printf("Enter data and location:\n");
	scanf("%d%d",&x,&loc);	
	newnode=getnode();
	newnode->data=x;
	ptr=start;     /*Assigning address of start to temporary pointer*/
	preptr=ptr;    /*Assigning address of pointer to another temporary pointer*/
	while(preptr->data!=loc)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	display(start);
	
}
void delete_node()
{
	struct node *ptr,*preptr;
	int val;
	printf("Enter value to be searched:\n");
	scanf("%d",&val);
	ptr=start;      /*Assigning address of start to temporary pointer*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	if(ptr->data==val)
	{
		delete_beg(start);
	}
	else
	{
		while(ptr->data!=val)
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
	struct node *ptr,*start2=NULL;
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
			if(ptr->next==NULL)
			{
				printf("List is Shorter\n");
				break;
			}
			ptr=ptr->next;
		}
		if(jump==loc-1)
		{
			start2=ptr->next;
			ptr->next=NULL;
		}
		display(start);
		display(start2);
	}
}
void copy()
{
	struct node *newnode,*ptr,*preptr,*start2=NULL;
	ptr=start;     /*Assigning address of start to temporary pointer.*/
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while(ptr!=NULL)
		{
			newnode=getnode();      /*Call getnode and return a newly created node.*/
			newnode->data=ptr->data;  /*Assign ptr's data to newnode.*/
			newnode->next=ptr->next;  /* Assign the address of next node in original to copy.*/
			if(start2==NULL)
			start2=newnode; /*For 1st node of copy list.*/
			else
			{
				preptr=start2;  /*Assigning address of start to temporary pointer*/
				while(preptr->next!=NULL)
					preptr=preptr->next;  /*Traverse through the list.*/
			}
			ptr=ptr->next;
		}
		display(start);
		display(start2);
	}
}
 void merge_node()
{
	struct node *ptr,*preptr,*start2=NULL;
	struct node *holder1=NULL;
	struct node *holder2=NULL;
	start2=create(start);
	ptr=start;
	preptr=start2;
	while((ptr!=NULL)&&(preptr!=NULL))
	{
		holder1=ptr->next;   //making the 1st node of 1st linked list point to 1st node of 2nd linked list
		ptr->next=preptr;
		if(holder1!=NULL)
		{
			holder2=preptr->next;  //making the 1st node of 2nd linked list point to 2nd node of 1st linked list
			preptr->next=holder1;
		}
		ptr=holder1;
		preptr=holder2;
		//Updating the address location of 2 pointers.
	}
	display(start);
}
void count()
{
	struct node *ptr;
	int count=0;
	ptr=start;    /*Assigning address of start to temporary pointer*/s
	if(ptr==NULL)
	printf("List doesn't exist!!Please create one!!!\n");
	else
	{
		while(ptr!=NULL)
		{
			count++;
			ptr=ptr->next;
		}
		printf("Count:%d",count);

	}
}
void reverse(struct node *start)
{
	struct node *temp, *start2, *newnode;
	temp=start;   /*Assigning address of start to temporary pointer*/
	start2=NULL;
 	if(temp==NULL)
        {
	   printf("Empty list");
	}	
   	else
    	{
        	while(temp!=NULL)
        	{
        	    newnode=getnode();
		    newnode->data=temp->data;
		    newnode->next=start2;
		    start2=newnode;
		    temp=temp->next;
        	}
        }
	display(start);
        printf("\nSUCCESSFULLY REVERSED LIST\n");
        display(start2);
 
    
}
/*
O/P:
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
1
List:
Node =  1       Do you wish to continue?
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
2
Value 2 is at 2
dbit@library-26:~$ cd /home/dbit/Desktop
dbit@library-26:~/Desktop$ gcc singlell.c -o singlellout
dbit@library-26:~/Desktop$ ./singlellout


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
2
Enter data:
11
List:
Node =	11	Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Do you wish to continue?
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
Node =	11	Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	Node =	45	Do you wish to continue?
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
1
List:
Node =	1	Do you wish to continue?
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
Enter value of Node 1: 11
Enter value of Node 2: 22
Enter value of Node 3: 33
Enter value of Node 4: 44
Enter value of Node 5: 55
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
5
Element 11 deletedList:
Node =	22	Node =	33	Node =	44	Node =	55	Do you wish to continue?
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
Node =	22	Node =	33	Node =	44	Do you wish to continue?
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
11
Count:5Do you wish to continue?
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
7
Enter value to be searched:
3
List:
Node =	1	Node =	2	Node =	4	Node =	5	Do you wish to continue?
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
2
List:
Node =	1	Do you wish to continue?
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
13
Enter no. of nodes:
5
Enter value of Node 1: 22
Enter value of Node 2: 33
Enter value of Node 3: 74
Enter value of Node 4: 45
Enter value of Node 5: 89
List:
Node =	1	Node =	22	Node =	33	Node =	74	Node =	45	Node =	89	Do you wish to continue?
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
4
Enter data and location:
44
3
List:
Node =  1       Node =  2       Node =  3       Node =  44      Node =  4       Node =  5
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
14
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	List:
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
List:
Node =	1	Node =	2	Node =	3	Node =	4	Node =	5	SUCCESSFULLY REVERSED LIST
List:
Node =	5	Node =	4	Node =	3	Node =	2	Node =	1	Do you wish to continue?
Press 1 for Yes & 0 for no


*/
