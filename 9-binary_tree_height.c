#include "binary_trees.h"

/**
 * binary_tree_height - Function measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height, if tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t L_branch = 0;
	size_t R_branch = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			/** get branchs length using recursion */
			L_branch = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			R_branch = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		/** return longest branch */
		return ((L_branch > R_branch) ? L_branch : R_branch);
	}
}
