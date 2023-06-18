#include "../../includes/minirt.h"

int ft_strcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1) + 1));
}

long double    ft_atod(const char *str)
{
	long double	result;
	long double	float_part;

	result = ft_atoi(str);
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	float_part = ft_atoi(str + 1);
	while (float_part >= 1)
		float_part /= 10;
	return (result + float_part);
}
