#include "binary_trees.h"
/**
 * binary_tree_height_add - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height_add(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = 1 + binary_tree_height_add(tree->left);

	height_r = 1 + binary_tree_height_add(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);

}
/**
 * printLevel - print nodes at given level order
 * @tree: pointer to the root node of the tree to measure the height
 * @level: number to refers at level in each point
 * @func: pointer to a function to call for each node.
 * Return: Height or 0 if tree is NULL
 */
void printLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printLevel(tree->left, level - 1, func);
		printLevel(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: Not return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int i = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_add(tree) + 1;

	while (i <= height)
	{
		printLevel(tree, i, func);
		i++;
	}
}
