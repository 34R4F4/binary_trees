#include "binary_trees.h"

/**
 * balance_avl - Rebalances an AVL tree after insertion or deletion.
 * @tree: The root of the AVL tree to rebalance.
 */
void balance_avl(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;

	/* If the tree is empty or has only one node, it is already balanced */
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	/* Balance the left and right subtrees recursively */
	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	/* Check the balance factor of the current node */
	bval = binary_tree_balance((const binary_tree_t *)*tree);

	/* Rebalance the tree if necessary */
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * bst_successor - Finds the successor of a given node in a binary search tree.
 * @node: The node to find the successor for.
 * Return: The value of the successor node.
 */
int bst_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);

	/* Traverse the left subtree to find the successor */
	left = bst_successor(node->left);
	if (left == 0)
		return (node->n);
	return (left);
}

/**
 * bst_remove_type - Removes a node from a binary search tree
 *	based on its children.
 * @root: The node to remove.
 * Return: 0 if it has no children or other value if it has.
 */
int bst_remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{	/* Update parent's pointer to this node */
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{	/* Update parent's pointer to this node */
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{	/* Get the successor value from the right subtree */
		new_value = bst_successor(root->right);
		/* Replace the node value with the successor value */
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The modified tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = bst_remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value of the node to remove.
 * Return: The modified tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);
	/* Rebalance the AVL tree */
	balance_avl(&root_a);
	return (root_a);
}
