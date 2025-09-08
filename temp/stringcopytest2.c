#include <stdio.h>
#include <stdlib.h>
char *copy(char *aa);

char *copy(char *aa) {
    size_t size = 0;
    char *b;
    b=aa;
    while (*b++ != '\0') {
	size++;
    }
    printf("size is %d\n", size);
    /* char *res = calloc(20, sizeof(char)); */
    char *res = calloc(size + 2, sizeof(char));
    char *p;
    p = res;
    *p++ = '<';
    while ((*p++ = *aa++) != '\0');
    *p = '>';
    return res;
}
int main() {
    char *s = copy("teach");
    printf("string is %s\n", s);
}
