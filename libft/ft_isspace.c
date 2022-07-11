#include "libft.h"

int		ft_isspace(int c)
{
	const char	*str;
	int			i;

	i = 0;
	str = " \n\t\v\f\r";
	while (c != str[i])
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}
