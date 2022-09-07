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
	stack_t *curr, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		curr = (*stack)->next;
		new->prev = *stack;
		new->next = curr;
		if (curr)
			curr->prev = new;
		(*stack)->next = new;
	}
	else
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		new->prev = curr;
		new->next = NULL;
		curr->next = new;
	}
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
	stack_t *curr = (*stack)->next;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	(void)line_number;
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
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
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
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
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
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
