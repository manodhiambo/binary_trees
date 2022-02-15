#include "binary_trees.h"

/**
 * binary_tree_height_B - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height_B(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height_B(tree->left);

	if (tree->right)
		height_r = 1 + binary_tree_height_B(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height_B(tree->left);
	if (tree->right)
		height_r = 1 + binary_tree_height_B(tree->right);

	return (height_l - height_r);
}
