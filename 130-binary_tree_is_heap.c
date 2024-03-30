#include "binary_trees.h"

size_t BT_size(const binary_tree_t *tree);
heap_t *find_parent(heap_t *root, size_t number);
heap_t *keep_max(heap_t *new, heap_t *parent)

/**
 * heap_insert - Insert a value into a max binary heap
 * @tree: Double pointer to the root of the heap
 * @value: Value to insert
 * Return: Pointer to the created node
 */
heap_t *heap_insert(heap_t **tree, int value)
{
    size_t size;
    int doswap = 1;
    heap_t *new, *parent;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        new = binary_tree_node(NULL, value);
        *tree = new;
        return (new);
    }

    size = BT_size(*tree);
    parent = find_parent(*tree, (size - 1) / 2);
    new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    if (size % 2 == 1)
        parent->left = new;
    else
        parent->right = new;

    while (doswap == 1 && parent != NULL)
    {
        if (parent->n >= new->n)
            doswap = 0;
        else
        {
            new = keep_max(new, parent);
            parent = new->parent;
        }
    }

    return (new);
}

/**
 * BT_size - Measure the size of a binary tree
 * @tree: Pointer to the root of the tree
 * Return: Size of the tree
 */
size_t BT_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + BT_size(tree->left) + BT_size(tree->right));
}

/**
 * find_parent - Find the parent node in a binary tree
 * @root: Pointer to the root of the tree
 * @number: Index of the parent node to find
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root, size_t number)
{
    size_t parentn, dir;

    if (number == 0)
        return (root);

    parentn = (number - 1) / 2;
    dir = (number - 1) % 2;

    if (dir == 0)
        return (find_parent(root, parentn)->left);
    return (find_parent(root, parentn)->right);
}

/**
 * keep_max - Swap nodes to maintain the max heap property
 * @new: Pointer to the new node
 * @parent: Pointer to the parent node
 * Return: Pointer to the parent node
 */
heap_t *keep_max(heap_t *new, heap_t *parent)
{
    int tmp;

    tmp = new->n;
    new->n = parent->n;
    parent->n = tmp;
    return (parent);
}
