/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_03_ex05.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:41:21 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/23 11:37:52 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	ft_strlcat(char *dest, char *src, unsigned int nb);
void	run_test_10sp(char *src, unsigned int nb);
void	run_test_zero(char *src, unsigned int nb);
void	run_test_null(char *src, unsigned int nb);
void	run_test(char *src, unsigned int nb, char *dest_orig, char *dest_test);
void	print_int(int number);
void	print_str(char *str); 

int	main(void)
{
	unsigned int	nb;
	char			string_1[10] = "123456789";
	char			string_2[6] = "12345";
	char			string_3[21] = "12345678901234567890";
	char			string_4[0] = "";
	char			string_5[8] = "abc\0def";
	char			string_6[21] = "12345";

	nb = 39;

	print_str("\n\nSrc string matches available space:\n");
	run_test_10sp(string_1, nb);

	print_str("\n\nSrc string shorter than available space:");
	run_test_10sp(string_2, nb);

	print_str("\n\nSrc string longer than available space:");
	run_test_10sp(string_3, nb);

	print_str("\n\nSrc string is zero-length:");
	run_test_10sp(string_4, nb);

	print_str("\n\nSrc string has null in middle:");
	run_test_10sp(string_5, nb);

	print_str("\n\nSrc string has extra spaces at end:");
	run_test_10sp(string_6, nb);


	nb = 10;

	print_str("\n\nSpace available, but dstsize too small:\n");
	run_test_10sp(string_1, nb);


//	print_str("\n\nBoth strings are zero-length:");
//	run_test_zero(string_4, nb);


	print_str("\n\nDestination string starts with null but has space.");
	run_test_null(string_2, nb);
}

void	run_test_10sp(char *src, unsigned int nb)
{
	char dest_orig[39] = "Dest string with ten spaces:"; 
	char dest_test[39] = "Dest string with ten spaces:"; 

	run_test(src, nb, dest_orig, dest_test);
}

void	run_test_zero(char *src, unsigned int nb)
{
	char dest_orig[0] = ""; 
	char dest_test[0] = ""; 

	run_test(src, nb, dest_orig, dest_test);
}

void	run_test_null(char *src, unsigned int nb)
{
	char dest_orig[15] = ""; 
	char dest_test[15] = ""; 

	run_test(src, nb, dest_orig, dest_test);
}

void	run_test(char *src, unsigned int nb, char *dest_orig, char *dest_test)
{
	int	len_orig;
	int	len_test;

	print_str("\n\ndest string: "); 
	print_str(dest_orig);
	print_str("\n\nsrc string: "); 
	print_str(src);
	print_str("\n\nnb = ");
	print_int(nb);
	print_str("\n\nORIGINAL FUNCTION: ");
	len_orig = strlcat(dest_orig, src, nb);
	print_str(dest_orig);
	print_str("\nReturns: ");
	print_int(len_orig);

	print_str("\nTEST FUNCTION:    ");
	len_test = ft_strlcat(dest_test, src, nb);
	print_str(dest_test);
	print_str("\nReturns: ");
	print_int(len_test);
	print_str("\n\n-----------------------------");
}

void	print_int(int number)
{
	char	digit;
	int		min_int;
	char	*min_int_str;

	min_int = -2147483648;
	min_int_str = "-2147483648";	
	if (number == min_int)
	{
 		write(1, &min_int_str, 11);
		return ;
	}
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number > 9)
	{
		print_int(number / 10);
	}
	digit = number % 10 + '0';
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
}
