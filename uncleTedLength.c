#include "main.h"

/**
 * lengthOfStr - returns the length of a string
 * @obi: string
 *
 * Return: 0
 */

int lengthOfStr(char *obi)
{
	int start;
	int end = 0;

	for (start = 0; obi[start] != '\0'; start++)
	{
		end++;
	}
	return (end);
}
