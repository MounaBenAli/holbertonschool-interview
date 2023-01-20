#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Basic Binary Tree*/
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/*AVL Tree*/
typedef struct binary_tree_s avl_t;

/*AVL - From sorted array function & helpers*/
avl_t *tree_from_array(int *array, int left, int right, avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);
void binary_tree_print(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */