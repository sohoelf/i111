#include <iostream>
#include <math.h>
#include <vector>
void getPrimeNumber(short n, std::vector<short>& primenumbers)//レポート課題２のアルゴリズム3を用いている
{
	std::vector<bool> prime;
	for (short i = 0; i <= n; i++)
	{
		prime.push_back(true);
	}
	for (short i = 2, k = sqrt(n); i <= k; i++)
	{
		for (short j = i, l;; j++)
		{
			l = i * j;
			if (l > n)break;
			prime[l] = false;
		}
	}
	for (short i = 2; i <= n; i++)
	{
		if (prime[i])
		{
			primenumbers.push_back(i);
		}
	}
}
int find(short x, std::vector<short>& primenumbers)//2分探索法
{
	std::cout << "Find " << x << "\n";
	short left = 0;
	short right = primenumbers.size() - 1;
	do {
		int mid = (left + right) / 2;
		std::cout << "[" << left << "," << right << "] mid=" << mid << "\n";
		if (x == primenumbers[mid]) {
			std::cout << "Found!" << "\n\n";
			return mid;
		}
		if (x < primenumbers[mid]) right = mid - 1;
		else left = mid + 1;
	} while (left <= right);
	std::cout << "[" << left << "," << right << "] left>right" << "\n" << "Not exist." << "\n\n";
	return -1;
}
int main()
{
	std::vector<short> primenumbers;
	getPrimeNumber(100, primenumbers);
	find(15, primenumbers);
	find(31, primenumbers);
	find(91, primenumbers);

	std::vector<short> htb;
	static short m;
	static int count;
	static class HashAlgorithm//ハッシュ法のアルゴリズム
	{
	public:
		static void init(std::vector<short>& htb)
		{
			for (short i = 1; i <= m; i++)
			{
				htb.push_back(0);
			}
		}
		static short hash(short x) { return x % m; }
		static void add(short x, std::vector<short>& htb) {
			short j = hash(x);
			while (count++ && htb[j] != 0)//htb[j] != 0 のチェック回数をカウント
			{
				j = (j + 1) % m;
			}
			htb[j] = x;
		}
		static int find(short x, std::vector<short>& htb) {
			short j = hash(x);
			while (htb[j] != 0) {
				if (htb[j] == x) return j;
				j = (j + 1) % m;
			}
			return -1;
		}
	};
	//m = 30、25回分の合計
	m = 30;
	count = 0;
	htb.clear();
	HashAlgorithm::init(htb);
	for (auto& i : primenumbers)
	{
		HashAlgorithm::add(i, htb);
	}
	std::cout << "m=" << m << " count=" << count << "\n";
	//m = 28、25回分の合計
	m = 28;
	count = 0;
	htb.clear();
	HashAlgorithm::init(htb);
	for (auto& i : primenumbers)
	{
		HashAlgorithm::add(i, htb);
	}
	std::cout << "m=" << m << " count=" << count << "\n";
	//m = 29、25回分の合計
	m = 29;
	count = 0;
	htb.clear();
	HashAlgorithm::init(htb);
	for (auto& i : primenumbers)
	{
		HashAlgorithm::add(i, htb);
	}
	std::cout << "m=" << m << " count=" << count << "\n";
	//m = 50、25回分の合計
	m = 50;
	count = 0;
	htb.clear();
	HashAlgorithm::init(htb);
	for (auto& i : primenumbers)
	{
		HashAlgorithm::add(i, htb);
	}
	std::cout << "m=" << m << " count=" << count << "\n";
	return 0;
}
/**実行結果//////////////////////
Find 15
[0, 24] mid = 12
[0, 11] mid = 5
[6, 11] mid = 8
[6, 7] mid = 6
[6, 5] left > right
Not exist.

Find 31
[0, 24] mid = 12
[0, 11] mid = 5
[6, 11] mid = 8
[9, 11] mid = 10
Found!

Find 91
[0, 24] mid = 12
[13, 24] mid = 18
[19, 24] mid = 21
[22, 24] mid = 23
[24, 24] mid = 24
[24, 23] left > right
Not exist.

m = 30 count = 56
m = 28 count = 51
m = 29 count = 51
m = 50 count = 31
**//////////////////////////////