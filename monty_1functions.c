#include "monty_header.h"

/**
  * _push - pushes a value to a stack_t linked list.
  *
  * @stack: double pointer to the head node of a stack_t linked list.
  * @line_number: current working line number of the Monty bytecodes file.
  *
  * Return: nothing.
  */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
  * _pall - prints out the value of a stack_t linked list.
  *
  * @stack: double pointer to the head node of a stack_t linked list.
  * @line_number: current working line number of the Monty bytecodes file.
  *
  * Return: nothing.
  */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}

/**
  * _pint - prints out the top value of a stack_t linked list.
  *
  * @stack: pointer to the head mode node of the stack_t linked list.
  * @line_number: the current working line number of a Monty bytecode file.
  *
  * Return: nothing.
  */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
  * _pop - removes the top value element of a stack_t linked list.
  *
  * @stack: pointer to the head mode node of the stack_t linked list.
  * @line_number: the current working line number of a Monty bytecode file.
  *
  * Return: nothing.
  */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.stack_len--;
}

/**
  * _swap - swaps the top 2 value elements of a stack_t linked list.
  *
  * @stack: pointer to the head mode node of the stack_t linked list.
  * @line_number: the current working line number of a Monty bytecode file.
  *
  * Return: nothing.
  */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}
