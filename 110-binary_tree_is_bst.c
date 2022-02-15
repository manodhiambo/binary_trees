#include "binary_trees.h"
/**
 * isBST - check if each node has in the left a less value than himself
 * @root: node to check
 * @min: min value to check with the node at the left
 * @max: max value to check with the node at the right
 * Return: 1 if is a BST or 0 otherwise
 */
int isBST(const binary_tree_t *root,
	   const binary_tree_t *min, const binary_tree_t *max)
{
	if (root == NULL)
		return (1);

	if (min != NULL && root->n <= min->n)
		return (0);

	if (max != NULL && root->n >= max->n)
		return (0);

	return (isBST(root->left, min, root) &&
		isBST(root->right, root, max));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a nid Binary Search Tree
 * @tree: a pointer to the node node of the tree to check
 * Return: 1 if tree is a nid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isBST(tree, NULL, NULL));
}
