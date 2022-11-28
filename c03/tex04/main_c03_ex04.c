/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c03_ex04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:25:04 by kmartin           #+#    #+#             */
/*   Updated: 2022/11/19 00:10:06 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);
void	run_test(char *haystack, char *needle);
void	print_str_or_null(char *str);

int	main(void)
{
	char 	*haystack = "This is the song that never ends - or if it ends, I don't remember.";
	char	*nullstack = "";
	char	*s_null = "";
	char	*s_hit = "end";
	char	*s_miss = "ended";
	char	*s_over	= "ember";

	run_test(nullstack, s_null);

	run_test(haystack, s_null);

	run_test(nullstack, s_hit);

	run_test(haystack, s_hit);

	run_test(haystack, s_miss);

	run_test(haystack, s_over);
}

void	run_test(char *haystack, char *needle)
{
	print_str_or_null("\n\nNeedle: ");
	print_str_or_null(needle);
	print_str_or_null("\nHaystack: ");
	print_str_or_null(haystack);

	print_str_or_null("\n\nORIGINAL FUNCTION: ");
	print_str_or_null(strstr(haystack, needle));

	print_str_or_null("\nTEST FUNCTION:     ");
	print_str_or_null(ft_strstr(haystack, needle));
}

void	print_str_or_null(char *str)
{
	int i;

	i = 0;
	if (str == 0)
		write(1, "NULL", 4);
	else if (str[i] == 0)
		write(1, &str[i], 1);
	while (str != 0 && str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}
