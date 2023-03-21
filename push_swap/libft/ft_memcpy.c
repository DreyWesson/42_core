/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:31:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/29 17:43:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.youtube.com/watch?v=PThPm24wGEo
#include "libft.h"

// typedef struct
// {
// 	char name[256];
// 	int age;
// 	double average;
// } Student;

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
		(*(unsigned char *)(dst + n)) = (*(unsigned char *)(src + n));
	return (dst);
}
// int	main(void)
// {
// 	ft_memcpy(((void *)0), ((void *)0), 3);
// 	return (0);
// }
	// ****** memcpy with string test *******
	// char src[] = "Copy that";
	// char dst [100];
	// char *dst_ptr = ft_memcpy(dst,src,4);
	// printf("%s\n%p\n%p\n", dst, dst_ptr, dst);
	// ******** memcpy with array test *********
	// double src_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	// double dst_arr[5];
	// char *dst_arr_ptr = ft_memcpy(dst_arr, src_arr, 8 * 5);
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
	// ft_memcpy(&student2, &student1, sizeof(Student));
	// printf("%s\n%d\n", student2.name, student2.age);
