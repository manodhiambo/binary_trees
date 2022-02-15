#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find sibling
 * Return: pointer to the sibling node,
 * or NULL if node has no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;
	binary_tree_t *parent = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	parent = node->parent;
	if ((node == parent->left) && (parent->right != NULL))
		sibling = parent->right;
	else if ((node == parent->right) && (parent->left != NULL))
		sibling = parent->left;
	return (sibling);
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find its uncle
 * Return: uncle node or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *uncle;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	parent = node->parent;
	uncle = binary_tree_sibling(parent);
	return (uncle);
}
