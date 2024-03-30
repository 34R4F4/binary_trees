#include "binary_trees.h"

/**
 * array_to_bst - Turns an array into a BST tree.
 * @array: Pointer to the array to be converted.
 * @size: Size of the array.
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (size == 0)
	{
		return NULL;
	}

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return root;
}
