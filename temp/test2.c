#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "/home/jack/develop/c/lib/stringutil.h"
int main() {
    FILE *file =
	fopen("/home/jack/develop/c/word_query/data/testdata.txt", "r");
    char *search_word = "<disservice>";
    /* char *search_word = "someone"; */
    char a;
    char *word = calloc(20, sizeof(char));
    char *p;
    p = word;

    bool isprint = false;

    while ((a = fgetc(file)) != EOF) {
	if (isprint) {
	    printf("%c", a);
	    continue;
	}

	if (a == ' ') {
	    *p = '\0';
	    /* printf("word is %s\n", word); */
	    /* printf("%s ", word); */
	    p = word;
	    if (isequal(search_word, word)) {
		isprint = true;
	    }
	} else {
	    // if a is new line or tab, then skip it
	    if (a == '\n' || a == '\r' || a == '\t') {
	    } else {
		*p = a;
		p++;
	    }
	}
    }
}
