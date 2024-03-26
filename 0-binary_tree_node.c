#include "binary_trees.h"


/**
 * binary_tree_node - function creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

binary_tree_t *newBTn = malloc(sizeof(binary_tree_t));

if (!newBTn)
	return (NULL);

newBTn->n = value;
newBTn->left = NULL;
newBTn->right = NULL;
newBTn->parent = parent;

return (newBTn);
}
