#include <stdlib.h>
#include <time.h>
/* #include <sys/types.h> */
/* #include <iostream> */
#include <unistd.h>

#include "/home/jack/develop/c/word_history/src/word_history.h"
#include "/home/jack/develop/c/word_query/src/wordquery.h"
void randomqueryword(int n);

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
	char *wordexplain = query(word);
	printf("EXPLANATION OF WORD %s is:\n %s\n", word, wordexplain);
    }
}
int main() { randomqueryword(5); }
