#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * is_max_heap - Checks if a binary tree is a max heap
 * @root: Pointer to the root node of the binary tree
 * Return: 1 if the binary tree is a max heap, 0 otherwise
 **/
int is_max_heap(const binary_tree_t *root)
{
	int left_result = 1, right_result = 1;

	if (!root)
		return (0);

	if (root->left)
	{
		if (root->n <= root->left->n)
			return (0);
		left_result = is_max_heap(root->left);
	}

	if (root->right)
	{
		if (root->n <= root->right->n)
			return (0);
		right_result = is_max_heap(root->right);
	}

	return (left_result && right_result);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a heap
 * @tree: Pointer to the root node of the binary tree
 * Return: 1 if the binary tree is a heap, 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int complete = 0;

	if (!tree)
		return (0);

	complete = binary_tree_is_complete(tree);
	if (!complete)
		return (0);

	return (is_max_heap(tree));
}
