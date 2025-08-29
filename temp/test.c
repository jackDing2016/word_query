#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file =
	fopen("/home/jack/develop/c/word_query/data/testdata.txt", "r");
    char a;

    char *p = calloc(20, sizeof(char));
    char *word;
    word = p;
    while ((a = fgetc(file)) != EOF) {
	if (a == ' ') {
	    *word = '\0';
	    printf("word is %s\n", p);
	    word = p;
	} else {
	    *word = a;
	    word++;
	}
    }
}
