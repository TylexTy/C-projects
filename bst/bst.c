#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bst.h"

void bstree_insertAgain(BStree bst, Key *key, int data, int i);
void bstree_traversalAgain(BStree bst, int i);

BStree bstree_ini(int size) {
	
	BStree t = malloc(sizeof(BStree));  	
	t->tree_nodes =  malloc (sizeof(Node) * (size+1));
	t->is_free =  malloc (sizeof(unsigned char) * (size+1));
	int i;
	for (i=0; i<size; i++) // loop that makes every array element 1, which means it's free
		t->is_free[i] = 1;
	t->size = size;
	return t;
}

void bstree_insert(BStree bst, Key *key, int data) {
	
	int i = 1;	
	bstree_insertAgain(bst, key, data, i);	// a helper method that uses recursion to insert values
	
}

void bstree_insertAgain(BStree bst, Key *key, int data, int i) {


	// if its free insert values and set it to not free
	if (bst->is_free[i] == 1) {
		bst->tree_nodes[i].key = key;
		bst->tree_nodes[i].data = data;
		bst->is_free[i] = 0;
	}
	// if it's not free and key is less than key in bst, go to left child
	else if (bst->is_free[i] == 0 && key_comp(*key,*bst->tree_nodes[i].key) < 0 && bst->size > 2*i) {
                        bstree_insertAgain((bst),key, data, 2*i);
                }
	// if it's not free and key is larger than key in bst go to right child
        else if (bst->is_free[i] == 0 && key_comp(*key,* bst->tree_nodes[i].key) > 0 && bst->size > 2*i+1) {
                 bstree_insertAgain((bst), key, data, (2*i) + 1);
             }
	else 
		printf("ERROR: tree is full\n");
}

void bstree_traversal(BStree bst) {
	
	int i= 1;
	// a helper function which recursively prints tree inOrder.
	bstree_traversalAgain(bst, i);
	
}

void bstree_traversalAgain(BStree bst, int i) {
	
	// if tehre are values for left child, recursively call function on left child
	if (bst->size > 2*i && bst->is_free[2*i] == 0)
		bstree_traversalAgain(bst, 2*i);
	// print node i, this works implicitly.
	print_node(bst->tree_nodes[i]);
	// if right child has values, recursively call function on right child
	if (bst->size > 2*i+1 && bst->is_free[(2*i)+1] == 0)
		bstree_traversalAgain(bst, (2*i)+1);
}

void bstree_free(BStree bst) {

	// frees values associated with bst.
	free(bst->tree_nodes);
	free(bst->is_free);
	free(bst);

}
