#include "binary_trees.h"

/**
 * array_to_bst_recursive - Recursively constructs a BST from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the subarray
 * @end: Index of the last element of the subarray
 * Return: Pointer to the root node of the constructed BST
 */
bst_t *array_to_bst_recursive(int *array, int start, int end)
{
	int mid;


	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	bst_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = array_to_bst_recursive(array, start, mid - 1);
	root->right = array_to_bst_recursive(array, mid + 1, end);

	return (root);
}

/**
 * array_to_bst - Constructs a Binary Search Tree (BST) from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the constructed BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	/* Sort the array (you can use any sorting algorithm here) */
	/* For simplicity, we'll use bubble sort in this example */
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	/* Build the BST recursively */
	return (array_to_bst_recursive(array, 0, size - 1));
}
