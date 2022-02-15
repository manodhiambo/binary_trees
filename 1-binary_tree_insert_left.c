#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as the left-child of
 * another node
 * @parent: parent of the node at left-insert
 * @value: value of the new node
 * Return: updated tree
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left = NULL;

	new_left = malloc(sizeof(binary_tree_t));
	if (!new_left)
		return (NULL);
	new_left->n = value;
	new_left->right = NULL;
	new_left->left = NULL;

	if (!parent)
	{
		free(new_left);
		return (NULL);
	}
	new_left->parent = parent;
	if (parent->left)
	{
		new_left->left = parent->left;
		new_left->left->parent = new_left;
	}
	parent->left = new_left;
	return (new_left);
}
