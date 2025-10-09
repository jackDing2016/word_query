#include <stdio.h>

int main() {
    // the print follow that A-Z is 65-90 a-z is 97-122
    char *a = "AaZz";

    char *pa = a;

    for (int i = 0; i < 4; i++) {
	printf("int of char is %d\n", *pa++);
    }
}
