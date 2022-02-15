#include "binary_trees.h"

/**
 * _pow - raises base to the power of exp
 * @base: base number
 * @exp: power to be raised to of base number
 * Return: math answer
 */
long int _pow(int base, int exp)
{
	int up;
	long int res;

	res = base;
	for (up = 0; up < exp; up++)
		res *= base;
	return (res);
}

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

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to root node of the tree to check
 * Return: 1 if tree is perfect,
 * otherwise, function return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	unsigned int height = 0;
	unsigned int num_nodes = 0;

	if (!tree)
		return (0);
	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);
	height = binary_tree_height(tree);
	num_nodes = binary_tree_size(tree);
	if (num_nodes == _pow(2, height) - 1)
		return (1);
	else
		return (0);
}
