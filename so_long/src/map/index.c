/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:33:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * [✅] only contains "01CEP"
 * [✅] must contain only one /E/P
 * [✅] all first & last row and first & last cols are 1s ELSE return error
 * [✅] must be rectangular ie the num of cols must be greater than rows
 * [✅] If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way
 * [🔴] check if there’s a valid path in the map.
 * 		make sure all collectibles and exit are accessible
 * 		by checking if its all surrounded by 1s
 */
/**
 * When you encounter C/E make sure P can access it
 * check if P is above or below or same line
 * check if the next lines are not sealed
*/
void handle_map(char **argv)
{
	char **ptr;
	int line_nbr;

	line_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], line_nbr);
	validate_map(ptr, line_nbr);
}
