#include "binary_trees.h"

/**
 * binary_tree_height - count a height of a binary tree
 * @tree: input entire tree
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_R = 0, h_L = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
	{
		h_L = binary_tree_height(tree->left);
		h_R = binary_tree_height(tree->right);
		return (1 + (h_L > h_R ? h_L : h_R));
	}
	return (0);
}
