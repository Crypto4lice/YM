#include<stdio.h>

#define MAX_SIZE 100

typedef enum {false,true} bool;

typedef struct _stack {
	int arr[MAX_SIZE];
	int top;
}_stack;

struct _stack stack;

void initStack(_stack* a);
bool isempty(_stack* a);
bool isfull(_stack* a);
void push(_stack* a);
int pop(_stack* a);
int peak(_stack* a);
void print_stack(_stack* a);

int main()
{
	initStack(&stack);
	while (1)
	{
		int n;
		printf("push,pop,peak,all print,exit [1,2,3,4,5]\n");
		scanf_s("%d", &n);
		if (n == 1)
			push(&stack);
		else if (n == 2)
			pop(&stack);
		else if (n == 3)
			peak(&stack);
		else if (n == 4)
			print_stack(&stack);
		else if (n == 5)
			break;
		else
			printf("Retry\n");
	}
	return 0;
}

void initStack(_stack* a)
{
	a->top = -1;
}

bool isempty(_stack* a)
{
	return (a->top == -1); // TRUE 1 FALSE 0
}

bool isfull(_stack* a)
{
	return (a->top == MAX_SIZE - 1); // TRUE 1 FALSE 0
}

void push(_stack* a)
{
	int data;
	printf("insert number : ");
	scanf_s("%d", &data);

	if (isfull(a))
		printf("stack is full\n");
	else
	{
		++a->top;
		a->arr[a->top] = data;
	}
}

int pop(_stack* a)
{
	if (isempty(a))
		printf("stack is empty\n");
	else
	{
		a->top--;
		printf("pop %d\n", a->arr[a->top + 1]);
		return a->arr[a->top+1];
	}
}

int peak(_stack* a)
{
	if (isempty(a))
		printf("stack is empty\n");
	else
	{
		printf("Top is %d\n", a->arr[a->top]);
		return a->arr[a->top];
	}
}

void print_stack(_stack* a)
{
	int i;
	printf("In Stack : ");
	for (i = 0; i <= a->top; i++)
	{
		printf("%d ", a->arr[i]);
	}
	printf("\n");
}


