#include "monty_header.h"
#include <stdio.h>
/**
 * _add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n += n;
}

/**
 * m_nop - no operation performed
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
