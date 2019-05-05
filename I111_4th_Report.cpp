#include <iostream>
#include <random>
#define n 150
int main()
{
	short s[n - 1];
	int a[101];
	for (auto& i : a)i = 0;
	for (auto& i : s)
	{
		i = rand() % 101;
		a[i]++;
	}
	std::cout << a[91];
	return 0;
}
