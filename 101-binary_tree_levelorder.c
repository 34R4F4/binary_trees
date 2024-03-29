#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left_height > right_height) ? left_height : right_height);
	}
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure.
 *
 * Return: The depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list node with a given tree node and level.
 * @head: Pointer to the head of the linked list.
 * @tree: Pointer to the binary tree node to store.
 * @level: Depth of the binary tree node.
 *
 * Return: Nothing.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new_node, *temp;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = level;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new_node->next = NULL;
		temp->next = new_node;
	}
}

/**
 * recursion - Recursively traverses the binary tree and stores each node.
 * @head: Pointer to the head of the linked list.
 * @tree: Pointer to the binary tree node to traverse.
 *
 * Return: Nothing.
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Traverses the binary tree in level-order
 *	and performs a function on each node.
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to the function to perform on each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *temp;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			temp = head;
			while (temp != NULL)
			{
				if (count == temp->n)
				{
					func(temp->node->n);
				}
				temp = temp->next;
			}
			count++;
		}
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
}
