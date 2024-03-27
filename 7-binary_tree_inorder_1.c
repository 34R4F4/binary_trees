#include "binary_trees.h"
/**
 * binary_tree_inorder - goes through a binary tree
 *				using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: Nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{

if (!tree || !func)
{
	;
}

stack_t *st = create_stack();  /* Create a stack for node tracking */
const binary_tree_t *current = tree;

while (current || !is_empty(st))
{
	/* Push nodes onto the stack until you reach a left-most leaf */
	while (current)
	{
		push(st, current);
		current = current->left;
	}

	/* Pop the top node, process it, and move to its right subtree */
	current = pop(st);
	func(current->n);
	current = current->right;
}

free_stack(st);  /* Free the stack memory */
}
