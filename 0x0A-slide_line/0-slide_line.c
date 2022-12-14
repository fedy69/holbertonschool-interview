#include "slide_line.h"

/**
 * moveRight - Slides and merges an array of integers to the right
 * @line: Pointer to an array of integers
 * @size: Number of elements in array
 * Return: 1 is success
 */
void moveRight(int *line, size_t size)
{
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (line[i] == 0 && line[j] > 0)
			{
				line[i] += line[j];
				line[j] = 0;
				i += 1;
				break;
			}
			if (line[j] > 0 && line[i] == line[j])
			{
				line[i] += line[j];
				line[j] = 0;
				break;
			}
		}
	}
}

/**
 * moveLeft - Slides and merges an array of integers to the left
 * @line: Pointer to an array of integers
 * @size: Number of elements in array
 * Return: 1 is success
 */
void moveLeft(int *line, size_t size)
{
	int i, j;

	for (i = 0; i < (int) size; i++)
	{
		for (j = i + 1; j < (int) size; j++)
		{
			if (line[i] == 0 && line[j] > 0)
			{
				line[i] += line[j];
				line[j] = 0;
				i -= 1;
				break;
			}
			if (line[j] > 0 && line[i] == line[j])
			{
				line[i] += line[j];
				line[j] = 0;
				break;
			}
		}
	}
}

/**

 * @line: points to an array of integers
 * @size: Number of elements in array
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		moveLeft(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		moveRight(line, size);
		return (1);
	}
	return (0); /* Fail */
}