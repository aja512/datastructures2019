/*
AMANDA JUDY ANDRADE
SE-IT 2
PRACTICAL 
C Program to Implement Queue Data Structure using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 	printf("\n************MENU************\n");
    printf("\n 1 . Enque");
    printf("\n 2 . Deque");
    printf("\n 3 . Front element");
    printf("\n 4 . Empty");
    printf("\n 5 . Exit");
    printf("\n 6 . Display");
    printf("\n 7 . Queue size");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
    display();
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d\n", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
        display();
}
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
/*
O/P:-
************MENU************

 1 . Enque
 2 . Deque
 3 . Front element
 4 . Empty
 5 . Exit
 6 . Display
 7 . Queue size
 Enter choice : 1
Enter data : 1
1
 Enter choice : 1
Enter data : 2
1 2
 Enter choice : 1
Enter data : 3
1 2 3
 Enter choice : 1
Enter data : 4
1 2 3 4
 Enter choice : 1
Enter data : 5
1 2 3 4 5
 Enter choice : 7

 Queue size : 5
 Enter choice : 6
1 2 3 4 5
 Enter choice : 2

 Dequed value : 12 3 4 5
 Enter choice : 2

 Dequed value : 23 4 5
 Enter choice : 2

 Dequed value : 34 5
 Enter choice : 2

 Dequed value : 45
 Enter choice : 2

 Dequed value : 5
Queue is empty
 Enter choice : 2

 Error: Trying to display elements from empty queue
 Enter choice :
*/