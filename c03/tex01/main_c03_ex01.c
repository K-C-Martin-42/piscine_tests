/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c03_ex01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:07:24 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/18 16:30:37 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	run_test(char *s1, char *s2, unsigned int n);
void	print_int(int number);
void	print_str(char *str);

int	main(void)
{
	char	*string_1 = "abcdef";
	char	*string_2 = "abcefg";
	char	*string_3 = "abc";
	char	*string_4 = "";
	char	*string_5 = "abc\00efg";
	char	*string_6 = "abc\00def";

	print_str("\nTwo identical strings:");
	run_test(string_1, string_1, 6);
	
	print_str("\nTwo identical strings; n too long:");
	run_test(string_1, string_1, 16);

	print_str("\nTwo different strings (equal length):");
	run_test(string_1, string_2, 6);

	print_str("\nTwo different strings (equal length); n too short:");
	run_test(string_1, string_2, 2);

	print_str("\nTwo different strings (equal length); n of zero:");
	run_test(string_1, string_2, 0);

	print_str("\nMatching strings, second one shorter:");
	run_test(string_1, string_3, 6);
	
	print_str("\nMatching strings, second one shorter; n too long:");
	run_test(string_1, string_3, 16);

	print_str("\nMatching strings, first one shorter:");
	run_test(string_3, string_1, 6);

	print_str("\nSecond string is zero-length:");
	run_test(string_1, string_4, 6);

	print_str("\nBoth strings are zero-length:");
	run_test(string_4, string_4, 6);

	print_str("\nMatching strings, second one continues after null char:");
	run_test(string_3, string_5, 6);

	print_str("\nStrings match for 3 chars until null, both different after):");
	run_test(string_5, string_6, 6);
}

void	run_test(char *s1, char *s2, unsigned int n)
{
	print_str(s1);
	print_str(s2);

	write(1, "n = ", 4);
	print_int(n);

	write(1, "\n\nORIGINAL FUNCTION: ", 21);
	print_int(strncmp(s1, s2, n));

	write(1, "\n\nTEST FUNCTION: ", 17);
	print_int(ft_strncmp(s1, s2, n));

	write(1, "\n\n", 2);
}

void	print_int(int number)
{
	char	digit;

	if (number < 0)
	{
		write(1, "-", 1);
		number = number * -1;
	}
	digit = number % 10 + '0';
	if (number > 9)
	{
		print_int(number / 10);	
	}
	write(1, &digit, 1);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
