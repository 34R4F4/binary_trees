#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node of a given node.
 * @node: Pointer to the node to check.
 *
 * Return: Pointer to the uncle node if it exists, otherwise NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node, its parent, and its grandparent exist */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	/**
	 * If node's parent is the left child of its grandparent
	 * return the right child
	 */
	if (node->parent->parent->left == node->parent)
	{
		return (node->parent->parent->right);
	}
	/**
	 * If node's parent is the right child of its grandparent
	 * return the left child
	 */
	return (node->parent->parent->left);
}
