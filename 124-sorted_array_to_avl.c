#include "binary_trees.h"

/**
 * aux_sort - Create the tree using the elements of the sorted array.
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @begin: Starting index of the array.
 * @end: Ending index of the array.
 * Return: Pointer to the root of the AVL tree.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int end)
{
	int mid;
	avl_t *root;

	if (begin > end)
		return (NULL);

	mid = (begin + end) / 2;
	root = (avl_t *)binary_tree_node((binary_tree_t *)parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = aux_sort(root, array, begin, mid - 1);
	root->right = aux_sort(root, array, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - Create an AVL tree from a sorted array.
 * @array: Pointer to the sorted array.
 * @size: Size of the array.
 * Return: Pointer to the root of the AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (aux_sort(NULL, array, 0, (int)size - 1));
}
