#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *next;
};

struct stack
{
	node *top;
}


void push(struct node *top, int data);
{
	node *data = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link = stack->top;
	stack->top = temp;
}


int pop(struct node *top)
{
	top->data[top->next];
	top->next--;
	retrun data;
}


int main()
{
	int num;
	struct node *p, *head = NULL;

	printf("num\n");

	while (scanf("%d", &num) == 1)
	{
		p = (struct node*)malloc(sizeof(struct student));

		if (p == NULL)
		{
			perror("malloc");
			exit(1);
		}

		p->data = data;
		push(*p, data);
	}

	printf("\nPrint stack\n");

	p = node;

	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->node;
	}

	exit(0);
}
