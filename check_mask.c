#include "includes/str_check.h"

int	check_default_mask(char **format, char **string)
{
	int	found;

	found = 0;
	while (**format != ']')
	{
		if (!**format)
			return (-1);
		if (**format == **string)
			found = 1;
		(*format)++;
	}
	(*format)++;
	(*string)++;
	return (found);
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

