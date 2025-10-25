#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "/home/jack/develop/c/lib/datastructs-c/arraylist.h"
/*
 * algorithm of random get a element in array list
 * 1) generate a random number of which the range is 0 to size of arrylist
 * 2) call the function which called remove in arrylist and will return the
 * elemenand then remove it of which the index is generated just
 */

int main() {
    arraylist *l = arraylist_create();
    arraylist_add(l, "a");
    arraylist_add(l, "b");
    arraylist_add(l, "c");
    arraylist_add(l, "d");
    arraylist_add(l, "e");
    arraylist_add(l, "f");
    arraylist_add(l, "g");
    arraylist_add(l, "h");
    arraylist_add(l, "i");
    arraylist_add(l, "j");
    arraylist_add(l, "k");
    arraylist_add(l, "l");
    arraylist_add(l, "m");
    arraylist_add(l, "n");
    arraylist_add(l, "o");
    /* char *a=arraylist_pop(l); */
    printf("size is %d\n", arraylist_size(l));
    printf("size is %d\n", arraylist_size(l));
    /* printf("%s\n", a); */

    int totalsize = arraylist_size(l);
    srand(time(NULL));
    int currentsize = totalsize;
    for (int i = 0; i < totalsize; i++) {
	int index = rand() % (currentsize);
	/* printf("rand index is %d\n", index); */
	char *a = arraylist_remove(l, index);
	currentsize--;
	printf("%s ", a);
    }
    printf("\n");
}
