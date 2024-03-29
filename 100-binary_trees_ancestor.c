#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor node, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *ancestor_first, *ancestor_second;

	/* Check if either of the nodes is NULL */
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	/* If both nodes are the same, return one of them */
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	/* Traverse up from the first node's parent */
	ancestor_first = first->parent;
	/* Traverse up from the second node's parent */
	ancestor_second = second->parent;
	/**
	 * If ancestor_first reaches NULL,
	 * or first reaches second's parent,
	 * or second's parent is the root
	 */
	if (ancestor_first == NULL || first == ancestor_second || (
				!ancestor_first->parent && ancestor_second))
	{
		return (binary_trees_ancestor(first, ancestor_second));
	}
	/**
	 * If ancestor_second reaches NULL,
	 * or second reaches first's parent,
	 * or first's parent is the root
	 */
	else if (ancestor_second == NULL || ancestor_first == second || (
				!ancestor_second->parent && ancestor_first))
	{
		return (binary_trees_ancestor(ancestor_first, second));
	}
	/* Recursively call the function with updated ancestors */
	return (binary_trees_ancestor(ancestor_first, ancestor_second));
}
