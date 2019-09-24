#include <stdio.h>
#include <string.h>
#include "data.h"
#include <stdlib.h>
Key *key_construct(char *in_name, int in_id) {

	Key * k =  malloc (sizeof(Key));
	k->id = in_id;
	k->name = strdup(in_name);	
	return k;
	
}

int key_comp(Key key1, Key key2) {

	int retVal = strcmp(key1.name,key2.name); //compares strings
	if (retVal < 0) { //if key1 < key2
		return -1;	
	}
	else if (retVal == 0) { // if names are the same check ids
		if (key1.id > key2.id) 
			return 1;
		else if (key1.id == key2.id)
			return 0;
		else 
			return -1;
	}
	else {             // else key1 > key2
		return 1;

	}

}

void print_key(Key *key) {

	Key k = *key;
	printf("(%-10s %10d)", k.name, k.id);

}

void print_node(Node node) {

	
	print_key(node.key);
	printf("%5d\n", node.data);

}
