#include "binary_trees.h"

/**
 * check_SUBtree_Right - Checks
 *	if all nodes in the subtree are greater than the root.
 * @node: Node in the subtree to verify.
 * @min: Value to compare with.
 * Return: 1 if all nodes are greater or equal, 0 otherwise.
 */
int check_SUBtree_Right(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_SUBtree_Right(node->left, min);
		right = check_SUBtree_Right(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * check_SUBtree_Left - Checks
 *	if all nodes in the subtree are smaller or equal to the root.
 * @node: Node in the subtree to verify.
 * @max: Value to compare with.
 * Return: 1 if all nodes are smaller or equal, 0 otherwise.
 */
int check_SUBtree_Left(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_SUBtree_Left(node->left, max);
		right = check_SUBtree_Left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 * @tree: Root node of the tree.
 * Return: 1 if it is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_SUBtree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_SUBtree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
