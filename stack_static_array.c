// Author:	Kevin
// Date:	20180516

#include <stdio.h>

#define MAXLEN	1024
typedef int  stack_t; 
//static int index = 0;
static int index = -1;
static stack_t stack[MAXLEN];
#define STACK_EMPTY	-99999 
#define STACK_FULL	-1

// stack handler declarations
int stack_push(stack_t val);
int stack_pop(void);
stack_t stack_top(void);
int stack_isempty(void);
int stack_isfull(void);
int stack_length(void);
int stack_empty(void);
void stack_print(void);

// stack handler
int stack_push(stack_t val)
{
	if(stack_isfull()) {
		return STACK_FULL;
	}
	//stack[index++] = val;
	stack[++index] = val;
	return 0;
}

int stack_pop(void)
{
	if(stack_isempty()) {
		return STACK_EMPTY;
	}
	index--;
	return 0;
}

stack_t stack_top(void)
{
	if(stack_isempty()) {
		return STACK_EMPTY; 
	}
	return stack[index];
}

int stack_isempty(void) 
{
	return index == 0;
}

int stack_isfull(void)
{
	return index == MAXLEN;
}

int stack_length(void)
{
	return index+1;
}

int stack_empty(void)
{
	index = 0;
}

void stack_print(void)
{
	int i;
	for(i=index; i>=0; i--) {
		fprintf(stdout, "%d ", stack[i]);
	}
	putchar('\n');
}

// test
void main(void)
{
	int i;
	for(i=0; i<20; i++) {
		stack_push(i);
	}
	stack_print();
	printf("stack length: %d\n", stack_length());
	printf("stack top: %d\n", stack_top());
	
	stack_pop();
	stack_print();

	stack_empty();
	printf("stack empty: %d\n", stack_isempty());
}
