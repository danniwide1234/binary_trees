#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 *
 * @array: pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: pointer to the root node of the created one, NULL on failure.
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int count;
	heap_t *root = NULL;

	for (count = 0; count < size; count++)
		heap_insert(&root, array[count]);

	return (root);
}
