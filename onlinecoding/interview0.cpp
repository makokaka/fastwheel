#include <stdio.h>
#include <set>
using namespace std;
typedef set<int> int_set;

int main() {
	int N, M;
	scanf("%d%d\n", &N, &M);
	//printf("%dxxx%d\n", N, M);

	// int *a = new int(N);
	int_set s;
	int x;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	//printf("%d\n", a[N-1]);

	int_set::iterator iter;
	int result = 0;
	for (iter = s.begin(); iter != s.end(); iter++) {
		// printf("%d\n", *iter);
		int a = *iter - M;
		int b = *iter + M;
		if (s.find(a) != s.end())
			result += 1;
		if (s.find(b) != s.end())
			result += 1;
	}
	printf("%d\n", result / 2);

	// delete a;
	return 0;
}