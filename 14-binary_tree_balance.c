#include "binary_trees.h"

/**
 * binary_tree_height2 - Function measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height, if tree is NULL, your function must return 0
 */
size_t binary_tree_height2(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height2(tree->left);
	right_height = binary_tree_height2(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Calculate the height of the left and right subtrees */
	size_t left_height = binary_tree_height2(tree->left);
	size_t right_height = binary_tree_height2(tree->right);

	/* Calculate the balance factor */
	return ((int)(left_height - right_height));
}
