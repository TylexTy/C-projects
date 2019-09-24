#include "data.h"

typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;
typedef BStree_struct * BStree;
void bstree_insert(BStree bst, Key *key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
