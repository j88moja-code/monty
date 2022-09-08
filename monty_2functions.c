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
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
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
