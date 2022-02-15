#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree->n != value)
	{
		if (tree->n > value)
			tree = tree->left;
		else
			tree = tree->right;
		if (!tree)
			return (NULL);
	}
	return ((bst_t *)tree);
}
