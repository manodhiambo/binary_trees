#include "binary_trees.h"
/**
 * recursive_succ - min value into the right subtree of node to delete
 * @node: node to find succesor before to delete
 * Return: the min value of subtree
 */
int recursive_succ(bst_t *node)
{
	int l_val = 0;

	if (node == NULL)
	{
		return (0);
	}

	l_val = recursive_succ(node->left);
	if (l_val == 0)
	{
		return (node->n);
	}
	return (l_val);

}
/**
 * assignment - function to get the succesor and change value
 * with the current node
 * @root: node to check because has two childs
 * Return: Value of node founded
 */
int assignment(bst_t *root)
{
	int node_value = 0;

	node_value = recursive_succ(root->right);
	root->n = node_value;
	return (node_value);
}
/**
 * remove_node - look for node to delete and do
 * connections for each node after deletion
 * @root: Node to delete
 * Return: Value of node to delete by recursion
 * or 0 if node was deleted
 */
int remove_node(bst_t *root)
{
	if (root->left && root->right)
	{
		return (assignment(root));
	}
	else if ((!root->left && root->right) || (root->left && !root->right))
	{
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		else
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
	}
	else
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
	}
	free(root);
	return (0);
}
/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where you
 * will remove a node
 * @value: is the value to remove in the tree
 * Return: pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int val = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		val = remove_node(root);
		if (val != 0)
			bst_remove(root->right, val);
	}
	else
		return (NULL);
	return (root);
}
