#include "querybyexcludeknownword.h"

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "/home/jack/develop/c/word_parse/src/indexservice.h"
#include "/home/jack/develop/c/word_parse/src/wordindex.h"
#include "wordquery.h"
struct wordstruct *randomqueryword(int n) {
    /* srand(time(NULL) - getpid()); */
    srand(time(NULL));
    arraylist *l = loadindex();
    int sizeal = arraylist_size(l);
    int index = rand() % (sizeal + 1);
    /* printf("index is %d\n",index); */
    struct wordindex *w = arraylist_get(l, index);
    /* printf("word is: %s\n",w->name->value); */
    struct wordstruct *ws = querybyindex(w->name->value);
    return ws;
}

