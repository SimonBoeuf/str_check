#ifndef STR_CHECK_H
# define STR_CHECK_H

#include <stdio.h>
#include <string.h>

int	is_quantif(char c);
int	check_default_mask(char **format, char **string);
int	mask_check(int mask_number, char **string);
int	get_mask_number(char *mask);
int	get_mask(char **format);
int	escape(char **format, char **string);
int	str_check(char *format, char *string);

#endif
