/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:25:56 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/17 15:59:29 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);
void	run_test(char *str);
void	print_string(char *string);

int	main(void)
{
	char	alpha_string[100] = "Teststringcontainingonlyalphachars";
	char	space_string[100] = "Test string with spaces";
	char	mix_string[100] = "Teststringcontainingsomenumbers1234";
	char	zero_string[100] = "";

	print_string(alpha_string);
	run_test(alpha_string);

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

	result = ft_str_is_alpha(str);
	if (result == 0)
		write(1, "\nString contains non-alphabet characters.\n", 42);
	else
		write(1, "\nString contains only alphabet characters.\n", 43);

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
