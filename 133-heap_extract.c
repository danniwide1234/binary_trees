#include "binary_trees.h"

int heap_extract(heap_t **root);
void recurse_extract(heap_t *tree);
heap_t *max(heap_t *tree);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: double pointer to the root node of heap.
 *
 * Return: The value stored in the root node.
 */

int heap_extract(heap_t **root)
{
	int val;

	if (!*root)
		return (0);
	val = (*root)->n;
	if (!(*root)->left)
	{
		val = (*root)->n;
		free(*root);
		*root = NULL;
		return (val);
	}
	recurse_extract(*root);
	return (val);
}

/**
 * recurse_extract - Recursively extracts the max from the tree.
 *
 * @tree: pointer to the root of the tree.
 */

void recurse_extract(heap_t *tree)
{
	heap_t *sub_max, *right_max = NULL;

	if (!tree->left)
		return;
	sub_max = max((tree)->left);
	if (tree->right)
		right_max = max(tree->right);
	if (right_max && right_max->n > sub_max->n)
		sub_max = right_max;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		recurse_extract(sub_max);
}

/**
 * max - Finds the maximum node in a tree.
 *
 * @tree: The pointer to the root of the tree.
 *
 * Return: The node with the maximum value.
 */

heap_t *max(heap_t *tree)
{
	heap_t *current_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max(tree->left);
	if (left_max->n > tree->n)
		current_max = left_max;
	else
		current_max = tree;
	if (tree->right)
	{
		right_max = max(tree->right);
		if (right_max->n > current_max->n)
			current_max = right_max;
		else
			current_max = tree;
	}
	return (current_max);
}
