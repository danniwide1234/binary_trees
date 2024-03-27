#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *storage;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	storage = pivot->right;
	pivot->right = tree;
	tree->left = storage;
	if (storage != NULL)
		storage->parent = tree;
	storage = tree->parent;
	tree->parent = pivot;
	pivot->parent = storage;
	if (storage != NULL)
	{
		if (storage->left == tree)
			storage->left = pivot;
		else
			storage->right = pivot;
	}

	return (pivot);
}
