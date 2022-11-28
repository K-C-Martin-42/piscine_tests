/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:06:30 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/17 16:10:48 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str);
void	run_test(char *str);
void	print_string(char *string);

int	main(void)
{
	char	num_string[100] = "0123456789";
	char	space_string[100] = "123 456 789";
	char	mix_string[100] = "1234word";
	char	zero_string[100] = "";

	print_string(num_string);
	run_test(num_string);

	print_string(space_string);
	run_test(space_string);

	print_string(mix_string);
	run_test(mix_string);

	print_string(zero_string);
	run_test(zero_string);
}

void	run_test(char *str)
{
	int		result;

	result = ft_str_is_numeric(str);
	if (result == 0)
		write(1, "\nString contains non-numeric characters.\n", 42);
	else
		write(1, "\nString contains only numeric characters.\n", 43);

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
