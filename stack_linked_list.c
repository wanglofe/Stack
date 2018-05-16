// Author:	Kevin
// Date:	20180516

#include <stdio.h>
#include <stdlib.h>

#define STACK_FULL -1
#define STACK_EMPTY -9999

typedef int stack_t;

typedef struct sll {
	stack_t val;
	struct sll *next;
} sll_t;

static sll_t *header = NULL;

// handler declarations
int	stack_push(stack_t val);
int	stack_pop(void);
stack_t	stack_top(void);
int	stack_isempty(void);
int	stack_isfull(void);
int	stack_empty(void);
size_t	stack_length(void);
void	stack_print(void);

// handlers
int stack_push(stack_t val)
{
	if(stack_isfull()) {
		return STACK_FULL;
	}
	sll_t *newnode = malloc(sizeof(sll_t));
	if (!newnode) {
		return -1;
	}
	newnode->val = val;
	newnode->next = header;
	header = newnode;
	return 0;
}

int stack_pop(void)
{
	if(stack_isempty()) {
		return STACK_EMPTY;
	}
	sll_t *tmp = header;
	header = header->next;
	free(tmp);
	return 0;
}

stack_t stack_top(void)
{
	if(stack_isempty()) {
		return STACK_EMPTY;
	}
	return header->val;
}

int stack_isempty(void)
{
	if(!header) {
		return 1;
	}
	return 0;
}

int stack_isfull(void)
{
	/* never */
	return 0;
}

int stack_empty(void)
{
	while(!stack_isempty()) {
		stack_pop();
	}
}

size_t stack_length(void)
{
	sll_t *tmp = header;
	size_t count = 0;
	while(tmp) {
		++count;
		tmp = tmp->next;
	}	
	return count;
}

void stack_print(void) 
{
	sll_t *tmp = header;
	while(tmp) {
		fprintf(stdout, "%d ", tmp->val );
		tmp = tmp->next;
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









