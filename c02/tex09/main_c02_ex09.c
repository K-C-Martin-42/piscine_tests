/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c02_ex09.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:08:58 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/19 11:49:57 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str);
void	print_string(char *str);

int	main(void)
{
	char test_string[100] = "Salut, coMMent tu vas ? 42Mots quarantE-Deux; cinquante+ET+un";
	char *result;

	print_string(test_string);
	result = ft_strcapitalize(test_string);
	print_string(result);
}


void	print_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
