/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:33:43 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/19 11:19:23 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);
void	compare_results(char *string, unsigned int n);
void	print_char_array_null_X(char *string, unsigned int n);
void	print_string(char *string);

int	main(void)
{
	char			src_10c[10] = "Ten chars";
	char			*src_0c = "";
	unsigned int	d_len;

	print_string("d_len less than length of src");
	d_len = 5;
	compare_results(src_10c, d_len);

	print_string("d_len same as length of src");
	d_len = 10;
	compare_results(src_10c, d_len);

	print_string("d_len greater than length of src");
	d_len = 20;
	compare_results(src_10c, d_len);

	print_string("d_len set to zero");
	d_len = 0;
	compare_results(src_10c, d_len);

	print_string("zero length src");
	d_len = 3;
	compare_results(src_0c, d_len);
}

void	compare_results(char *string, unsigned int n)
{
	char	d_string_orig[n];
	char	d_string_test[n];
	char	*p_new_orig;
	char	*p_new_test;

	d_string_orig[0] = 't';
	d_string_test[0] = 't';

	write(1, "\nOriginal function: \n", 21);
	p_new_orig = strcpy(d_string_orig, string);
	print_char_array_null_X(d_string_orig, n);
	print_char_array_null_X(p_new_orig, n);

	write(1, "\nRecreated function: \n", 22);
	p_new_test = ft_strcpy(d_string_test, string);
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
