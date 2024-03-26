#include "binary_trees.h"


/**
 * binary_tree_insert_left - function  inserts a node
 *				as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return:  pointer (created node),
 *	or NULL (on failure || parent is NULL)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

binary_tree_t *newLnode;

if (!parent)
	return (NULL);

newLnode = binary_tree_node(parent, value);

if (!newLnode)
	return (NULL);

newLnode->n = value;
newLnode->right = NULL;

if (!parent->left)
{
	newLnode->left = NULL;
	parent->left = newLnode;
}
else
{
	newLnode->left = parent->left;
	newLnode->left->parent = newLnode;
}

parent->left = newLnode;

return (newLnode);
}
