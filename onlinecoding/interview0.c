#include <stdio.h>
int main() {
	int N, M;
	scanf("%d%d\n", &N, &M);
	//printf("%dxxx%d\n", N, M);

	int *a = new int(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	delete a;
	return 0;
}