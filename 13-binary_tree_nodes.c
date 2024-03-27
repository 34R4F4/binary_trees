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

	size_t  parents = 0;

	if (!tree)
	{
		/* If tree is NULL, the function must return 0 */
		return (parents);
	}
	else
	{
		/* check if node is parent? */
		parents += ((tree->left || tree->right) ? 1 : 0);

		/* get though node branches */
		parents += binary_tree_nodes(tree->left);
		parents += binary_tree_nodes(tree->right);

		return (parents);
	}
}
