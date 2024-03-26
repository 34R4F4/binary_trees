#include "binary_trees.h"
/**
 * binary_tree_preorder - function  goes through a binary tree
 *							using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *		The value in the node must be passed as a parameter to this function.
 * Return: 1 if node is a root, otherwise 0
 *		If node is NULL, return 0
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (!tree || !func)
{
	;
}
else
{
	/* current node value */
	func(tree->n);

	/* Traverse the left subtree recursively */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
}
