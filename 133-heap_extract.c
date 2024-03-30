#include "binary_trees.h"

/**
 * count_heap_nodes - Counts the number of nodes inside a heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Number of nodes in the heap
 */
int count_heap_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_heap_nodes(root->left) +
		    count_heap_nodes(root->right));
}

/**
 * bubble_down - Puts a node value in the correct position in the heap
 * @parent: Pointer to the parent node of the heap
 */
void bubble_down(heap_t *parent)
{
	int temp;
	heap_t *max_child = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		max_child = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			max_child = parent->right;

		if (max_child->n > parent->n)
		{
			temp = parent->n;
			parent->n = max_child->n;
			max_child->n = temp;
		}

		parent = max_child;
	}
}

/**
 * find_parent - Finds the parent node for a given node in the heap
 * @root: Pointer to the root node of the heap
 * @index: Index of the current node
 * @pind: Index being searched for
 *
 * Return: Pointer to the parent node of the heap
 */
heap_t *find_parent(heap_t *root, int index, int pind)
{
	heap_t *left = NULL, *right = NULL;

	if (!root || index > pind)
		return (NULL);

	if (index == pind)
		return (root);

	left = find_parent(root->left, index * 2 + 1, pind);
	if (left)
		return (left);

	right = find_parent(root->right, index * 2 + 2, pind);
	if (right)
		return (right);

	return (NULL);
}

/**
 * remove_last_node - Removes the last node of a heap
 * @root: Double pointer to the root node of the heap
 * @parent: Pointer to the parent node from which to remove the last node
 */
void remove_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	bubble_down(*root);
}

/**
 * heap_extract - Extracts the maximum value of a heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Maximum value of the heap
 */
int heap_extract(heap_t **root)
{
	int nodes, pind = 0, max_val = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	max_val = (*root)->n;
	nodes = count_heap_nodes(*root);

	pind = (nodes - 2) / 2;
	parent = find_parent(*root, 0, pind);

	remove_last_node(root, parent);

	return (max_val);
}
