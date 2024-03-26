#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (!tree || !func)
	return;

/* Create a stack to hold the nodes */
const binary_tree_t **stack = malloc(sizeof(binary_tree_t *) * 1000);
/*size as needed */

if (stack == NULL)
	return;

int top = -1; /* Initialize stack top */

const binary_tree_t *current = tree;

/* Traverse the tree iteratively */
while (current != NULL || top != -1)
{
	/* Reach the leftmost node of the current node */
	while (current != NULL)
	{
		stack[++top] = current;
		current = current->left;
	}

	/* Current is NULL, backtrack to the parent node */
	current = stack[top--];

	/* Call the function for the current node */
	func(current->n);

	/* Move to the right subtree */
	current = current->right;
}

free(stack);
}
