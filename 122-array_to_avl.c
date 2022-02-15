#include "binary_trees.h"


/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (!array || size < 1)
		return (NULL);

	avl_insert(&tree, array[0]);

	for (i = 1; i < size; i++)
		avl_insert(&tree, array[i]);

	return (tree);
}
