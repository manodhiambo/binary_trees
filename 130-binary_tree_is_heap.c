#include "binary_trees.h"
/**
 * b_height - return number of nodes of a binary tree
 * @tree: Tree to check
 * Return: Number of nodes
 */
int b_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + b_height(tree->left)
		+ b_height(tree->right));
}
/**
 * is_complete - check if tree is complete
 * @root: Tree to check
 * @index: Initial Level
 * @n_nodes: Max levels into tree
 * Return: 1 is complete or 0 is not
 */
int is_complete(const binary_tree_t *root, int index, int n_nodes)
{
	if (root == NULL)
		return (1);
	if (index >= n_nodes)
		return (0);

	return (is_complete(root->left, 2 * index + 1, n_nodes) &&
		is_complete(root->right, 2 * index + 2, n_nodes));
}
/**
 * is_heap - check if a subtree or tree is perfect
 * @node: Tree or subtree to check
 * Return: 1 is heap or 0 if not
 */
int is_heap(const binary_tree_t *node)
{
	if (!node->left && !node->right)
		return (1);
	if (!node->right)
		return (node->n >= node->left->n);
	if (node->n >= node->left->n
	    && node->n >= node->right->n)
		return ((is_heap(node->left))
			&& (is_heap(node->right)));
	else
		return (0);
}
/**
 * binary_tree_is_heap - function that checks if a binary tree is
 *  a valid Max Binary Heap
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int height = b_height(tree);
	int index = 0;

	if (!tree)
		return (0);

	if (is_complete(tree, index, height) && is_heap(tree))
		return (1);
	return (0);
}
