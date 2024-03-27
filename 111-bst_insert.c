#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree:  double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return:  pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *now, *new;

	if (tree != NULL)
	{
		now = *tree;
		if (now == NULL)
		{
			new = binary_tree_node(now, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < now->n)
		{
			if (now->left != NULL)
				return (bst_insert(&now->left, value));
			new = binary_tree_node(now, value);
			if (new == NULL)
				return (NULL);
			return (now->left = new);
		}
		if (value > now->n)
		{
			if (now->right != NULL)
				return (bst_insert(&now->right, value));
			new = binary_tree_node(now, value);
			if (new == NULL)
				return (NULL);
			return (now->right = new);
		}
	}

	return (NULL);
}
