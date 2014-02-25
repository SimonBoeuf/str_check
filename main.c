#include <stdio.h>
#include "includes/str_check.h"

int main(void)
{
	if (!str_check("abc", "abc") > 0)
		printf("abc should match abc\n");
	if (str_check("abc", "abd") > 0)
		printf("abc should not match abd\n");
	if (!str_check("a[bcd]c", "abc") > 0)
		printf("a[bcd]c should match abc\n");
	if (!str_check("a[bcd]c", "acc") > 0)
		printf("a[bcd]c should match acc\n");
	if (!str_check("a[bcd]c", "adc") > 0)
		printf("a[bcd]c should match adc\n");
	if (str_check("a[bcd]c", "aec") > 0)
		printf("abc should not match aec\n");
	if (str_check("a[bcd]c", "ac") > 0)
		printf("a[bcd]c should not match ac\n");
	if (!str_check("ab+c", "abbc") > 0)
		printf("ab+c should match abbc\n");
	if (!str_check("ab*c", "abbc") > 0)
		printf("ab*c should match abbc\n");
	if (!str_check("ab*c", "ac") > 0)
		printf("ab*c should match ac\n");
	if (!str_check("ab?c", "abc") > 0)
		printf("ab?c should match abc\n");
	if (!str_check("ab?c", "ac") > 0)
		printf("ab?c should match ac\n");
	if (str_check("ab+c", "ac") > 0)
		printf("ab+c should not match ac\n");
	if (str_check("ab*c", "adc") > 0)
		printf("ab*c should not match adc\n");
	if (str_check("ab+c", "adc") > 0)
		printf("ab+c should not match adc\n");
	if (str_check("ab?c", "abbc") > 0)
		printf("ab?c should not match abbc\n");
	if (str_check("ab?c", "adc") > 0)
		printf("ab?c should not match adc\n");
	if (!str_check("a\\*b", "a*b") > 0)
		printf("a\\*b should match a*b\n");
	if (!str_check("a[bcd]?e", "abe") > 0)
		printf("a[bcd]?e should match abe\n");
	if (!str_check("a[bcd]?e", "ace") > 0)
		printf("a[bcd]?e should match ace\n");
	if (str_check("a[bcd]?e", "abbce") > 0)
		printf("a[bcd]?e should not match abbce\n");
	if (!str_check("a[bcd]+e", "abbe") > 0)
		printf("a[bcd]+e should  match abbe\n");
	if (!str_check("a[bcd]+e", "abbbbbbbbbe") > 0)
		printf("a[bcd]+e should  match abbbbbbbe\n");
	if (!str_check("a[bcd]+e", "abe") > 0)
		printf("a[bcd]+e should  match abe\n");
	if (str_check("a[bcd]+e", "ae") > 0)
		printf("a[bcd]+e should not match ae\n");
	if (!str_check("a[bcd]*e", "ae"))
		printf("a[bcd]*e shoud match ae\n");
	if (!str_check("a[bcd]*e", "abcde"))
		printf("a[bcd]*e shoud match abcde\n");
	if (!str_check("a[bcd]+e", "acccce"))
		printf("a[bcd]+e should match acccce\n");
	if (!str_check("a[bcd]+", "acccc"))
		printf("a[bcd]+ should match acccc\n");
	if (!str_check("a[bcd]+e", "addde"))
		printf("a[bcd]+e should match addde\n");
	if (str_check("a[bcd]+", "acccce"))
		printf("a[bcd]+ should not match acccce\n");
	if (!str_check("a[bcd]+", "adcdddc"))
		printf("a[bcd]+ should match adcccdddc\n");
	if (!str_check("a[bcd]+", "abcdddcdbcdbdcdcb"))
		printf("a[bcd]+ should match abcdddcdcdbdcdbdcdb\n");
	if (!str_check("a[bcd]+e", "abcdcdbcdbcdbe"))
		printf("a[bcd]+e should  match abcdcbcdbcdbe\n");
	return (0);
}
