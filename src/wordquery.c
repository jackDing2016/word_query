#include "wordquery.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "/home/jack/develop/c/lib/stringutil.h"
#include "/home/jack/develop/c/word_parse/src/indexservice.h"
#include "/home/jack/develop/c/word_parse/src/wordindex.h"

size_t getsize(char *s);
/* void decoratesearchword(char *dest, char *source); */

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
struct wordstruct *queryandhidesearchword(char *searchword) {
    struct wordstruct *word = query(searchword);
    char *exp = word->explaination;
    char *pexp = exp;

    char *wordinexp = calloc(30, sizeof(char));
    char *pword = wordinexp;

    /* int offset = 0; */

    while (*pexp != '\0') {
	if (*pexp == ' ') {
	    *pword = '\0';
	    /* printf("word is %s\n", wordinexp); */
	    if (isequal(wordinexp, searchword) ||
		islike(searchword, wordinexp)) {
		char *pforhide = pexp - 1;
		size_t len = size(wordinexp);
		for (int i = 0; i < len; i++) {
		    *(pforhide - i) = '*';
		}
	    }
	    pword = wordinexp;
	} else {
	    *pword++ = *pexp;
	}
	pexp++;
	/* offset++; */
    }

    return word;
}
struct wordstruct *query(char *searchword) {
    struct wordstruct *w = malloc(sizeof(struct wordstruct));
    // the order is very important which if inverse it you will get different
    // result
    /* char *pname = w->name; */
    /* pname = calloc(30, sizeof(char)); */
    w->name = calloc(30, sizeof(char));
    char *pname = w->name;
    strcpy(pname, searchword);
    // use for stroe the explanation of the searching word;
    w->explaination = calloc(200000, sizeof(char));
    char *sp = w->explaination;

    char *dsw = calloc(30, sizeof(char));
    decoratesearchword(dsw, searchword);
    printf("dsw is %s\n", dsw);
    FILE *file =
	fopen("/home/jack/develop/c/word_query/data/testdata.txt", "r");
    char *ending_word = "<end>";

    char *word = calloc(20, sizeof(char));
    char *p = word;
    bool isstore = false;
    char a;
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
    return w;
}

struct wordstruct *querybyindex(char *searchword) {
    struct wordstruct *ws = malloc(sizeof(struct wordstruct));
    ws->name = calloc(100, sizeof(char));
    char *pname = ws->name;
    strcpy(pname, searchword);
    // use for stroe the explanation of the searching word;
    ws->explaination = calloc(200000, sizeof(char));
    char *sp = ws->explaination;

    /* char *dsw = calloc(110, sizeof(char)); */
    /* decoratesearchword(dsw, searchword); */

    hashtable *t = loadindextable();
    struct wordindex *w = hashtable_get(t, pname);
    FILE *f = fopen("/home/jack/develop/c/word_parse/data/dict/longmandict.txt",
		    "rb");
    fseek(f, w->startindex, SEEK_CUR);

    int len = w->endindex - w->startindex;
    for (int i = 0; i < len - 10; i++) {
	char a = fgetc(f);
	*sp++ = a;
	/* printf("%c", a); */
    }
    /* printf("\n"); */

    return ws;
}
