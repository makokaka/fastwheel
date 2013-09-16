#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<string> string_vector_t;
string_vector_t string_vector;
const int MAXCHAR = 16;
int dist[MAXCHAR][MAXCHAR];
typedef map<string, int> string_int_map_t;
string_int_map_t dict_word_map;

int minx(int a, int b, int c) {
	int tmp = (a < b)? a: b;
	return (tmp < c)? tmp: c;
}

int edit_distance(string a, string b) {
	int ret = 0;
	int m = a.size(), n = b.size();
	for (int i = 0; i <= m; ++i)
	{
		dist[i][0] = i;
	}
	for (int i = 0; i <= n; ++i)
	{
		dist[0][i] = i;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int x = (a[i-1] == b[j-1])? 0: 1;
			dist[i][j] = minx(dist[i][j-1]+1, dist[i-1][j]+1,
				dist[i-1][j-1] + x);
			//cout << dist[i][j-1]+1 << " "<< dist[i-1][j]+1 <<" "<< dist[i-1][j-1] << " "<<dist[i][j]<<" ";
		}
	}
	return dist[m][n];
}

void check(string s) {
	string_int_map_t::iterator x = dict_word_map.find(s);
	if (x != dict_word_map.end()) {
		cout << s << " is correct\n";
		return;
	}
	cout << s << ":";
	//cout << string_vector.size() << string_vector[1] << endl;
	for (std::vector<string>::iterator i = string_vector.begin(); i != string_vector.end(); ++i)
	{
		int sizediff = (*i).size() - s.size();
		if (abs(float(sizediff)) > 1)
			continue;
		int d = edit_distance(*i, s);
		//cout << d << endl;
		//cout << *i << " " << s << " " << d << endl;
		if (d <= 1)
			cout << " " << *i;
	}
	cout << endl;
}

void readinput()
{
	string s;
	bool dict_end = false;
	while(1) {
		cin >> s;
		if (s == "#") {
			if (dict_end)
				break;
			dict_end = true;
			continue;
		}
		if (!dict_end) {
			string_vector.push_back(s);
			dict_word_map[s] = 0;
		} else {
			check(s);
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAXCHAR; ++i)
	{
		for (int j = 0; j < MAXCHAR; ++j)
		{
			dist[i][j] = 0;
		}
	}
	readinput();
	return 0;
}