#include <iostream>
#include <math.h>
#include <vector>
////////////////////////////////アルゴリズム１、計算量の上界はO(n^2)
void getPrimeNumber_1(short n)
{
	unsigned long int count = 0;
	short prime_count = 0;//2Byte
	float avg = 0;//4Byte
	for (short i = 2; i <= n; i++)//2Byte+2Byte
	{
		for (short j = 2; j <= i; j++)//2Byte
		{
			count++;
			if (i % j == 0)
			{
				if (i == j)
				{
					std::cout << i << " ";
					avg += i;
					prime_count++;
				}
				break;
			}
		}
	}
	avg /= prime_count;
	std::cout << "|Avg=" << avg << "|Count=" << count << "\n";
}
////////////////////////////////アルゴリズム２、計算量の上界はO(n^1.5)
void getPrimeNumber_2(short n)
{
	unsigned long int count = 0;
	short prime_count = 0;//2Byte
	float avg = 0;//4Byte
	for (short i = 2, k; i <= n; i++)//2Byte+2Byte+2Byte
	{
		k = sqrt(i);
		for (short j = 2; j <= k; j++)//2Byte
		{
			count++;
			if (i % j == 0)
			{
				k = -1;
				break;
			}
		}
		if (k != -1)
		{
			std::cout << i << " ";
			avg += i;
			prime_count++;
		}
	}
	avg /= prime_count;
	std::cout << "|Avg=" << avg << "|Count=" << count << "\n";
}
////////////////////////////////アルゴリズム３、計算量の上界はO(n*log(n*0.5))
void getPrimeNumber_3(short n)
{
	unsigned long int count = 0;
	short prime_count = 0;//2Byte
	float avg = 0;//4Byte
	std::vector<bool> prime;//Vector構造のMemory、(n+1)*1Byteより大きい
	for (short i = 0; i <= n; i++)
	{
		prime.push_back(true);
	}
	for (short i = 2, k = sqrt(n); i <= k; i++)//2Byte+2Byte+2Byte
	{
		for (short j = i, l;; j++)//2Byte+2Byte
		{
			count++;
			l = i * j;
			if (l > n)break;
			prime[l] = false;
		}
	}
	for (short i = 2; i <= n; i++)
	{
		if (prime[i])
		{
			std::cout << i << " ";
			avg += i;
			prime_count++;
		}
	}
	avg /= prime_count;
	std::cout << "|Avg=" << avg << "|Count=" << count << "\n";
}
////////////////////////////////Main
int main()
{
	getPrimeNumber_1(100);
	getPrimeNumber_2(100);
	getPrimeNumber_3(100);
	return 0;
}
/**実行結果//////////////////////
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 | Avg = 42.4 | Count = 1158
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 | Avg = 42.4 | Count = 236
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 | Avg = 42.4 | Count = 155
**//////////////////////////////
