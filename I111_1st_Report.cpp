//	結果:
//	-8
//  0
//	
//	結果の解説レポート:
//	C++言語で実装され、先生の例と同じなアルゴリズムだ。
//	O(n)時間で計算するアルゴリズムだ。
//	前回のMAX[0,j-1]を使ってMAX[0,j]を計算する。

#include <iostream>
#define DATA_1 0
#define DATA_2 1
const short DATA[2][12] = { { 103, 97, 106, 104, 107, 101, 100, 106, 103, 99, 102, 111 }
						, { 92, 95, 97, 99, 99, 100, 103, 106, 110, 112, 118, 121 } };

void mnsp(const char DATA_N)
{
	short mnp = 0;							//利益の最安値
	short mxep = DATA[DATA_N][0];			//これまでの最高値
	for (const short& x : DATA[DATA_N]) {	//順番にアクセス
		short d = x - mxep;					//売却益
		if (d < mnp) mnp = d;				//最損益の更新
		if (x > mxep) mxep = x;				//これまでの最高値の更新
	}
	std::cout << mnp << "\n";
}

void main()
{
	mnsp(DATA_1);
	mnsp(DATA_2);
}

