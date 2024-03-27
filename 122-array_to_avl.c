#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: pointer to the root node of the created AVL tree, NULL on failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, kndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (kndex = 0; kndex < index; kndex++)
		{
			if (array[kndex] == array[index])
				break;
		}
		if (kndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
