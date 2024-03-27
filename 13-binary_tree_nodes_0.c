#include "binary_trees.h"
/**
 * binary_tree_nodes - function counts the nodes
 *						with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes with children
 *	A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

/* If tree is NULL, the function must return 0 */
if (tree == NULL)
	return 0;

/* If the node has at least one child, count it */
if (tree->left != NULL || tree->right != NULL)
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

/* Otherwise, it's a leaf node with no children */
return 0;
}
