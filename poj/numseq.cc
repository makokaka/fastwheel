#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		//cout << sqrt(2 * a[i] - 1/4) - 1/2 << endl;
		int k = int(ceil(sqrt(2 * a[i] - 0.25) - 0.5));
		cout <<a[i] - k*(k-1)/2<<endl;
	}
	//int k = int(sqrt(2*))
	return 0;
}