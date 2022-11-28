/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex07.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:04:47 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/17 18:47:43 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str);
void	print_string(char *str);
void	run_test(char *str);

int	main(void)
{
	// ASSUMING THAT ONLY CHAR ARRAYS, NOT STRING LITERALS, WILL BE PASSED!
	char	low_string[100] = "alowercasestring";
	char	mix_string[100]	= "A String with spaces, mixed-case and punctuation.";
	char	upp_string[100] = "ANUPPERCASESTRINGALREADY";
	char	num_string[100] = "1234567890";
	char	nul_string[100] = "";

	run_test(low_string);
	
	run_test(mix_string);

	run_test(upp_string);

	run_test(num_string);

	run_test(nul_string);
}


void	run_test(char *str)
{
	char	*result_ptr;

	print_string(str);
	result_ptr = ft_strupcase(str);
	print_string(result_ptr);
}

void	print_string(char *str)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
