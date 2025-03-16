#include "libft.h"

char    *ft_strtof(char *str, float *f)
{
    int i;
	int	len;
    float atoi;
    int sign;

    i = 0;
    sign = 1;
	len = 0;
    if (str[0] == '-')
        sign = -1, i++;
	else if (str[0] == '+')
		i++;
    *f = ft_atoi(str);
    while(str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '.')
    {
		i++;
        atoi = ft_atoi(str + i);
        while (str[i] >= '0' && str[i] <= '9')
            i++, len++;
        *f = *f + (sign) * atoi / pow(10, len);
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