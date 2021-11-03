/*
Amanda Judy Andrade
SE-IT 2
Practical 12
Write a program to generate an expression tree from given postfix expression
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 50

struct node
{
	char value;
	struct node *left;
	struct node *right,*prev;
}*cur,*par,*root=NULL;

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);       		//Go to left subtree
        printf("%c ", root->value);    //Printf root->data
        inorder(root->right);      	   //Go to right subtree
    }
}
void preorder(struct node *root)
{
	if(root!=NULL)
    {
        printf("%c ",root->value);    //Printf root->data
        preorder(root->left);    //Go to left subtree
        preorder(root->right);     //Go to right subtree
    }
}
void postorder(struct node *root)
{
	if(root!=NULL)
    {
        postorder(root->left);    //Go to left sub tree
        postorder(root->right);     //Go to right sub tree
        printf("%c ",root->value);    //Printf root->data
    }	
}
void main()
{
	char a[size];
	int len,i;
	struct node *new_node;
	printf("Enter Postfix Expression:\n");
	scanf("%s",a);
	len=strlen(a);
	for(i=len-1;i>=0;i--)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
   		new_node->value=a[i];
   		new_node->left=new_node->right=new_node->prev=NULL;
   		if(root==NULL)
  		{
		    root=new_node;
		    cur=par=root;
		}
		else
   		{
		    if(a[i]=='+' ||a[i]=='-' ||a[i]=='*'||a[i]=='/'||a[i]=='%')
		    {
			    if(par->right==NULL)
			    {
				    cur=new_node;
				    par->right=cur;
				    cur->prev=par;
				    par=cur;
			    }
		     	else if(par->left==NULL)
		     	{
		      		cur=new_node;
		      		par->left=cur;
		      		cur->prev=par;
		      		par=cur;
		     	}
		    	else
		    	{
		     		while(par->left!=NULL)
		     		{
		      			par=par->prev;
		     		}
		     		cur=new_node;
		     		par->left=cur;
		     		cur->prev=par;
		     		par=cur;
		    	}
		   }
		   else
		   {
		    	if(par->right==NULL)
		    	{
		     		cur=new_node;
				    par->right=cur;
				    cur->prev=par;
		    	}
		    	else if(par->left==NULL)
		    	{
		     		cur=new_node;
		     		par->left=cur;
		     		cur->prev=par;
		    	}
		    	else
		    	{
		     		while(par->left!=NULL)
		     		{
		      			par=par->prev;
		     		}
		     		cur=new_node;
		    		par->left=cur;
		     		cur->prev=par;
		    	}
   			}	
  		}
 	}
 	printf("\nInorder Traversal:\n");
 	inorder(root);
	printf("\n\nPreorder Traversal:\n");
 	preorder(root);
 	printf("\n\nPostorder Traversal:\n");
 	postorder(root);
}
/*
OUTPUT:-
Enter Postfix Expression:
123/456*%7/+8*-

Inorder Traversal:
1 - 2 / 3 + 4 % 5 * 6 / 7 * 8

Preorder Traversal:
- 1 * + / 2 3 / % 4 * 5 6 7 8

Postorder Traversal:
1 2 3 / 4 5 6 * % 7 / + 8 * -
--------------------------------
Process exited after 26.34 seconds with return value 2
Press any key to continue . . .
*/


