#include "binary_trees.h"


/**
 * binary_tree_insert_right - function  inserts a node
 *				as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return:  pointer (created node),
 *	or NULL (on failure || parent is NULL)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

binary_tree_t *newRnode;

if (!parent)
	return (NULL);

newRnode = binary_tree_node(parent, value);

if (!newRnode)
	return (NULL);

newRnode->n = value;
newRnode->right = NULL;

if (!parent->right)
{
	newRnode->right = NULL;
	parent->right = newRnode;
}
else
{
	newRnode->right = parent->right;
	newRnode->right->parent = newRnode;
}

parent->right = newRnode;

return (newRnode);
}
