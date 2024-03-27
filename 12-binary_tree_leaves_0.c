#include "binary_trees.h"

/**
 * binary_tree_leaves - function counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: the number of leaves
 *	A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0, Right = 0, Left = 0;

	if (!tree)
	{
		/* If tree is NULL, the function must return 0 */
		return (0);
	}
	else
	{
		Right = binary_tree_leaves(tree->left);
		Left = binary_tree_leaves(tree->right);
		leaves = Right + Left;
		return ((!Right && !Left) ? leaves + 1 : leaves + 0);
	}
}
