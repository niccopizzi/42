#include "libft.h"

char    *ft_strtod(char *str, double *d)
{
    int i;
    double atoi;
    int sign;

    i = 0;
    sign = 1;
    if (str[0] == '-')
        sign = -1;
    *d = ft_atoi(str);
    while(str[i] && str[i] != '.' && !ft_isspace(str[i]))
        i++;
    if (str[i] && !ft_isspace(str[i]))
    {
        atoi = ft_atoi(str + i);
        *d = *d + (sign) * atoi / pow(10, ft_numlen((int)atoi) - 1);
        while (str[i] >= '0' && str[i] <= '9')
            i++;
    }
    return (str + i);
}

/*
char	*ft_strtod(char *str, double *atod)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	*atod = ft_atoi(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		*atod = *atod + (sign) * (float)ft_atoi(str + i) / ft_pow(10,
				ft_numlen(ft_atoi(str + i)));
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (str + i);
}
*/