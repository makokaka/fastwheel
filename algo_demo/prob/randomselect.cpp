#include <iostream>
#include <string>
#include <vector>

using namespace std;

void randselect(std::vector<int> &v, int K) {
	cout << K << endl;
}

int main(int argc, char const *argv[])
{
	//int N, K;
	int K = 5;
	std::vector<int> v;
	//cin >> N >> K;
	while(true) {
		int i;
		cin >> i;
		v.append(i);
		randselect(v, K);
	}
	return 0;
}