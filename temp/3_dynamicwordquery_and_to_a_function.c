#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "/home/jack/develop/c/lib/stringutil.h"

char *query(char *searchword);

char *query(char *searchword) {
    FILE *file =
	fopen("/home/jack/develop/c/word_query/data/testdata.txt", "r");
    char *ending_word = "<end>";
    char a;
    char *word = calloc(20, sizeof(char));
    char *p;
    p = word;
    bool isstore = false;
    // use for stroe the explanation of the searching word;
    char *string = calloc(200000, sizeof(char));
    char *sp;
    sp = string;
    while ((a = fgetc(file)) != EOF) {
	if (isstore) {
	    *sp = a;
	    sp++;
	    if (isequal(ending_word, word)) {
		break;
	    }
	}
	if (a == ' ' || a == '\n' || a == '\r' || a == '\t') {
	    *p = '\0';
	    p = word;
	    /* printf("word is %s\n", word); */
	    if (isstore == false) {
		if (isequal(searchword, word)) {
		    isstore = true;
		}
	    } else {
	    }
	} else {
	    *p = a;
	    p++;
	}
    }
    return string;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
	char *search_word = argv[i];
	printf("searching word is %s\n", search_word);
	char *result = query(search_word);
	// print the explanation of the searching word;
	printf("explanation is %s\n", result);
    }
}
