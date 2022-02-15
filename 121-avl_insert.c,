#include "binary_trees.h"


/**
 * avl_rotation - applies rotation for insert
 * @tree: double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: No return
 */
void avl_rotation(avl_t **tree, int value)
{
	int balance, check = 1;

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n && check)
		*tree = binary_tree_rotate_right(*tree), check = 0;

	if (balance < -1 && value > (*tree)->right->n && check)
		*tree = binary_tree_rotate_left(*tree), check = 0;

	if (balance > 1 && value > (*tree)->left->n && check)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		check = 0;
	}

	if (balance < -1 && value < (*tree)->right->n && check)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
		check = 0;
	}
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{

	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if (!((*tree)->left))
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
			node = avl_insert(&((*tree)->left), value);

	}
	else if (value > (*tree)->n)
	{
		if (!((*tree)->right))
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
			node = avl_insert(&((*tree)->right), value);
	}

	if (node)
		avl_rotation(tree, value);
	return (node);
}
