#include "asm.h"

int	str_is_empty(char *str)
{
	int	index;
	int	is_it;

	index = -1;
	is_it = 1;
	while (str[++index])
	{
		if (str[index] != ' ' && str[index] != '\t'
			&& str[index] != '\n')
			is_it = 0;
	}
	return ((is_it) ? 1 : 0);
}
