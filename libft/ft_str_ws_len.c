#include "libft.h"

int		ft_str_ws_len(char *str)
{
	int		index;

	index = -1;
	while (str[++index] && str[index] != ' ' && str[index] != '\t'
		&& str[index] != '\n')
		;
	return (index);
}
