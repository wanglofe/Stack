// Author:	Kevin
// Date:	20180516

#include <stdio.h>
#include <stdlib.h>

#define STACK_FULL	-1
#define STACK_EMPTY	-9999

static int index = -1;
typedef int stack_t;
static stack_t *stack = NULL;
static size_t maxlength = 0;


// stack handler declarations
int 	stack_create(size_t stack_size);
int 	stack_push(stack_t val);
int 	stack_pop(void);
stack_t stack_top(void);
int 	stack_isempty(void);
int 	stack_isfull(void);
int 	stack_empty(void);
size_t 	stack_length(void);
void 	stack_print(void);

// stack handlers
int stack_create(size_t stack_size)
{
	stack = malloc(sizeof(stack_t)*stack_size);
	if (!stack) {
		return -1;
	}
	maxlength = stack_size;
	return 0;
}

int stack_push(stack_t val)
{
	if(stack_isfull()) {
		return STACK_FULL;
	}
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
	return index == maxlength;
}

int stack_empty(void)
{
	index = 0;
	if(stack) {
		free(stack);
	}
	return 0;
}

size_t stack_length(void)
{
	return index+1;
}

void stack_print(void)
{
	int i;
	for(i=0; i<index; i++) {
		fprintf(stdout, "%d ", stack[i]);
	}
	putchar('\n');
}


// test
void main(void)
{
	stack_create(20);
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

