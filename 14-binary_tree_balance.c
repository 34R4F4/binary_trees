#include "binary_trees.h"

/**
 * binary_tree_height2 - Function measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height, if tree is NULL, your function must return 0
 */

size_t binary_tree_height2(const binary_tree_t *tree)
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
			L_branch = tree->left ? 1 + binary_tree_height2(tree->left) : 0;
			R_branch = tree->right ? 1 + binary_tree_height2(tree->right) : 0;
		}
		/** return longest branch */
		return ((L_branch > R_branch) ? L_branch : R_branch);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height2(tree->left));
		right = ((int)binary_tree_height2(tree->right));
		total = left - right;
	}
	return (total);
}
