#include <stdio.h>

#include "querybyexcludeknownword.h"
#include "wordquery.h"
void randomquerywordtest();

int main() {
   
    randomquerywordtest();

};

void randomquerywordtest() {
    struct wordstruct *w = randomqueryword(1);
    printf("%s:\n, %s\n", w->name, w->explaination);
}

