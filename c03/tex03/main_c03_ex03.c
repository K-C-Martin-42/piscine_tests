/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c03_ex03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:26:53 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/28 10:16:27 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);
void	init_array_digits_x(char *array, int num_char, int len);
void	run_test(char *src, unsigned int nb, int d_num_char, int d_len);
void	print_int(int number);
void	print_str(char *str);
void	print_str_n_X(char *str, int n);

int	main(void)
{
	print_str("\nNB: in the following test outputs, dest is originally pre-filled with 'x' \n"
	"and null-terminated (and then is initialised with the specified number of \n"
	"digit characters, and null-terminated again); 'X' represents null characters \n"
	"found when the total dest buffer is printed out.");
	print_str("\n\n---------------------------------------\n\n");

	// run_test takes:
	// - src (string to append)
	// - n (number of chars to append - will null terminate afterwards)
	// - d_num_char (number of chars in dest before first null)
	// - d_len (number of total elements in dest... including space for final null) 

	print_str("\nSrc string shorter than available space:");
	run_test("abc", 5, 5, 10);

	print_str("\nSrc exactly the same as available space:");
	run_test("abcd", 4, 5, 10);

	print_str("\nSrc too long for available space (trying to append without leaving space for null):");
	run_test("abcdef", 5, 5, 10);

	print_str("\nSrc is an empty string:");
	run_test("", 3, 5, 10);

	print_str("\nDest is an empty string:");
	run_test("abc", 3, 0, 10);


}

void	run_test(char *src, unsigned int nb, int d_num_char, int d_len)
{
	char dest_orig[d_len]; 
	char dest_test[d_len]; 

	init_array_digits_x(dest_orig, d_num_char, d_len);
	init_array_digits_x(dest_test, d_num_char, d_len);
	
	print_str("\n\ndest string: "); 
	print_str(dest_orig);
	print_str("\n\nsrc string: "); 
	print_str(src);
	print_str("\n\ndest string total size (not including final null): "); 
	print_int(d_len);
	print_str("\n\ndest string num chars: "); 
	print_int(d_num_char);
	print_str("\n\nn chars to append: "); 
	print_int(nb);

	
	print_str("\n\nORIGINAL FUNCTION: ");
	strncat(dest_orig, src, nb);
	print_str_n_X(dest_orig, d_len);

	print_str("\n\nTEST FUNCTION:     ");
	ft_strncat(dest_test, src, nb);
	print_str_n_X(dest_test, d_len);

	print_str("\n\n---------------------------------------\n\n");
}

// initializes a string array with 1,..,9,0 for num_char elements, 
// then adds null , and fills until len with 'x' (ending with null)
void	init_array_digits_x(char *array, int num_char, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i < num_char)
			array[i] = i % 9 + 1 + '0';
		else
			array[i] = 'x';
		if (i == num_char)
			array[i] = 0;
		i++;
	}	
	array[i] = 0;
}

// prints an integer (can handle min int)
void	print_int(int number)
{
	char	digit;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 1);
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	if (number > 9)
	{
		print_int(number / 10);	
	}
	digit = number % 10 + '0';
	write(1, &digit, 1);
}

// prints n elements, replacing nulls with 'X'
void	print_str_n_X(char *str, int n)
{
	int		i;
	char	print_char;

	i = 0;
	while (i < n)
	{
		if (str[i] == 0)
			print_char = 'X';
		else
			print_char = str[i];
		write(1, &print_char, 1);
		i++;
	}
}

// prints a string, terminating at null
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
