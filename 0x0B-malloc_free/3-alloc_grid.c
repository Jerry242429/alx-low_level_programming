#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **me;
	int a, b;

	if (width <= 0 || height <= 0)
		return (NULL);

	me = malloc(sizeof(int *) * height);

	if (me == NULL)
		return (NULL);

	for (a = 0; a < height; a++)
	{
		me[a] = malloc(sizeof(int) * width);

		if (me[a] == NULL)
		{
			for (; a >= 0; a--)
				free(me[a]);

			free(me);
			return (NULL);
		}
	}

	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
			me[a][b] = 0;
	}

	return (me);
}
