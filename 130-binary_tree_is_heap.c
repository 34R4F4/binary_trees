#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if the tree is a complete binary tree */
    if (!is_complete_tree(tree, 0, binary_tree_size(tree)))
        return (0);

    /* Check if the tree satisfies the Max Heap property */
    return (is_max_heap(tree));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete_tree - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root of the tree
 * @index: Index of the current node
 * @size: Size of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_tree(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (is_complete_tree(tree->left, 2 * index + 1, size) &&
            is_complete_tree(tree->right, 2 * index + 2, size));
}

/**
 * is_max_heap - Checks if a binary tree satisfies the Max Heap property
 *
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if the tree satisfies the Max Heap property, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);

    /* Check if the value at the root is greater than or equal to the values of its children */
    if ((tree->left && tree->n < tree->left->n) ||
        (tree->right && tree->n < tree->right->n))
        return (0);

    /* Recursively check the Max Heap property for left and right subtrees */
    return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
