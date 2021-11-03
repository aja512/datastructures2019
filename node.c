/* DSA Practical 1
Amanda Judy Andrade
SYBE IT 2
*/


#include<stdio.h>
int a[10];
void insert(int loc,int val,int n);
void delete(int loc,int n);
void traverse(int n);
void search(int val,int n);

int main ()
{
	int loc,val,n,i,ch;
	
	printf("Enter no of elements:\n");//Enter  number of array elements
	scanf("%d",&n);
	printf("Enter elements:\n");//Enter array elements
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	label1:
	do//To repeat the loop continuously so that the user can execute multiple tasks
	{
		printf("\n* MENU * \n1.Insert\n2.Delete\n3.Traverse\n4.Search\n0.Exit\n\nPlease enter your choice\n");//display menu
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter location and value:\n");//Ask the user to enter position and value for the position he/she entered
				   scanf("%d%d",&loc,&val);
				   insert(loc,val,n);
			       break;
			case 2:printf("Enter location:\n");//Ask the user to enter position and value for the position he/she entered
			      scanf("%d",&loc);
			      delete(loc,n);
			      break;
			case 3:traverse(n);
			      break;
			case 4:printf("Enter value:\n");//Ask the user to enter position and value for the position he/she entered
			      scanf("%d",&val);
			      search(val,n);
			      break;
			case 0:printf("Do you wish to continue ? Press 1 or 0");
			      if(1)
			      exit(0);
			      else goto label1;
			      break;
			default:if(ch>1 && ch<=5)
			       printf("Invalid Input");
			       break;                        
			
		}
	}
	while(ch!=0);		
}
void insert(int loc,int val,int n)
{
	int i;
	if(loc>n)
	printf("Insertion not possible !!");
	else
	{
		for(i=n-1;i>=loc-1;i--)//Insert user entered value
		{
			a[i+1]=a[i];
		}	
		a[loc-1]=val;
	}
	printf("Resultant Array :\n");//Print array
	for(i=0;i<=n;i++)
	{
		printf("%d  ",a[i]);
	}
}
void delete(int loc,int n)
{
	int i;
	if(loc>n)
	printf("Deletion not possible !!");
	else
	for(i=loc-1;i<n-1;i++)//  To Delete elements at given position
	{
		a[i]=a[i+1];
	}
	printf("Resultant Array :\n");//Print the array
	for(i=0;i<n-1;i++)
	{
		printf("%d  ",a[i]);
	}			
}
void traverse(int n)
{
	int i;
	printf("Resultant Array :\n");//Print the array
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}			
}
void search(int val,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
		printf("%d is present at location %d",val,i+1);//To check whether the user entered value is present in array or not
		break;
	}
	if(a[i]!=val&&i==n)
	printf("%d is not present in the array",val);
}
/*
O/P:
Enter no of elements:
5
Enter elements:
1
2
3
4
5

Enter no of elements:
5
Enter elements:
1
2
3
4
5

* MENU *
1.Insert
2.Delete
3.Traverse
4.Search
0.Exit

Please enter your choice
1
Enter location and value:
100
10
Insertion not possible !!Resultant Array :
1  2  3  4  5  0
* MENU *
1.Insert
2.Delete
3.Traverse
4.Search
0.Exit

Please enter your choice
2
Enter location:
2
Resultant Array :
1  3  4  5
* MENU *
1.Insert
2.Delete
3.Traverse
4.Search
0.Exit

Please enter your choice
2
Enter location:
6
Deletion not possible !!Resultant Array :
1  3  4  5
Enter no of elements:
5
Enter elements:
1
2
3
4
5

* MENU *
1.Insert
2.Delete
3.Traverse
4.Search
0.Exit

Please enter your choice
4
Enter value:
4
4 is present at location 4
* MENU *
1.Insert
2.Delete
3.Traverse
4.Search
0.Exit

Please enter your choice
4
Enter value:
54
54 is not present in the array

* MENU *
1.Insert
2.Delete
3.Traverse
4.Search
0.Exit

Please enter your choice
0
Do you wish to continue ? Press 1 or 0
--------------------------------
Process exited after 91.2 seconds with return value 0
Press any key to continue . . .
*/
