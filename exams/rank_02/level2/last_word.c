/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:33:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/03 14:35:21 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *last_word(char *str)
{
		int i = 0;

		while (str[++i]);
		i--;
		while(str[i] == ' ' || (str[i] >= 9 && str[i] == 13))
			i--;
		str[i + 1] = '\0';
		while (i >= 0 && ((str[i] != ',' && str[i] != ' ') || (str[i] >= 9 && str[i] <= 13)))
			i--;
		i++;
		printf("%s\n", &str[i]);
	return (&str[i]);
}
int main(int argc, char ** argv)
{
	if (argc == 2)
		last_word(argv[1]);
	return (0);
}