/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:33:43 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/17 15:10:52 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	compare_results(char *string, unsigned int n);
void	print_char_array_null_X(char *string, unsigned int n);
void	print_string(char *string);

int	main(void)
{
	char			s_string_10c[10] = "Ten chars";
	char			*s_string_0c = "";
	unsigned int	d_len;

	print_string("d_len less than length of s_string");
	d_len = 5;
	compare_results(s_string_10c, d_len);

	print_string("d_len same as length of s_string");
	d_len = 10;
	compare_results(s_string_10c, d_len);

	print_string("d_len greater than length of s_string");
	d_len = 20;
	compare_results(s_string_10c, d_len);

	print_string("d_len set to zero");
	d_len = 0;
	compare_results(s_string_10c, d_len);

	print_string("zero length s_string");
	d_len = 3;
	compare_results(s_string_0c, d_len);
}

void	compare_results(char *string, unsigned int n)
{
	char	d_string_orig[n];
	char	d_string_test[n];
	char	*p_new_orig;
	char	*p_new_test;

	write(1, "\nOriginal function: \n", 21);
	p_new_orig = strncpy(d_string_orig, string, n);
	print_char_array_null_X(d_string_orig, n);
	print_char_array_null_X(p_new_orig, n);

	write(1, "\nRecreated function: \n", 22);
	p_new_test = ft_strncpy(d_string_test, string, n);
	print_char_array_null_X(d_string_test, n);
	print_char_array_null_X(p_new_test, n);

	write(1, "\n", 1);
}

void	print_char_array_null_X(char *string, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (string[i] == 0)
			string[i] = 'X';
		write(1, &string[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_string(char *string)
{
	int	i;
	
	i = 0;
	write(1, "\n", 1);
	while (string[i] != 0)
	{
		write(1, &string[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
