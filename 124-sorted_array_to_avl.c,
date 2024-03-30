#include "binary_trees.h"

/**
 * create_avl_from_sorted_array - Recursively creates an AVL tree from a sorted array.
 * @parent: Parent node of the current node being created.
 * @array: Sorted array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * Return: Pointer to the root of the AVL tree.
 */
avl_t *create_avl_from_sorted_array(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = avl_insert(&parent, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = create_avl_from_sorted_array(root, array, start, mid - 1);
	root->right = create_avl_from_sorted_array(root, array, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 * @array: Sorted array.
 * @size: Size of the array.
 * Return: Pointer to the root of the AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (create_avl_from_sorted_array(NULL, array, 0, (int)(size - 1)));
}
