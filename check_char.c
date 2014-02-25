#include "includes/str_check.h"

static int	check_star(char **format, char **string, int mask_pos)
{
	while (**format == **string)
		(*string)++;
	(*format) += mask_pos + 2;
	return (1);
}

static int	check_inter(char **format, char **string, int mask_pos)
{
	if (**format == **string)
		*string += 1;
	(*format) += mask_pos + 2;
	return (1);
}

static int	check_plus(char **format, char **string, int mask_pos)
{
	if (**format != **string)
		return (0);
	while (**format == **string)
		*string += 1;
	(*format) += mask_pos + 2;
	return (1);
}

static int	check_no_quantif(char **format, char **string, int mask_pos)
{
		if (**format != **string)
			return (0);
		else
		{
			(*format) += mask_pos + 1;
			(*string)++;
			return (1);
		}
}

int	check_char(char **format, char **string, char quantif, int mask_pos)
{
	if (quantif == '*')
		return (check_star(format, string, mask_pos));
	else if (quantif == '?')
		return (check_inter(format ,string, mask_pos));
	else if (quantif == '+')
		return (check_plus(format, string, mask_pos));
	else
		return (check_no_quantif(format, string, mask_pos));
}

