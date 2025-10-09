#include <stdio.h>

#include "/home/jack/develop/c/word_parse/src/indexservice.h"
#include "/home/jack/develop/c/word_parse/src/wordindex.h"
#include "wordquery.h"
void querytest();
void queryandhidesearchwordtest();
void querybyindextest();

void loadindextest();
void loadindextabletest();

int main() {
    /* querytest(); */
    /* queryandhidesearchwordtest(); */
    querybyindextest();
    /* loadindextest(); */
    /* loadindextabletest(); */
}

void loadindextest() {
    arraylist *l = loadindex();
    for (int i = 0; i < arraylist_size(l); i++) {
	struct wordindex *w = arraylist_get(l, i);
	printf(" %s startindex: %d endindex: %d\n", w->name->value,
	       w->startindex, w->endindex);
    }
}

void loadindextabletest() {
    char *a = "<kit>";
    hashtable *t = loadindextable();
    struct wordindex *w = hashtable_get(t, a);
    printf(" %s startindex: %d endindex: %d\n", w->name->value, w->startindex,
	   w->endindex);
}

void querytest() {
    /* char *word = query("monkey"); */
    /* printf("word explain is %s", word); */
    struct wordstruct *res = query("serious");
    printf("hi man again\n");
    /* printf("word: %c ", *(res->name)); */
    /* printf("%s\n", res->name); */
    printf("word: %s explaination is %s\n", res->name, res->explaination);
}

void queryandhidesearchwordtest() {
    struct wordstruct *res = queryandhidesearchword("smash");
    printf("exp is %s\n", res->explaination);
}
void querybyindextest() { querybyindex("sing"); }
