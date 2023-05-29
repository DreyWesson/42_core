/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:39:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/29 08:10:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_valid(char *str)
{
	char	*s;
	int		len;
	int		res;

	res = 0;
	len = ft_trim(str, "./");
	while (str[len])
	{
		if (str[len] == '.')
		{
			s = ft_substr(&str[len], 0, 4);
			if (ft_strncmp(s, ".ber", 4) == 0 && !str[len + 4])
				res = 1;
			else
				break ;
		}
		len++;
	}
	if (len == 4)
	{
		ft_error("File name doesn't exist");
		exit(0);
	}
	free(s);
	return (res);
}

int	handle_validation(int argc, char **argv)
{
	if (argc == 1)
		return (ft_error("Too few argument"));
	if (argc > 2)
		ft_warning("Processing the first argument only");
	if (!is_valid(argv[1]))
		return (ft_error("Expecting a .ber file"));
	return (1);
}