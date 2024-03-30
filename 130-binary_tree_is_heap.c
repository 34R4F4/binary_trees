#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right != NULL)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = (int)binary_tree_height(tree->left);

	if (tree->right != NULL)
		right_height = (int)binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * tree_is_perfect - Checks if a tree is perfect
 * A perfect binary tree has the same number of nodes at each level
 * and all its nodes have either 0 or 2 children.
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree if perfect, otherwise 0
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->right != NULL)
	{
		left_height = 1 + tree_is_perfect(tree->left);
		right_height = 1 + tree_is_perfect(tree->right);
		if (left_height == right_height)
			return (left_height);
	}

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_is_perfect(tree) != 0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree
 * Return: 1 if it is a Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	if (binary_tree_is_perfect(tree))
		return (1);

	balance = binary_tree_balance(tree);
	if (balance == 0)
		return (
				binary_tree_is_perfect(tree->left) && binary_tree_is_heap(tree->right));
	if (balance == 1)
		return (
				binary_tree_is_heap(tree->left) && binary_tree_is_perfect(tree->right));

	return (0);
}
