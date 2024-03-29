#include "binary_trees.h"

/**
 * binary_tree_is_full - function checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it is a full 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int L_check = 0, R_check = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			L_check = binary_tree_is_full(tree->left);
			R_check = binary_tree_is_full(tree->right);
			if (L_check == 0 || R_check == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->left && !tree->right)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
