#include <stdio.h>
#include <stdlib.h>

int main() {
    char **strarr = malloc(sizeof(*strarr) * 2);
    char *ele_one = calloc(2, sizeof(char));
    char *ele_two = calloc(2, sizeof(char));
    char *ele_three = calloc(2, sizeof(char));
    *strarr = ele_one;
    /* *strarr++ = ele_two; */
    /* *strarr++ = ele_three; */
    *ele_one = 'a';
    /* *ele_one++ = 'b'; */
    /* *ele_one++ = 'c'; */
    printf("%s",strarr[0]);
    
}


