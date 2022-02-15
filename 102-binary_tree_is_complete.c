include "binary_trees.h"
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
 * runLevel - print nodes at given level order
 * @tree: pointer to the root node of the tree to measure the height
 * @level: number to refers at level in each point
 * @last: variable to know if in last level of tree
 * @left: checks if for semilast level node can be on left
 * @ch: true or false for complete tree
 * @prev: helps checks if node is leftmost when having childs
 *
 * Return: Height or 0 if tree is NULL
 */
void runLevel(const binary_tree_t *tree, int level, int last,
	      int *left, int *ch, int *prev)
{
	if (!tree)
		return;

	if (level == 1 && last != 1)
	{
		if (tree->left && !(tree->right) && !last)
			*ch = 0;

		if (tree->right && !(tree->left) && !last)
			*ch = 0;

		if (!(tree->left) && !(tree->right) && !last)
			*ch = 0;

		if ((tree->left || tree->right) && last && *prev)
			*ch = 0;

		if (!(tree->left) && !(tree->right) && last)
			*prev = 1;

		if (tree->left && !(*left) && last)
			*ch = 0;

		if (tree->left && last)
			*left = 0;

		if (tree->right && (*left) && last)
			*ch = 0;

		if (tree->right && !(*left) && last)
			*left = 1;
	}

	else if (level > 1)
	{
		runLevel(tree->left, level - 1, last, left, ch, prev);
		runLevel(tree->right, level - 1, last, left, ch, prev);
	}
}
/**
 * binary_tree_is_complete - checks if a tree is complete
 * @tree: a pointer to the root node of the tree to traverse
 * Return: 1 if complete, 0 if not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int height, i, check = 1, last = 0, left = 1, prev = 0;

	if (!tree)
		return (0);

	/** Last = 1, SemiLast = 2 **/

	height = binary_tree_height_add(tree);

	for (i = 1; i <= height && check; i++)
	{
		if (i == height - 1)
			last = 2;
		else if (i == height)
			last = 1;
		runLevel(tree, i, last, &left, &check, &prev);
	}

	return (check);
}
