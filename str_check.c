#include "includes/str_check.h"

int	escape(char **format, char **string)
{
	if (*(*format + 1) != **string)
		return (0);
	*format += 2;
	*string += 1;
	return (1);
}

int	str_check(char *format, char *string)
{
	int	mask;

	while (*string && *format)
	{
		if (*format == '[')
		{
			if ((mask = get_mask(&format)) == -1)
				return (-1);
			else if (mask == 0)
			{
				if (!check_default_mask(&format, &string))
					return (0);
			}
			else if (!check_mask(mask, &string))
				return (0);
		}
		else if (*format == '\\')
		{
			if (!escape(&format, &string))
				return (0);
		}
		else
		{
			if (!check_char(&format, &string, *(format + 1), 0))
				return (0);
		}
	}
	return((!*string) && (!*format));
}
