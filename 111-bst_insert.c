#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = NULL, *parent = NULL, *node = NULL;
	int lr = 0;

	if (!tree)
		return (NULL);

	current = *tree;

	node = binary_tree_node(current, value);
	if (!node)
		return (NULL);

	if (!current)
	{
		*tree = node;
		return (node);
	}
	while (1)
	{
		parent = current;

		if (value < parent->n)
			current = current->left, lr = 0;
		else if (value > parent->n)
			current = current->right, lr = 1;
		else
			break;

		if (!current)
		{
			if (lr == 0)
				parent->left = node;
			else
				parent->right = node;
			node->parent = parent;
			return (node);
		}
	}
	free(node);
	return (NULL);
}
