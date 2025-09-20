#include <stdio.h>
#include <stdlib.h>
struct word {
    char *name;
    char *explaination;
};

struct word *getword();

struct word *getword() {
    struct word *word = malloc(sizeof(struct word));

    word->name = calloc(30, sizeof(char));
    char *pname = word->name;
    *pname++ = 'a';
    *pname++ = 'b';
    word->explaination = malloc(sizeof(char));
    char *pexplaination = word->explaination;
    *pexplaination++ = 'c';
    *pexplaination++ = 'd';
    return word;
};

int main() {
    /* struct word *word = malloc(sizeof(struct word)); */

    /* word->name = calloc(30, sizeof(char)); */
    /* char *pname = word->name; */
    /* *pname++ = 'a'; */
    /* *pname++ = 'b'; */
    /* word->explaination = malloc(sizeof(char)); */
    /* char *pexplaination = word->explaination; */
    /* *pexplaination++ = 'c'; */
    /* *pexplaination++ = 'd'; */
    struct word *w = getword();

    printf("word is %s\n", w->name);
}
