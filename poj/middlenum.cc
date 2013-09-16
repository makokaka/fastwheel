#include <iostream>
//#include <algorithm>

using namespace std;

void exch(int a[], int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void printarr(int a[], int n) {
	cout << "print arr: ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int partition(int a[], int lo, int hi)
{
	//if (lo >= hi)
	int m = lo, n = hi + 1;
	while (m < n) {
		while (m < n && a[++m] <= a[lo]);
		while (m < n && a[--n] >= a[lo]);
		if (m >= n)
			break;
		exch(a, m, n);
	}
	exch(a, m-1, lo);
	return m-1;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int *a = new int[N];
	int i = 0;
	while (cin >> a[i++]);
	//printarr(a, N);

	int lo = 0, hi = N-1;
	int mid = (N-1)/2;
	while (1) {
		int j = partition(a, lo, hi);
		//printarr(a, N);
		//cout << lo << " " << hi << " " << j << " " <<a[lo]<<" "<<a[hi]<< " "<<a[j]<<endl;
		if (j == mid) {
			cout << a[j] << endl;
			break;
		}
		else if (j < mid) {
			lo = j + 1;
		}
		else
			hi = j - 1;
	}
	return 0;
}