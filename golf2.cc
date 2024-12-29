#include <stdio.h>
#include <string.h>

char *c(char *s) {
	char *p = s;
	while (*p) {
		char *q = p;
		while(*q && *++q == *p)
			;
		if (q-p >= 3)
			return strcpy(p, q), c(s);
		p = q;
	}
	return s;
}

int main(int argc, char *argv[]) {

	printf("C: %s\n", c(argv[1]));
	return 0;
}

