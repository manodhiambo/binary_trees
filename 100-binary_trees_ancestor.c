#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the
 * two given nodes or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t const *tmpf = NULL, *tmps = NULL;

	if (!first || !second)
		return (NULL);

	for (tmpf = first; tmpf; tmpf = tmpf->parent)
		for (tmps = second; tmps; tmps = tmps->parent)
			if (tmpf == tmps)
				return ((binary_tree_t *)tmpf);
	return (NULL);
}
