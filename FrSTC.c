#include "hdr.h"

/**
* ysffree_stack - function that frees a doubly linked list
* @head: head pointer to the stack
*
* Return: nothing
*/
void ysffree_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* ysf_stack - function that prints the top
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void ysf_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
