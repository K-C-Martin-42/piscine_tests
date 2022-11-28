/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:06:30 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/17 16:36:04 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_uppercase(char *str);
void	run_test(char *str);
void	print_string(char *string);

int	main(void)
{
	char	up_string[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	space_string[100] = "UPPERCASE WORDS WITH SPACES";
	char	mix_string[100] = "AStringwithMixedcasewords";
	char	zero_string[100] = "";

	print_string(up_string);
	run_test(up_string);

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

	result = ft_str_is_uppercase(str);
	if (result == 0)
		write(1, "\nString contains non-uppercase alphabetical characters.\n", 56);
	else
		write(1, "\nString contains no non-uppercase alphabetical characters.\n", 59);

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
