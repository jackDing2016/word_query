#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "/home/jack/develop/c/lib/stringutil.h"

size_t getsize(char *s);
void decoratesearchword(char *dest, char *source);
size_t getsize(char *s) {
    size_t res = 0;
    while (*s++ != '\0') {
	res++;
    }
    return res;
}
void decoratesearchword(char *dest, char *source) {
    *dest++ = '<';
    while ((*dest++ = *source++) != '\0');
    *(--dest) = '>';
    *(++dest) = '\0';
}

char *query(char *searchword) {
    /* char *dsh = decoratesearchword(searchword); */
    char *dsw = calloc(30, sizeof(char));
    decoratesearchword(dsw, searchword);
    printf("dsw is %s\n", dsw);
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
		if (isequal(dsw, word)) {
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

