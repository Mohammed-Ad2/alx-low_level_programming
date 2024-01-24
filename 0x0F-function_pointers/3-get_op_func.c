#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - Returns a function pointer to the corresponding
 *		 arithmetic operation based on the provided operator.
 * @s: The operator string.
 *
 * Return:
 *   - If a matching operator is found, returns the corresponding function
 *     pointer.
 *   - If no matching operator is found, returns NULL.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (i < 5)
	{
		if (*s == *ops[i].op)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
