#include <stdio.h>

#include "querybyhistory.h"

/* #include "wordquery.h" */
void randomquerywordtest();
void randomquerywordandhidesearchwordtest();
/* struct wordstuct *randomqueryword_version2(); */
void randomqueryword_version2test();
void randomqueryword_version3test();
int main() {
    /* randomquerywordtest(); */
    /* randomquerywordandhidesearchwordtest(); */
    /* randomqueryword_version2test(); */
    randomqueryword_version3test();
}

void randomquerywordtest() { randomqueryword(1); }

void randomquerywordandhidesearchwordtest() {
    randomquerywordandhidesearchword(1);
}
void randomqueryword_version2test() {
    struct wordstruct *ws = randomqueryword_version2();
    printf("%s:\n %s\n", ws->name, ws->explaination);
}
void randomqueryword_version3test() {
    struct wordstruct *ws = randomqueryword_version3();
    printf("%s:\n %s\n", ws->name, ws->explaination);
}
