#include <stdlib.h>
#include <time.h>
/* #include <sys/types.h> */
/* #include <iostream> */
#include <string.h>
#include <unistd.h>

#include "/home/jack/develop/c/word_history/src/word_history.h"
#include "/home/jack/develop/c/word_query/src/querybyhistory.h"
struct wordstruct *randomqueryword_version2() {
    arraylist *wordhistorylist = getallhistory();
    int wordhistorylistsize = arraylist_size(wordhistorylist);
    srand(time(NULL));
    // rand number for word history list
    int index = rand() % (wordhistorylistsize + 1);
    /* printf( */
	/* "index which is generated randomly and is in word history list is %d\n", */
	/* index); */
    char *word = arraylist_get(wordhistorylist, index);
    char *dsw = calloc(strlen(word) + 2, sizeof(char));
    decoratesearchword(dsw, word);
    /* printf("the word which would be queried is %s\n", dsw); */
    struct wordstruct *wordstruct = querybyindex(dsw);
    return wordstruct;
}
void randomqueryword(int n) {
    arraylist *wl = getallhistory();
    int wordcount = arraylist_size(wl);
    // just can be call once, so it is out of the loop
    srand(time(NULL) - getpid());
    for (int i = 0; i < n; i++) {
	/* srand(time(0)); */
	/* srand((time(NULL) & 0xFFFF) | (getpid() << 16)); */
	int index = rand() % (wordcount + 1);
	printf("rand index is %d\n", index);
	char *word = arraylist_get(wl, index);
	/* char *wordexplain = query(word); */
	struct wordstruct *w = query(word);
	printf("EXPLANATION OF WORD %s is:\n %s\n", w->name, w->explaination);
    }
}
/* int main() { randomqueryword(1); } */
void randomquerywordandhidesearchword(int n) {
    arraylist *wl = getallhistory();
    int wordcount = arraylist_size(wl);
    // just can be call once, so it is out of the loop
    srand(time(NULL) - getpid());
    for (int i = 0; i < n; i++) {
	/* srand(time(0)); */
	/* srand((time(NULL) & 0xFFFF) | (getpid() << 16)); */
	int index = rand() % (wordcount + 1);
	printf("rand index is %d\n", index);
	char *word = arraylist_get(wl, index);
	/* char *wordexplain = query(word); */
	struct wordstruct *w = queryandhidesearchword(word);
	printf("EXPLANATION OF WORD %s is:\n %s\n", w->name, w->explaination);
    }
}

