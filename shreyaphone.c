/*
Write a program to create a link list called as phonebook with members 
1. First Name
2. Last Name
3. Phone Number
4. Email ID(verify for a valid email id)
The input for the phonebook is taken from the users(minimum 10 entries) and stored in the link list in alphabetical order.

Next, create a .csv file and store the details in phonebook.
*/

#include<stdio.h>
#include<stdlib.h>
# include<string.h>
 
struct phonebook
{
    string name;
    string email;;
    int number;
    struct phonebook*next;
};
void create(); 
void insert();
void display();
void delete();
 
int main()
{
    int choice;
    while(choice != 5)
    {
 
 
    printf("\nPhonebook");
    printf("1 - Insert something in the phonebook?\n");
    printf("2 - Delete something from the phonebook?\n");
    printf("3 - Print out one of the contacts?\n");
    printf("4 - Return the element selected?\n");
    printf("5 - Nothing at all\n");
    printf("Enter 1 through 5: ");
    scanf("%d", &choice);
 
 
    switch(choice){
        case 1:
            insertsomething();
            printitout();
            break;
        case 2:
            deletesomething();
            break;
        case 3:
            printitout();
            break;
        case 4:
            servesomething();
            break;
        default:
            printf("\nThank you for using the phonebook\n");
            return 0;
    }
    }
 
 
    return 0;
 
 
}
 
void create(struct phonebook)
{
	
}
 
void insertsomething()
{
    char first_name_string[20];
    char last_name_string[20];
    char number[13];
    int value;
    Entryptr ptr;
    printf("Enter the first name of the contact to be entered.\n");
    scanf("%s", first_name_string);
    printf("Enter the last name of the contact to be entered.\n");
    scanf("%s", last_name_string);
    printf("Enter the telephone number of the contact to be entered in the format (xxx)xxx-xxxx:\n");
    scanf("%s", number);
 
 
    ptr = malloc(sizeof(Entry));
 
 
    strcpy(ptr->firstname, first_name_string);
    strcpy(ptr->lastname, last_name_string);
    ptr->next=NULL;
 
 
    insert(ptr);
 
 
    printf("%s %s", ptr->firstname, ptr->lastname); /* Just to check */
 
 
 
 
}
 
 
void insert(Entryptr newnodeptr)
{
    Entryptr trailing = head, target = head;
    if (head == NULL) //List is empty
        head = newnodeptr;
    else if (strcmp(newnodeptr->lastname, target->lastname)>0)
    {
        newnodeptr->next = head;
        head = newnodeptr;
    }
    else
    {
        target = previous->next;
        while(target != NULL)
        {
            if (strcmp(newnodeptr->lastname, target->lastname)>0)
            {
                newnodeptr->next = target;
                trailing->next = newnodeptr;
            }
            else
            {
                trailing = target;
                target = trailing->next;
            }
        }
 
 
    }
    printitout();
}
 
 
void printiout()
{
    int n = 1;
    Entryptr ptr = head;
    if (head==NULL)
        printf("List is empty\n");
    else
    {
        while (ptr != NULL)
        {
            printf("Entry %d: %s, %s\t\t%s", n, ptr->lastname, ptr->firstname, ptr->number);
            printf("\n\n");
            ptr=ptr->next;
            n++;
        }
    }
}
 
 
void deletesomething()
{
    Entryptr target = head, trailing = head, ptr = NULL;
    char *fstring, *lstring;
    printf("What task do you want to delete (LAST-NAME FIRST-NAME)?\n");
    scanf("%s %s", lstring, fstring);
        if (head == NULL)
            printf("The list is empty\n");
        else if (strcmp(head->lastname, lstring)==0)
        {
            ptr = head;
            head = head->next;
            free(ptr);
        }
        else
        {
            target = trailing->next;
            while (target != NULL)
            {
                if((strcmp(target->lastname, lstring)==0))
                {
                    trailing->next = target->next;
                    free(target);
                }
                else
                {
                    trailing=target;
                    target = trailing->next;
                }
            }
        }
}
