#include <stdio.h>

int main() {
    int index = 18809978;
    FILE *f = fopen("/home/jack/develop/c/word_parse/data/dict/longmandict.txt",
		    "rb");
    fseek(f, index, SEEK_CUR);

    for (int i = 0; i < 200; i++) {
	char a = fgetc(f);
	printf("%c", a);
    }
    printf("\n");
}
