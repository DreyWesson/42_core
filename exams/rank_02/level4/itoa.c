// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);


#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr) 
{
    int n = nbr;
    int len = 0;

    if (nbr <= 0)
	    len++;

    while (n) 
    {
        n /= 10;
        len++;
    }
    // get the number length
    // allocate memory and null terminate it
    // if num is zero save '0' into result and return
	// if number is less than zero: put '-' at index zero and re-sign

    char *result = (char *)malloc(sizeof(char) * (len + 1));
    if (result == NULL) 
        return NULL;
    result[len] = '\0';
    if (nbr == 0)
    {
        result[0] = '0';
        return(result);
    }
    if (nbr < 0) 
    {
        result[0] = '-';
        nbr = -nbr;
    }
    while (nbr) 
    {
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return result;
}
