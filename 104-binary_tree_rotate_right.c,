#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs
 *  a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *y = NULL;

	if (!tree || !tree->left)
		return (tree);

	x = tree;
	y = tree->left;

	if (!y->right)
		x->left = NULL;
	else
	{
		x->left = y->right;
		y->right->parent = x;
	}

	y->right = x;
	y->parent = x->parent;
	x->parent = y;
	return (y);
}
