#include <stdio.h>
#include "bst.h"

int main(void) {
/*
	BStree bst;
	bst = bstree_ini(1000);
	bstree_insert(bst, key_construct("Once", 1), 11);
	bstree_insert(bst, key_construct("Upon", 22), 2);
	bstree_traversal(bst);
	bstree_insert(bst, key_construct("a", 3), 33);
	bstree_insert(bst, key_construct("Time", 4), 44);
	bstree_insert(bst, key_construct("is", 5), 55);
	bstree_insert(bst, key_construct("filmed", 6), 66);
	bstree_insert(bst, key_construct("in", 7), 77);
	bstree_insert(bst, key_construct("Vancouver", 8), 88);
	bstree_insert(bst, key_construct("!", 99), 9);
	bstree_insert(bst, key_construct("Once", 5), 50);
	bstree_insert(bst, key_construct("Once", 1), 10);
	bstree_traversal(bst);
	bstree_free(bst);
*/
	BStree bst; 
	int size;
	printf("Please enter size of the tree: ");
	scanf(" %d", &size);
	
	bst = bstree_ini(size);
	char name[10];
	char chQuit = 'Y';
	int id,data;
	while (chQuit == 'Y') {
		printf("Enter name id and data separated by a space\n");
		scanf(" %s%d%d", name, &id, &data);
		bstree_insert(bst, key_construct(name,id), data);
		printf("Do you wish to continue? (Y or N) : ");
		scanf(" %c", &chQuit);
		
	}
	bstree_traversal(bst);
	bstree_free(bst);
}
