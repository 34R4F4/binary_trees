#include "binary_trees.h"

/**
 * bst_insert - Inserts nodes to create a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the BST.
 * @value: Value of the node to insert.
 * Return: Pointer to the new node inserted.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current_node;
	binary_tree_t *binary_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		/* Create a new node and assign it as the root */
		binary_node = binary_tree_node((binary_tree_t *)(*tree), value);
		new_node = (bst_t *)binary_node;
		*tree = new_node;
	}
	else
	{
		current_node = *tree;

		if (value < current_node->n)
		{
			if (current_node->left)
				new_node = bst_insert(&current_node->left, value);
			else
			{
				/* Create a new left child node */
				binary_node = binary_tree_node((binary_tree_t *)current_node, value);
				new_node = current_node->left = (bst_t *)binary_node;
			}
		}
		else if (value > current_node->n)
		{
			if (current_node->right)
				new_node = bst_insert(&current_node->right, value);
			else
			{
				/* Create a new right child node */
				binary_node = binary_tree_node((binary_tree_t *)current_node, value);
				new_node = current_node->right = (bst_t *)binary_node;
			}
		}
		else
			return (NULL);
	}

	return (new_node);
}
