#include <stdio.h>

#include "querybyhistory.h"

/* #include "wordquery.h" */
void randomquerywordtest();
void randomquerywordandhidesearchwordtest();
/* struct wordstuct *randomqueryword_version2(); */
void randomqueryword_version2test();
int main() {
    /* randomquerywordtest(); */
    /* randomquerywordandhidesearchwordtest(); */
    randomqueryword_version2test();
}

void randomquerywordtest() { randomqueryword(1); }

void randomquerywordandhidesearchwordtest() {
    randomquerywordandhidesearchword(1);
}
void randomqueryword_version2test() {
    struct wordstruct *ws = randomqueryword_version2();
    printf("%s:\n %s\n", ws->name, ws->explaination);
}
