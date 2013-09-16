/*
bwwb
bbwb
bwwb
bwww

output
4
*/

#include <stdio.h>
#include <iostream>

using namespace std;

void init(unsigned int &x)
{
	char c;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%c", &c);
			if (c == 'b')
				x = x + 1 << i * 4 + j;
			printf("%d\n", x);
		}
		scanf("%c", &c);
	}
}

int main(int argc, char const *argv[])
{
	unsigned int x = 0;
	char c;
	for (int i = 0; i < 16; ++i)
	{
		cin >> c;
		if (c == 'b')
			x += 1 << i;
		printf("%d\n", x);
	}
	printf("%o\n", x);
	return 0;
}