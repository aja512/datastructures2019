/*
Amanda Judy Andrade
SE-IT 2
Practical 11
Write a menu driven program to implement BST  and perform the following operations
1.Insert a node
2.Preorder Traversal
3.Postorder Traversal
4.Inorder Traversal
5.Height og the tree
6.Total no of nodes
7.No of internal nodes
8.No of external nodes
9.Successor Node
10.Predecessor Node
11.Tree Maximum
12.Tree Minimum
13.Search
14.Delete Node
15.Delete Tree
16.Level ordr Traversal
17.Level/Height of a given node 
*/
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *left, *right;
};
struct node *root=NULL;
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
	if(root!=NULL)
    {
        printf("%d ",root->key);    //Printf root->data
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
        printf("%d ",root->key);    //Printf root->data
    }	
}
void prt_levelorder(struct node *root)
{
		int h=height(root);
		int i;
		for(i=0;i<=h;i++)
		{
			prt_givenNode(root,i+1);
		}
}
void prt_givenNode(struct node *root,int level)
{
	if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->key); 
    else if (level >1) 
    { 
        prt_givenNode(root->left,level-1); 
        prt_givenNode(root->right,level-1); 
    } 
}
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 	if(node==NULL)
 	{
 		printf("\nTree is Empty!!!");
 		return;
 	}
    /* loop down to find the leftmost leaf */
    else
    {
	    while (current->left != NULL)
	        current = current->left;
	 	printf("\nMinima:%d\n",current->key);
	    return current;
	}
}
struct node *tree_max(struct node *root)
{
	struct node *ptr;
	ptr=root;
	if(root==NULL)
 	{
 		printf("\nTree is Empty!!!");
 		return;
 	}
 	else
 	{
 		while(ptr->right!=NULL)
 		{
 			ptr=ptr->right;
 		}
 		printf("\nMaxima:%d\n",ptr->key);
 		return ptr;
 	}
}
struct node *delete_tree(struct node *root)
{
 	if(root==NULL)
 	{
 		printf("\nTree is Empty!!!");
 		return;
 	}
 	else
 	{
 		delete_tree(root->left);
 		delete_tree(root->right);
 		free(root);
 	}
} 
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
struct node *predecessor(struct node *root)
{
	if(root==NULL)
	{
		printf("\nTree is Empty!!!");
 		return;
	}
	else
	{
		return (tree_max(root->left));
	}
}
struct node *successor(struct node *root)
{
	if(root==NULL)
	{
		printf("\nTree is Empty!!!");
 		return;
	}
	else
	{
		return (minValueNode(root->right));
	}
}
int height(struct node *root)
{
	int lh,rh,h;
	if((root==NULL)||((root->left==NULL)&&(root->right==NULL)))
 	{
 		return 0;
 	}
 	else
 	{
 		lh=height(root->left);
 		rh=height(root->right);
 		h=(lh>rh)?lh:rh;
 		return(h+1);
 	}
}
int count_tree(struct node *root)
{
	int count=1;
	struct node *ptr;
	ptr=root;
 	if(ptr==NULL)
 	{
 		printf("\nEMPTY TREE!!\n");
 		return;
	}
	else
	{
		count+=count_tree(ptr->left)+count_tree(ptr->right);
		return count;
	}
}
int count_intern(struct node *root)
{
	if((root==NULL)||((root->left==NULL)&&(root->right==NULL)))
 	{
 		return 0;
 	}
 	else
 	{
 		return(count_intern(root->left)+count_intern(root->right)+1);
 	}	
}
int count_extern(struct node *root)
{
	if(root==NULL)
 	{
 		return 0;
 	}
 	else 
 	if((root->left==NULL)&&(root->right==NULL))
 	{
 		return 1;
 	}
 	else 
 	{
 		return(count_extern(root->left)+count_extern(root->right));
 	}
}
void search(struct node *root,int val)
{
	if(root==NULL)
 	{
 		printf("\nTree is Empty!!!");
 		return;
 	}
 	else
 	if(val==root->key)
 	{
 		printf("\nValue found!!\n");
 	}
 	else
 	if(val<root->key)
 	{
 		search(root->left,val);
 	}
 	else
 	if(val>root->key)
 	{
 		search(root->right,val);
 	}
 	else
 	{
 		printf("\nElement not found!!!\n");
 		return;
 	}
}
/* Helper function for getLevel().  It returns level of the data if data is 
   present in tree, otherwise returns 0.*/
int getLevelUtil(struct node *node, int data, int level) 
{ 
    if (node == NULL) 
        return 0; 
  
    if (node->key == data) 
        return level; 
  
    int downlevel = getLevelUtil(node->left, data, level+1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(node->right, data, level+1); 
    return downlevel; 
} 
  
/* Returns level of given data value */
int getLevel(struct node *node, int data) 
{ 
    return getLevelUtil(node,data,1); 
} 
int main()
{
	int p,val,ch;
	do
	{
		printf("\n*************** MAIN MENU ***************\n");
		printf("\n1.	Insert an Element\n2.	Delete a node\n3.	Inorder Traversal\n4.	Preorder Traversal\n5.	Postorder Traversal\n6.	Levelorder Traversal\n7.	Minimum Value of the tree\n8.	Maximum Value of tree\n9.	Delete the whole tree\n10.	Predecessor of the root\n11.	Successor of The Root Node\n12.	Height of the Tree\n13.	Total no. of Nodes\n14.	Total no. of Internal Nodes\n15.	Total no. of External Nodes\n16.	Search a Node\n17.	Level/Height of the given Node\n18.	EXIT\n");
		printf("Enter your choice:\n");
	 	scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter data for insertion:");
					scanf("%d",&val);
					root=insert(root,val);
					break;
			case 2:printf("\nEnter data for deletion:");
					scanf("%d",&val);
					root=deleteNode(root,val);
					break;
			case 3:printf("Inorder traversal of the given tree:-\n");
    				inorder(root);
    				break;
    		case 4:printf("Preorder traversal of the given tree:-\n");
    				preorder(root);
    				break;
    		case 5:printf("Postorder traversal of the given tree:-\n");
    				postorder(root);
    				break;
    		case 6:printf("\nLevel Order:-\n");
    				prt_levelorder(root);
    				break;
    		case 7:root=minValueNode(root);
    				break;
    		case 8:root=tree_max(root);
    				break;
    		case 9:root=delete_tree(root);
    				break;
    		case 10:root=predecessor(root);
    				break;
    		case 11:root=successor(root);
    				break;
    		case 12:val=height(root);
					printf("\nHeight of the tree:%d\n",val)	;
					break;
			case 13:val=count_tree(root);
					printf("\nTotal of nodes:%d\n",val);
					break;
			case 14:val=count_intern(root);
					printf("\nTotal of Internal nodes:%d\n",val);
					break;
			case 15:val=count_extern(root);
					printf("\nTotal of External nodes:%d\n",val);
					break;
			case 16:printf("\nEnter the node you want to search:");
					scanf("%d",&val);
					search(root,val);
					break;
    		case 17:printf("\nEnter data for insertion:");
					scanf("%d",&val);
					int x=getLevel(root,val);
					if(x)
					{
						printf("\n Level Of %d :%d\n",val,x-1);
						printf("\nHeight of %d:%d\n",val,x);
					}
					else
					printf(" %d is not present in tree \n", val);
					break;	
			case 18:exit(0);
    				break;
    		default:printf("\nINVALID INPUT!!!!\n");
    				break;
		}
		printf("\nDo you wish to continue?\nPress 1 for Yes & 0 for No\n");
		scanf("%d",&p);
	}
	while(p!=0);
	return 0;
}
/*
o/P:-
it1-3@it1-3:~$ cd /home/it1-3/Desktop
it1-3@it1-3:~/Desktop$ gcc bst.c
it1-3@it1-3:~/Desktop$ ./a.out

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:45

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:39

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:54

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:47

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:68

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1 

Enter data for insertion:78

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:80

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
39 45 47 54 68 78 80 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
4
Preorder traversal of the given tree:-
45 39 54 47 68 78 80 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
5
Postorder traversal of the given tree:-
39 47 80 78 68 54 45 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
2

Enter data for deletion:47

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
39 45 54 68 78 80 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
4
Preorder traversal of the given tree:-
45 39 54 68 78 80 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
5
Postorder traversal of the given tree:-
39 80 78 68 54 45 
Do you wish to continue?
Press 1 for Yes & 0 for No
1
*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
6

Minima:39

Do you wish to continue?
Press 1 for Yes & 0 for No
1
*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
6

Minima:39

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
39 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:24

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:45

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
47

INVALID INPUT!!!!

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1 

Enter data for insertion:33

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:54

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1 

Enter data for insertion:68

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
70

INVALID INPUT!!!!

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
1

Enter data for insertion:70

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
24 33 39 45 54 68 70 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
4
Preorder traversal of the given tree:-
39 24 33 45 54 68 70 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
5
Postorder traversal of the given tree:-
33 24 70 68 54 45 39 
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
7

Maxima:70

Do you wish to continue?
Press 1 for Yes & 0 for No
1
*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
13

Total of Internal nodes:4

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
14

Total of External nodes:2

Do you wish to continue?
Press 1 for Yes & 0 for No
15

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
15

Enter the node you want to search:55

Tree is Empty!!!
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.	Insert an Element
2.	Delete a node
3.	Inorder Traversal
4.	Preorder Traversal
5.	Postorder Traversal
6.	Minimum Value of the tree
7.	Maximum Value of tree
8.	Delete the whole tree
9.	Predecessor of the root
10.	Successor of The Root Node
11.	Height of the Tree
12.	Total no. of Nodes
13.	Total no. of Internal Nodes
14.	Total no. of External Nodes
15.	Search a Node
16.	EXIT
Enter your choice:
15

Enter the node you want to search:45

Value found!!

Do you wish to continue?
Press 1 for Yes & 0 for No
*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:45

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:39

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:54

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:78

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:80

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
39 45 54 78 80
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
12

EMPTY TREE!!

EMPTY TREE!!

EMPTY TREE!!

EMPTY TREE!!

EMPTY TREE!!

EMPTY TREE!!

Total of nodes:5

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
9

Maxima:39

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:24

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:63

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
24 39 63
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:45

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
1

Enter data for insertion:54

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
24 39 45 54 63
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Minimum Value of the tree
7.      Maximum Value of tree
8.      Delete the whole tree
9.      Predecessor of the root
10.     Successor of The Root Node
11.     Height of the Tree
12.     Total no. of Nodes
13.     Total no. of Internal Nodes
14.     Total no. of External Nodes
15.     Search a Node
16.     EXIT
Enter your choice:
10

Minima:45

Do you wish to continue?
Press 1 for Yes & 0 for No
0

--------------------------------
Process exited after 136.8 seconds with return value 0
Press any key to continue . . .
*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
1

Enter data for insertion:45

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
1

Enter data for insertion:45

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
1

Enter data for insertion:39

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
1

Enter data for insertion:54

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
1

Enter data for insertion:60

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
1

Enter data for insertion:78

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
39 45 45 54 60 78
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     EXIT
Enter your choice:
6

Level Order:-
45 39 45 54 60 78
Do you wish to continue?
Press 1 for Yes & 0 for No
0

--------------------------------
Process exited after 95.38 seconds with return value 0
Press any key to continue . . .

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:3

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
2

Enter data for deletion:0

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
3
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:2

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:1

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:4

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:5

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
1 2 3 4 5
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
4
Preorder traversal of the given tree:-
3 2 1 4 5
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
5
Postorder traversal of the given tree:-
1 2 5 4 3
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
6

Level Order:-
3 2 4 1 5
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
17

Enter data for insertion:4

 Level Of 4 :2

Do you wish to continue?
Press 1 for Yes & 0 for No
0

--------------------------------
Process exited after 78.8 seconds with return value 0
Press any key to continue . . .
*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:3

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
4
Preorder traversal of the given tree:-
3
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:5

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:1

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:2

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
1

Enter data for insertion:4

Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
3
Inorder traversal of the given tree:-
1 2 3 4 5
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
6

Level Order:-
3 1 5 2 4
Do you wish to continue?
Press 1 for Yes & 0 for No
1

*************** MAIN MENU ***************

1.      Insert an Element
2.      Delete a node
3.      Inorder Traversal
4.      Preorder Traversal
5.      Postorder Traversal
6.      Levelorder Traversal
7.      Minimum Value of the tree
8.      Maximum Value of tree
9.      Delete the whole tree
10.     Predecessor of the root
11.     Successor of The Root Node
12.     Height of the Tree
13.     Total no. of Nodes
14.     Total no. of Internal Nodes
15.     Total no. of External Nodes
16.     Search a Node
17.     Level/Height of the given Node
18.     EXIT
Enter your choice:
17

Enter data for insertion:5

 Level Of 5 :2

Height of 5:1

Do you wish to continue?
Press 1 for Yes & 0 for No
0

--------------------------------
Process exited after 52.55 seconds with return value 0
Press any key to continue . . .
*/
