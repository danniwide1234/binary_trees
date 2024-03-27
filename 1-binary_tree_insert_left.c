#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 *
 * @parent: pointer to the node to insert the left child in.
 * @value: The value to store the new node.
 *
 * Return: A pointer to the created node, NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *fresh;

	if (parent == NULL)
		return (NULL);

	fresh = binary_tree_node(parent, value);
	if (fresh == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		fresh->left = parent->left;
		parent->left->parent = fresh;
	}
	parent->left = fresh;

	return (fresh);
}
