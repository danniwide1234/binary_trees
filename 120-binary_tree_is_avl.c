#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t keg, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		keg = height(tree->left);
		rhgt = height(tree->right);
		diff = keg > rhgt ? keg - rhgt : rhgt - keg;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t m = 0, n = 0;

		m = tree->left ? 1 + height(tree->left) : 1;
		n = tree->right ? 1 + height(tree->right) : 1;
		return ((m > n) ? m : n);
	}
	return (0);
}
