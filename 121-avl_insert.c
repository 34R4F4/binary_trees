#include "binary_trees.h"

/**
 * insert_AVL_node - Recursively insert a node value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @parent: The parent node of the current node being inserted.
 * @new: A double pointer to the newly inserted node.
 * @nval: The value to be inserted into the AVL tree.
 * Return: A pointer to the new root after insertion, otherwise NULL.
 */
avl_t *insert_AVL_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));

	if ((*tree)->n > nval)
	{
		(*tree)->left = insert_AVL_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = insert_AVL_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}

	bval = binary_tree_balance(*tree);

	if (bval > 1 && (*tree)->left->n > nval)
		*tree = binary_tree_rotate_right(*tree);
	else if (bval > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && (*tree)->right->n < nval)
		*tree = binary_tree_rotate_left(*tree);
	else if (bval < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Insert a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the inserted node, or NULL if insertion fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	insert_AVL_node(tree, *tree, &new, value);
	return (new);
}
