#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, k;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (k = 0; k < width; k++)
		s[depth][offset + left + k] = b[k];
	if (depth && is_left)
	{
		for (k = 0; k < width + right; k++)
			s[depth - 1][offset + left + width / 2 + k] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (k = 0; k < left + width; k++)
			s[depth - 1][offset - width / 2 + k] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: height of the tree starting at @node
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t height_a;
	size_t height_b;

	height_a = tree->left ? 1 + _height(tree->left) : 0;
	height_b = tree->right ? 1 + _height(tree->right) : 0;
	return (height_a > height_b ? height_a : height_b);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, y, z;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (y = 0; y < height + 1; y++)
	{
		s[y] = malloc(sizeof(**s) * 255);
		if (!s[y])
			return;
		memset(s[y], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (y = 0; y < height + 1; y++)
	{
		for (z = 254; z > 1; --z)
		{
			if (s[y][z] != ' ')
				break;
			s[y][z] = '\0';
		}
		printf("%s\n", s[y]);
		free(s[y]);
	}
	free(s);
}
