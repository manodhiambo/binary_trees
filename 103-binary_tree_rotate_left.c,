#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs
 * a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y = NULL;

	if (!tree || !tree->right)
		return (tree);

	x = tree;
	y = tree->right;

	if (!y->left)
		x->right = NULL;
	else
	{
		x->right = y->left;
		y->left->parent = x;
	}

	y->left = x;
	y->parent = x->parent;
	x->parent = y;
	return (y);
}
