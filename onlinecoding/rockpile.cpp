#include <iostream>
using namespace std;

int sub_sum_equal_val(int *a, int i, int n, int x) {
	int ret = 0;
	if (x == 0) {
		if (n == 0)
			return 1;
		return 0;
	}
	if (i >= 10)
		return 0;
	if (n <= 0)
		return 0;
	if (n == 1) {
		if (a[i] == x)
			return 1;
		return 0;
	}
	ret = sub_sum_equal_val(a, i+1, n-1, x-a[i]) || sub_sum_equal_val(a, i+1, n, x);
	return ret;
}

int main() {
    int a[10];
    int sum = 0;
    for (int i = 0; i < 10; i++) {
    	cin >> a[i];
    	cin.get();
    	sum = sum + a[i];
    }
    if (sum % 2 != 0) {
    	cout << -1;
    	return 0;
    }

    for (int j = 5; j >= 1; j--) {
		if (1 == sub_sum_equal_val(a, 0, j, sum/2)) {
			cout << j;
			return 0;
		}
    }
    //cout << a[0];
    return 0;
}