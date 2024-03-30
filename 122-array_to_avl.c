#include "binary_trees.h"

/**
 * array_to_avl - Converts an array to an AVL tree.
 * @array: The array to be converted.
 * @size: The size of the array.
 * Return: A pointer to the root of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	avl_t *root = NULL;

	if (size == 0 || array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Check for duplicate values */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		/* If no duplicates found, insert the value into AVL tree */
		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
				return (NULL);
		}
	}

	return (root);
}
