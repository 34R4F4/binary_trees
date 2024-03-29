#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling node of a given node.
 * @node: Pointer to the node to check.
 *
 * Return: Pointer to the sibling node if it exists, otherwise NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If node is NULL or has no parent, it has no sibling */
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	/* If node is the left child, return the right child of its parent */
	if (node->parent->left == node)
	{
		return (node->parent->right);
	}
	/* If node is the right child, return the left child of its parent */
	return (node->parent->left);
}
