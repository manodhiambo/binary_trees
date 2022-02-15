#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size of the tree
 * If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t num_nodes = 0;

	if (!tree)
		return (0);
	if (tree->left != NULL)
		num_nodes += binary_tree_size(tree->left);
	if (tree->right != NULL)
		num_nodes += binary_tree_size(tree->right);
	return (num_nodes + 1);
}
