#include <stdio.h>
#include <stdlib.h>
void stringcopy(char *dest, char *origin);
size_t getsize(char *s);
size_t getsize(char *s) {
    size_t res = 0;
    while (*s++ != '\0') {
	res++;
    }
    return res;
}
void stringcopy(char *dest, char *origin) {
    *dest++ = '<';
    while ((*dest++ = *origin++) != '\0');
    *(--dest) = '>';
    *(++dest) = '\0';
}

int main() {
    char *s = calloc(30, sizeof(char));
    stringcopy(s, "abc");
    printf("s is %s\n", s);
}
