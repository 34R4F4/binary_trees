#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t Rsize = 0, Lsize = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		/* Recursively calculate the size of the left and right branches */
		Lsize = binary_tree_size(tree->left);
		Rsize = binary_tree_size(tree->right);
	}
	/* Return the total size, including the current node (root) */
	return (Lsize + Rsize + 1);
}

