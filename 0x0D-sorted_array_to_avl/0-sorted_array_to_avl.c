#include "binary_trees.h"

/**
 * tree_from_array - recursive function that builds
 * an AVL tree (Adelson-Velsky and Landis tree) from an array
 * @array: pointer to array
 * @left: first element
 * @right: last element
 * @parent: parent node
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 **/
avl_t *tree_from_array(int *array, int left, int right, avl_t *parent)
{
int midpoint;
avl_t *root_node;


if (left > right)
return (NULL);

midpoint = (left + right) / 2;

root_node = malloc(sizeof(avl_t));
if (!root_node)
return (NULL);

root_node->n = array[midpoint];
root_node->parent = parent;
root_node->left = tree_from_array(array, left, midpoint - 1, root_node);
root_node->right = tree_from_array(array, midpoint + 1, right, root_node);
return (root_node);
}

/**
 * sorted_array_to_avl - function that converts a sorted array to an AVL tree
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{

if (!array)
return (NULL);

return (tree_from_array(array, 0, size - 1, NULL));
}
