#include <stdio.h>
#include <stdlib.h>
#include "lcs.h"

int huiwen(const char *s)
{
	size_t m = strlen(s);
	char *s2 = new char[m+1];
	for (size_t i = 0; i < m; i++) {
		s2[i] = s[m - i - 1];
	}
	s2[m] = 0;
	printf("%s : %s\n", s, s2);
	int len = longest_common_substring(s, s2);
	delete[] s2;
	return len;
}

int main()
{
	const char *s[] = {"aabbaa", "xyabccbaxy", "xabcccba"};
	for (int i = 0; i < sizeof(s)/sizeof(char *); i++)
		printf("%s: %d\n", s[i], huiwen(s[i]));
	return 0;
}
