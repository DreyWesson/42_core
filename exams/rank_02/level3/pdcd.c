// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e 
// 1$
// $> ./pgcd | cat -e
// $
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	(void)argc;
	int string1 = atoi(argv[1]);
	int string2 = atoi(argv[2]);
	int n;

	if (string1 > string2)
		n = string2;
	else
		n = string1;
	while (n)
	{
		if (string1 % n == 0 && string2 % n == 0)
			break;
		n--;
	}
	

	// if (argc != 3)
	// {
	// 	printf("\n");
	// 	return 0;
	// }
	// if (string1 <= 0 || string2 <= 0)
	// {
	// 	printf("\n");
	// 	return 0;
	// }
	// while (string2 != 0)
	// {
	// 	int temporary = string2;
	// 	string2 = string1 % string2;
	// 	string1 = temporary;
	// }
	printf("%d\n", n);
	return 0;
}