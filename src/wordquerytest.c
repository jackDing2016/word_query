#include <stdio.h>

#include "wordquery.h"
int main() {
    /* char *word = query("monkey"); */
    /* printf("word explain is %s", word); */
    struct wordstruct *res = query("serious");
    printf("hi man again\n");
    /* printf("word: %c ", *(res->name)); */
    /* printf("%s\n", res->name); */
    printf("word: %s explaination is %s\n", res->name, res->explaination);
}
