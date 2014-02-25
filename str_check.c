#include "includes/str_check.h"

int	check_default_mask(char **format, char **string)
{
	int	found;

	found = 0;
	while (**format != ']')
	{
		if (!**format)
			return (0);
		if (**format == **string)
			found = 1;
		(*format)++;
	}
	(*format)++;
	(*string)++;
	return (found);
}

int	mask_check(int mask_nubmer, char **string)
{
	return (0);
}

int	get_mask_number(char *mask)
{
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

int	escape(char **format, char **string)
{
	if (*(*format + 1) != **string)
		return (0);
	*format += 2;
	*string += 1;
	return (1);
}

int	check_char(char **format, char **string)
{
	if (*(*format + 1) == '*')
	{
		while (**format == **string)
			(*string)++;
		*format += 2;
		return (1);
	}
	else if (*(*format + 1) == '?')
	{
		if (**format == **string)
			*string += 1;
		*format += 2;
		return (1);
	}
	else if (*(*format + 1) == '+')
	{
		if (**format != **string)
			return (0);
		while (**format == **string)
			*string += 1;
		*format += 2;
		return (1);
	}
	else
	{
		if (**format != **string)
			return (0);
		else
		{
			(*format++);
			(*string++);
			return (1);
		}
	}
}

int	str_check(char *format, char *string)
{
	int	mask;

	while (*string && *format)
	{
		if (*format == '[')
		{
			if ((mask = get_mask(&format)) == -1)
				return (0);
			else if (mask == 0)
			{
				if (!check_default_mask(&format, &string))
					return (0);
			}
			else if (!mask_check(mask, &string))
				return (0);
		}
		else if (*format == '\\')
		{
			if (!escape(&format, &string))
				return (0);
		}
		else
		{
			if (!check_char(&format, &string))
				return (0);
			string++;
			format++;
		}
	}
	return((!*string) && (!*format));
}
