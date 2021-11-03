/*
AMANDA JUDY ANDRDADE
SE-IT 2
Practical 7A
Write a program for conversion and evaluation of infix to POSTFIX notation. 
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50            

char stack[SIZE];
int top = -1; 

void push(char elem) 
{ 
	stack[++top] = elem;
}

char pop() 
{ 
	return (stack[top--]);
}

int priority(char elem) 
{ 
	switch (elem) 
	{
		case '#':return 0;
		case '(':return 1;
					break;
		case '+':
		case '-':return 2;
				break;
		case '*':
		case '/':
		case '%':
		case '^':return 3; 
				break;
		default:printf("Invalid Input!!");	
				break;
	}
}

void infix_to_postfix(char *infix, char *postfix) 
{
	char ch, elem;
	int i = 0, j = 0;
	push('#');
	
	while ((ch = infix[i++]) != '\n') 
	{
		if (ch == '(')
			push(ch);
		else if (isalnum(ch))
			postfix[j++] = ch;
		else if (ch == ')') 
		{
			while (stack[top] != '(')
			postfix[j++] = pop();
			elem = pop(); 
		} 
		else 
		{ 
			while (priority(stack[top]) >= priority(ch))//if top has more priority we cannot push the lower priority element
				postfix[j++] = pop();
			push(ch);
		}
	}
	while (stack[top] != '#') 
	postfix[j++] = pop();
  	postfix[j] = 0; 
}

int evaluation(char *postfix) 
{
	char ch;
	int i = 0, op1, op2;
	while((ch = postfix[i++]) != 0) //Storing the value while scanning the expression
	{
		if(isdigit(ch)) 
			push(ch-'0'); 
		else 
		{        
			op2 = pop();
			op1 = pop();
			switch(ch) 
			{
				case '+' : push(op1+op2); 
							break;
				case '-' : push(op1-op2); 
							break;
				case '*' : push(op1*op2);
							break;
				case '/' : push(op1/op2);
							break;
				case '%':push(op1%op2);
							break;
				case '^':push(pow(op1,op2));
							break;
			}
		}
	}
	return stack[top];
}

int main() 
{ 
	
	char infix[50], postfix[50];
	printf("\n\tENTER THE INFIX EXPRESSION: ");
	fgets(infix, 50, stdin);
	
	infix_to_postfix(infix, postfix);

	printf("\n\tPOSTFIX EXPRESSION:\t %s",postfix);
	top = -1;
	printf("\n\tRESULT: %d", evaluation(postfix));
	return 0;
}

