#include "binary_trees.h"
#include <stdlib.h>

/**
 * is_bst - Checks if a binary tree is a valid binary search tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value allowed for the tree
 * @max: The maximum value allowed for the tree
 *
 * Return: If the tree is a valid binary search tree, 1.
 *         Otherwise, 0.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * height - Calculates the height of a binary tree
 * @tree: A pointer to the root node of the tree to calculate the height of
 *
 * Return: The height of the binary tree.
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: If the tree is a valid AVL tree, 1.
 *         Otherwise, 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
