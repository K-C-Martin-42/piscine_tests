/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex06.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:02 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/18 20:02:15 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char *str);
void	run_test(char *str);
void	print_string(char *string);

int	main(void)
{
	char	true_string[100] = "Some printable characters including 2316 and ,./';<>?\":[]{}|!@#$%^&*()_+-=";
	char	space_string[100] = "String containing the hex representation of 'backspace': \x08 (with some words after)";
	char	newl_string[100] = "A string with \n a new line.";
	char	mix_string[100] = "AStringwithMixedcasewords";
	char	zero_string[100] = "";

	print_string(true_string);
	run_test(true_string);

	print_string(space_string);
	run_test(space_string);

	print_string(newl_string);
	run_test(newl_string);

	print_string(mix_string);
	run_test(mix_string);

	print_string(zero_string);
	run_test(zero_string);
}

void	run_test(char *str)
{
	int		result;

	result = ft_str_is_printable(str);
	if (result == 0)
		write(1, "\nString contains non-printable characters.\n", 43);
	else
		write(1, "\nString contains no non-printable characters.\n", 46);

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
