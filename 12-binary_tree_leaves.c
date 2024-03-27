#include "binary_trees.h"

/**
 * binary_tree_leaves - function counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: the number of leaves
 *	A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{

/* If tree is NULL, the function must return 0 */
if (!tree)
	return (0);

/* If the node is a leaf (both children are NULL), return 1 */
if (tree->left == NULL && tree->right == NULL)
	return 1;

/* Recursively count the leaves in the left and right subtrees */
size_t left_leaves = binary_tree_leaves(tree->left);
size_t right_leaves = binary_tree_leaves(tree->right);

/* Return the total count of leaves */
return (left_leaves + right_leaves);

}
