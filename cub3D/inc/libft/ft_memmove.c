/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:13:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/write-memcpy/
// typedef struct
// {
// 	char name[256];
// 	int age;
// 	double average;
// } Student;
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	i = n;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (--i >= 0)
			(*(char *)(dst + i)) = (*(char *)(src + i));
	else
	{
		i = 0;
		while (i < (int)n)
		{
			(*(char *)(dst + i)) = (*(char *)(src + i));
			i++;
		}
	}
	return (dst);
}
// int	main(void)
// {
// 	// char src[] = "Copy that gsghuuwu";
// 	// char dst [100];
// 	// ft_memmove(dst,src,4);
// 	// printf("two: %p\t%p\t%li\n", dst,src, dst-src);
// 	        char b[0xF0];
//         ft_memmove(((void *)0), b, 5);
// 	return (0);
// }
	// ****** memcpy with string test *******
	// ****** memcpy with string test 2 *******
	// char csrc[100] = "Geeksfor"; 
	// char *dest = ft_memmove(csrc+5, csrc, strlen(csrc)+1);
	// printf("%s\t%s\n", csrc, dest); 
	// ******** memcpy with array test *********
	// double src_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	// double dst_arr[5];
	// char *dst_arr_ptr = ft_memmove(dst_arr, src_arr, 8 * 5);
	// printf("%p\n%p\n", dst_arr_ptr, dst_arr);
	// for (int i = 0; i < 5; i++){
	// 	printf("%f\n", dst_arr[i]);
	// }
	// ******** memcpy with struct *********
	// Student student1;
	// strcpy(student1.name, "drey");
	// student1.age = 33;
	// student1.average = 99.9;
	// Student student2;
	// ft_memmove(&student2, &student1, sizeof(Student));
	// printf("%s\n%d\n", student2.name, student2.age);
