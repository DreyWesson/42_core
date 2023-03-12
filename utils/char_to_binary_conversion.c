#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h> 

int	bin_to_char(int** ptr)
{
	static char		c;
	int				byte_idx;
	int				bit_idx;
	int				val;

	byte_idx = 0;
	while (ptr[byte_idx])
	{
		bit_idx = 0;
		while (bit_idx < 8)
		{
			val = ptr[byte_idx][bit_idx];
			if (val == 1)
				c = (c << 1) | 1;
			else if (val == 0)
				c <<= 1;
			bit_idx++;
		}
		printf("\n");
		byte_idx++;
	}
	printf("-> %d", c);
	return (c);
}

int** char_to_bin(char* str)
{
	int** ptr;
	int byte_index;
	int	bit_index;
	int i;

	byte_index = 0;
	while (str[++byte_index]);
	ptr = calloc(byte_index + 1, sizeof(int*));
	if (!ptr)
		return(NULL);
	byte_index = 0;
	while (str[byte_index])
	{
		ptr[byte_index] = calloc(sizeof(int), 8);
		if (!ptr[byte_index])
			return(NULL);
		bit_index = 7;
		i = 0;
		while (bit_index >= 0) {
			ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
			bit_index--;
		}
		byte_index++;
	}
	return (ptr);
}

int	main(void) {
	// char str[5] = "🌍"; // -115
	char str[2] = "H"; // 72
	int** ptr;

	ptr = char_to_bin(str);
	bin_to_char(ptr);
	return (0);
}
