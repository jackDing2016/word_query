#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "/home/jack/develop/c/lib/stringutil.h"

char *query(char *searchword);
size_t getsize(char *s);
char *decoratesearchword(char *searchword);
size_t getsize(char *s) {
    size_t res = 0;
    while (*s++ != '\0') {
	res++;
    }
    return res;
}
char *decoratesearchword(char *searchword) {
    size_t size = getsize(searchword);
    char *res = calloc(size + 2, sizeof(char));
    char *p;
    p = res;
    *p++ = '<';
    while ((*p++ = *searchword++) != '\0');
    *p = '>';
    return res;
}

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
		    /* printf("its true word\n "); */
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
	/* printf("searching word is %s\n", search_word); */
	/* char *result = query(search_word); */

	char *dsh = decoratesearchword(search_word);
	printf("dsh is %s\n", decoratesearchword);
	char *result = query(dsh);
	// print the explanation of the searching word;
	printf("explanation is %s\n", result);
    }
}
