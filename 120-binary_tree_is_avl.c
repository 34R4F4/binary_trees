#include "binary_trees.h"
#include <limits.h> /* for INT_MIN and INT_MAX */

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: The tree to measure.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * bal_avl - Auxiliar function to check if each subtree is AVL.
 * @tree: The node that points to the tree to check.
 * @lower: The lower limit of values in the subtree.
 * @upper: The upper limit of values in the subtree.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int upper)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= lower || tree->n >= upper)
		return (0);

	int left_balanced = bal_avl(tree->left, lower, tree->n);
	int right_balanced = bal_avl(tree->right, tree->n, upper);

	if (!left_balanced || !right_balanced)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);
	size_t balancer =
		left_height > right_height ?
		left_height - right_height : right_height - left_height;

	return (balancer <= 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: The node that points to the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bal_avl(tree, INT_MIN, INT_MAX));
}
