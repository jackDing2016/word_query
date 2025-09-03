#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "/home/jack/develop/c/lib/stringutil.h"
int main(int argc, char *argv[]) {
    char *search_word = argv[1];

    FILE *file =
	fopen("/home/jack/develop/c/word_query/data/testdata.txt", "r");
    /* char *search_word = "<disservice>"; */
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
		if (isequal(search_word, word)) {
		    isstore = true;
		}
	    } else {
	    }
	} else {
	    *p = a;
	    p++;
	}
    }
    // print the explanation of the searching word;
    printf("explanation is %s\n", string);
}
