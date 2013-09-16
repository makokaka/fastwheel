#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_aggnum(int num)
{
	char s[256];
	char tmp1[256], tmp2[256], tmp3[256];
	snprintf(s, 256, "%d", num);

	size_t len = strlen(s);
	for (int i = 1; i < (len+1)/2; i++) {
		strncpy(tmp1, s, i);
		tmp1[i] = 0;
		int a = atoi(tmp1);
		for (int j = 1; j < (len+1)/2; j++) {
			strncpy(tmp2, s+i, j);
			tmp2[j] = 0;
			int b = atoi(tmp2);
			int c = a + b;
			
			snprintf(tmp3, 256, "%d", c);
			int x = strlen(tmp3);
			//printf("%s %s %s\n", tmp1, tmp2, tmp3);
			if (strncmp(s+i+j, tmp3, x) == 0) {
				if (len == i + j + x)
					return true;
				if (is_aggnum(atoi(s+i)))
					return true;
			}
		}
	}
	return false;
}

int main()
{
	int a[] = {112358, 12113, 122436, 1299111210, 112112224};
	for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
		printf("%d, %d\n", a[i], is_aggnum(a[i]));
	}
	return 0;
}
