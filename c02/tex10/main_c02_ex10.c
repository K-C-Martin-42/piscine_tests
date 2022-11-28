/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:23:51 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/19 13:03:53 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			compare_results(char *string, unsigned int size, unsigned int actual_d);
void			print_char_array_null_X(char *string, unsigned int size);
void			print_string(char *string);
void			print_int(unsigned int len);
void			fill_array_with_alpha(char *array, unsigned int n);

int	main(void)
{
	char			s_string_10c[10] = "1234 6789";
	char			*s_string_0c = "";
	unsigned int	d_len;

	print_string("\nd_len less than length of s_string");
	d_len = 5;
	compare_results(s_string_10c, d_len, d_len);

	print_string("\nd_len same as length of s_string");
	d_len = 10;
	compare_results(s_string_10c, d_len, d_len);

	print_string("\nd_len greater than length of s_string");
	d_len = 20;
	compare_results(s_string_10c, d_len, d_len);

	print_string("\nd_len set to zero");
	d_len = 0;
	compare_results(s_string_10c, d_len, d_len);

	print_string("\nd_len set to zero, but dest has space");
	d_len = 0;
	compare_results(s_string_10c, d_len, 8);

	print_string("\nd_len set to zero");
	d_len = 0;
	compare_results(s_string_10c, d_len, 5);

	print_string("\nzero length s_string");
	d_len = 5;
	compare_results(s_string_0c, d_len, d_len);
}

void	compare_results(char *string, unsigned int n, unsigned int actual_d)
{
	char			d_string_orig[actual_d];
	char			d_string_test[actual_d];
	unsigned int	len_orig;
	unsigned int	len_test;

	fill_array_with_alpha(d_string_orig, actual_d);
	fill_array_with_alpha(d_string_test, actual_d);

	print_string("\n\nSource: ");
	print_string(string);
	print_string("\nDestination: ");
	print_string(d_string_orig);

	print_string("\ndlen: ");
	print_int(n);

	print_string("\nactual dest length: ");
	print_int(actual_d);

	print_string("\n\nORIGINAL FUNCTION:\nReturns: ");
	len_orig = strlcpy(d_string_orig, string, n);
	print_int(len_orig);
	print_string("\nResult: ");
	print_char_array_null_X(d_string_orig, n);

	print_string("\nRECREATED FUNCTION:\nReturns: ");
	len_test = ft_strlcpy(d_string_test, string, n);
	print_int(len_test);
	print_string("\nResult: ");
	print_char_array_null_X(d_string_test, n);

	print_string("\n\n-------------");
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
	while (string[i] != 0)
	{
		write(1, &string[i], 1);
		i++;
	}
}

void	print_int(unsigned int len)
{
	char	digit;

	if (len > 9)
	{
		print_int(len / 10);
	}
	digit = len % 10 + '0';
	write(1, &digit, 1);
}

void	fill_array_with_alpha(char *array, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		array[i] = i + 97;
		i++;	
	}
}
