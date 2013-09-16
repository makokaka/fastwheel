#include <string.h>

int longest_common_substring(const char *s1, const char *s2)
{
	int m = strlen(s1);
	int n = strlen(s2);
	int **rec = new int*[m+1];
	int i, j;
	for (i = 0; i < m+1; i++) {
		rec[i] = new int[n+1];
	}

	for (i = 0; i <=m; i++) {
		rec[i][0] = 0;
	}
	for (j = 0; j <=n; j++) {
		rec[0][j] = 0;
	}

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (s1[i-1] == s2[j-1]) {
				if (i-2 >= 0 && j-2 >= 0 && s1[i-2] == s2[j-2]) {
					rec[i][j] = rec[i-1][j-1] + 1;
				}
				else {
					rec[i][j] = rec[i-1][j-1] > 1? rec[i-1][j-1] : 1;
				}
			} else if (rec[i][j-1] >= rec[i-1][j]) {
				rec[i][j] = rec[i][j-1];
			} else {
				rec[i][j] = rec[i-1][j];
			}
		}
	}
	int max = rec[m][n];

	for (i = 0; i < m + 1; i++) {
		delete[] rec[i];
	}
	delete[] rec;

	return max;
}
