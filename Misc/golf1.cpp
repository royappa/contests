#include <stdio.h>
#include <string.h>

char *c(char *s) {
	char *p = s;
	while (*p) {
		char *q = p;
		while(*q && *q++ == *p)
			;
		if (q-p >= 3) {
				 strcpy(p, q);
				 return c(s);
		}
		p = q;
	}
	return s;
}

int main() {
	char s[100];
	scanf(s);
	printf("C: %s\n", c(s));

	return 0;
}

/*
string c(string s) {
	for (int i = 0; i < s.size(); i++) {
		int j = i+1;
		while(j < s.size() && s[j] == s[i])
			j++;
		if (j-i >= 3)
				return c(s.substr(0, i) + s.substr(j));
	}
	return s;
}
*/
