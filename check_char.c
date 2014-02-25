#include "includes/str_check.h"

static int	check_star(char **format, char **string, int mask_pos)
{
	int	cont;
	int	i;

	cont = 1;
	if (mask_pos == 0)
	{
		while (**format == **string)
			*string += 1;
	}
	else
	{
		cont = 1;
		while (cont)
		{
			i = 0;
			cont = 0;
			while (i < mask_pos)
			{
				if (*((*format) + i) == **string)
					cont = 1;
				i++;
			}
			if (cont)
				*string += 1;
		}
	}
	(*format) += mask_pos + 2;
	return (1);
}

static int	check_inter(char **format, char **string, int mask_pos)
{
	int	i;

	if (mask_pos == 0)
	{
		if (**format == **string)
			*string += 1;
	}
	else
	{
		i = 0;
		while (i < mask_pos)
		{
			if (*((*format) + i) == **string)
				*string += 1;
			i++;
		}
	}
	(*format) += mask_pos + 2;
	return (1);
}

static int	check_plus(char **format, char **string, int mask_pos)
{
	int	cont;
	int	i;

	cont = 1;
	if (mask_pos == 0)
	{
		if (**format != **string)
			return (0);
		while (**format == **string)
			*string += 1;
	}
	else
	{
		cont = 0;
		i = 0;
		while (i < mask_pos)
		{
			if (*((*format) + i) == **string)
				cont = 1;
			i++;
		}
		if (!cont)
			return (0);
		cont = 1;
		while (cont)
		{
			i = 0;
			cont = 0;
			while (i < mask_pos)
			{
				if (*((*format) + i) == **string)
					cont = 1;
				i++;
			}
			if (cont)
				*string += 1;
		}
	}
	(*format) += mask_pos + 2;
	return (1);
}

static int	check_no_quantif(char **format, char **string, int mask_pos)
{
		if (**format != **string)
			return (0);
		else
		{
			*format += mask_pos + 1;
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

