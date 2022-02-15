#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the
 * right-child of another node
 * @parent: parent of the node at right-insert
 * @value: value of the new node
 * Return: updated tree
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right = NULL;

	new_right = malloc(sizeof(binary_tree_t));
	if (!new_right)
		return (NULL);
	new_right->n = value;
	new_right->left = NULL;
	new_right->right = NULL;

	if (!parent)
	{
		free(new_right);
		return (NULL);
	}
	new_right->parent = parent;
	if (parent->right)
	{
		new_right->right = parent->right;
		new_right->right->parent = new_right;
	}
	parent->right = new_right;
	return (new_right);
}
