#include <stdio.h>
#include <stdlib.h>
// that is a very very very good example for pointer!
// create a string array and set some element in it and print it by loop
int main() {
    char **arr = malloc(sizeof(*arr) * 10);
    // set
    for (int i = 0; i < 10; i++) {
	char *word = calloc(20, sizeof(char));
	*word = 'a';
	*(word + 1) = '1';
	*(arr + i) = word;
    }
    // print
    for (int i = 0; i < 10; i++) {
	printf("element is %s\n", *(arr + i));
    }
}
