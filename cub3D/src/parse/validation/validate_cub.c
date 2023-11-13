/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:54:45 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 14:48:02 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	check_len(int len)
{
	if (len == 4)
	{
		ft_error("File name doesn't exist");
		exit(0);
	}
}

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trim(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	return (start);
}

int	is_valid_exe(char *str, char *exe)
{
	char	*s;
	int		len;
	int		res;
	int		exe_len;

	res = 0;
	s = NULL;
	len = ft_trim(str, "./");
	exe_len = ft_strlen(exe);
	while (str[len])
	{
		if (str[len] == '.')
		{
			s = ft_substr(&str[len], 0, exe_len);
			if (ft_strncmp(s, exe, exe_len) == 0 && !str[len + exe_len])
				res = 1;
			else
				break ;
		}
		len++;
	}
	check_len(len);
	free(s);
	return (res);
}
