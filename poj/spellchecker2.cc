#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

char dict[10001][16];
char word[51][16];
int dict_num = 0;
int word_num = 0;

int main(int argc, char const *argv[])
{
	while (cin >> dict[dict_num] && dict[dict_num++][0] != '#');
	while (cin >> word[word_num] && word[word_num++][0] != '#');
	dict_num--;
	word_num--;

	int *dict_len = new int[dict_num];
	for (int i = 0; i < dict_num; ++i)
	{
		dict_len[i] = strlen(dict[i]);
	}

	for (int i = 0; i < word_num; ++i)
	{
		int word_len = strlen(word[i]);
		bool indict = false;
		int * found = new int[dict_num];
		int curr = 0;
		for (int j = 0; j < dict_num; ++j)
		{
			if (dict_len[j] == word_len)
			{
				if (strcmp(dict[j], word[i]) == 0)
				{
					//cout << word[i]<<" is correct"<<endl;
					indict = true;
					break;
				}
				else
				{
					// change one char
					int same_chars = 0;
					for (int x = 0; x < word_len; ++x)
					{
						if (same_chars < x-1)
							break;
						if (word[i][x] == dict[j][x])
							same_chars++;
					}
					if (same_chars == word_len - 1)
						found[curr++] = j;
				}
			}
			else if (dict_len[j] - word_len == 1 || word_len - dict_len[j] == 1)
			{
				char *big = word[i], *small = dict[j];
				int biglen = max(dict_len[j], word_len);
				int smallen = min(dict_len[j], word_len);
				if (dict_len[j] > word_len) {
					big = dict[j];
					small = word[i];
				}
				int diff = 0;
				//cout << big << " "<<small <<" " << diff <<biglen << " " << smallen << endl;
				for (int z = 0, k = 0; z < biglen && k < smallen && diff <= 1; z++)
				{
					if (big[z] != small[k]) {
						//cout << "t1: " <<z << " " << k << " "<<big[z] << " " << small[k] << endl;
						diff++;
					}
					else
						k++;
				}
				
				if (diff <= 1)
					found[curr++] = j;
			}
		}
		if (indict)
			cout << word[i]<<" is correct"<<endl;
		else {
			cout<<word[i]<<": ";
			for (int y = 0; y < curr; ++y)
			{
				cout << dict[found[y]] << ' ';
			}
			cout << endl;
		}
		delete found;
	}
	return 0;
}