#include "binary_trees.h"

/**
 * new_node - Function that creates a new node in a linked list
 * @node: Pointer to the node to be created
 * Return: Pointer to the newly created node
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new = malloc(sizeof(link_t));

	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * _free_queue - Function that frees the nodes in a linked list
 * @head: Head of the linked list
 */
void _free_queue(link_t *head)
{
	link_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * _push - Function that _pushes a node into the queue
 * @node: Node to be _pushed
 * @head: Head of the queue
 * @tail: Tail of the queue
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new = new_node(node);

	if (new == NULL)
	{
		_free_queue(head);
		exit(1);
	}

	(*tail)->next = new;
	*tail = new;
}

/**
 * _pop - Function that _pops a node from the queue
 * @head: Head of the queue
 */
void _pop(link_t **head)
{
	link_t *temp_node;

	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the binary tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				_free_queue(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				_free_queue(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
