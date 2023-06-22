#include "hdr.h"

/**
* ysfexecute - function that executes the opcode
* @stack: head stack linked list
* @counter: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int ysfexecute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", YSF_push}, {"pall", YSF_pALL}, {"pint", YSF_pINT},
				{"pop", ysf_pop},
				{"swap", ysf_swap},
				{"add", ysf_add},
				{"nop", ysf_nopAK},
				{"sub", ysf_sub},
				{"div", ysf_div},
				{"mul", ysf_mul},
				{"mod", ysf_mod},
				{"pchar", ysf_pchar},
				{"pstr", ysf_pstr},
				{"rotl", ysf_rotl},
				{"rotr", f_rotrysf},
				{"queue", ysf_queue},
				{"stack", ysf_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		ysffree_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
