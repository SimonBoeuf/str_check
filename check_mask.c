#include "includes/str_check.h"

int	check_default_mask(char **format, char **string)
{
	int	i;
	int	j;

	i = 0;
	while (*((*format) + i) != ']')
	{
		if (!format[0][i])
			return (-1);
		i++;
	}
	j = i;
	while (**format != ']')
	{
		if (!**format)
			return (-1);
		if (check_char(format, string, *(*format + j + 1), j))
			return (1);
		j = j - 1;
		*format += 1;
	}
	(*format)++;
	(*string)++;
	return (0);
}

int	check_mask(int mask_number, char **string)
{
	(void)mask_number;
	(void)string;
	return (0);
}

int	get_mask_number(char *mask)
{
	(void)mask;
	return (0);
}

int	get_mask(char **format)
{
	int		i;
	char	*mask;

	mask = NULL;
	(*format)++;
	i = 0;
	while (format[0][i] != ']')
	{
		if (!(format[0][i]))
			return (0);
		i++;
	}
	if (i != 0)
		mask = strndup(*format, i);
	if (mask != NULL)
	{
		if (get_mask_number(mask))
			format += i + 1;
	}
	else
		return (0);
	return (get_mask_number(mask));
}

