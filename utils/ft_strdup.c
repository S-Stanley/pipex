#include "../main.h"

char	*ft_strdup(char *str)
{
	char			*to_return;
	unsigned int	i;

	to_return = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		to_return[i] = str[i];
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}
