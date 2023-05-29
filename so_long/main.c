/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/29 07:45:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "./inc/so_long.h"

int	main(int argc, char **argv)
{

	if (!handle_validation(argc, argv))
		return (0);
	handle_map(argv);

	return (0);
}
