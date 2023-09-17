/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:54:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/18 06:41:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

void	default_quant(t_quant *quant)
{
	quant->collectibles = 0;
	quant->exit = 0;
	quant->player = 0;
}
