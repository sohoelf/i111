#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <time.h>
template
<
	typename TYPE,
	std::size_t SIZE
>
std::size_t array_length(const TYPE(&)[SIZE])
{
	return SIZE;
}
template
<
	typename TYPE,
	std::size_t SIZE
>
void print(const TYPE(&array)[SIZE])
{
	for (auto i : array)
	{
		std::cout << i << "_";
	}
	std::cout << std::endl;
}
template
<
	typename TYPE,
	typename SIZE
>
void print(const TYPE array, SIZE size)
{
	for (SIZE i = 0; i < size; i++)
	{
		std::cout << array[i] << "_";
	}
	std::cout << std::endl;
}
template
<
	typename TYPE,
	std::size_t SIZE
>
TYPE* bubbleSort(const TYPE(&array)[SIZE])//バブルソート
{
	TYPE* array_ = new TYPE[SIZE];
	memcpy(array_, array, sizeof(array));
	int n = SIZE;long long count = 0;
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			if (array_[i] > array_[i + 1]) {
				int t = array_[i]; array_[i] = array_[i + 1]; array_[i + 1] = t; count++;
			}
		}
	}
	std::cout << "BubbleSort   " << count << std::endl;
	return array_;
}
template
<
	typename TYPE,
	std::size_t SIZE
>
TYPE* shellSort(const TYPE(&array)[SIZE])//シェルソート
{
	TYPE* array_ = new TYPE[SIZE];
	memcpy(array_, array, sizeof(array));
	int n = SIZE, count = 0;
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		for (int i = gap; i < n; i++) {
			for (int j = i - gap; j >= 0 && array_[j] > array_[j + gap]; j = j - gap) {
				auto t = array_[j]; array_[j] = array_[j + gap]; array_[j + gap] = t; count++;
			}
		}
	}
	std::cout << "ShellSort   " << count << std::endl;
	return array_;
}
class HeapArray {
private:
	int* heap;
	int n;
public:
	int count = 0;
	HeapArray(int size) {
		heap = new int[size];
		n = 0;
	}
	void push(int x) {
		heap[n] = x;
		int child = n;
		int parent = (n - 1) / 2;
		while (child != 0 && x < heap[parent]) {
			heap[child] = heap[parent]; count++;
			child = parent;
			parent = (child - 1) / 2;
		}
		heap[child] = x;
		n++;
	}
	int pop() {
		int minValue = heap[0];
		heap[0] = heap[n - 1];
		n--;
		int parent = 0;
		int child = parent * 2 + 1;
		while (child < n) {
			if (child + 1 < n && heap[child] > heap[child + 1]) child++;
			if (heap[parent] <= heap[child]) break;
			int t = heap[child]; heap[child] = heap[parent]; heap[parent] = t; count++;
			parent = child;
			child = parent * 2 + 1;
		}
		return minValue;
	}
};
template
<
	typename TYPE,
	std::size_t SIZE
>
TYPE* heapSort(const TYPE(&array)[SIZE])//ヒープソート
{
	TYPE* array_ = new TYPE[SIZE];
	memcpy(array_, array, sizeof(array));
	int n = SIZE;
	//std::vector<TYPE> heap;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	heap.push_back(array_[i]);
	//}
	//std::make_heap(heap.begin(), heap.end());
	//for (int i = SIZE - 1; i >= 0; i--)
	//{
	//	array_[i] = heap.front();
	//	std::pop_heap(heap.begin(), heap.end());
	//	heap.pop_back();
	//}
	HeapArray* heap = new HeapArray(n);
	for (int i = 0; i < n; i++) heap->push(array_[i]);
	for (int i = 0; i < n; i++) array_[i] = heap->pop();
	std::cout << "HeapSort   " << heap->count << std::endl;
	return array_;
}
int qcount = 0;
template
<
	typename TYPE
>
void qsort(TYPE * array, int left, int right) {
	if (right <= left) return;
	int i = left; int j = right; int x = array[(i + j) / 2];
	while (i <= j) {
		while (array[i] < x) i = i + 1;
		while (array[j] > x) j = j - 1;
		if (i <= j) {
			TYPE t = array[i]; array[i] = array[j]; array[j] = t; qcount++;
			i++; j--;
		}
	}
	qsort(array, left, j); qsort(array, i, right);
}
template
<
	typename TYPE,
	std::size_t SIZE
>
TYPE* quickSort(const TYPE(&array)[SIZE])//クイックソート
{
	TYPE* array_ = new TYPE[SIZE];
	memcpy(array_, array, sizeof(array));
	int n = SIZE;
	qsort(array_, 0, n - 1);
	std::cout << "QuickSort   " << qcount << std::endl;
	return array_;
}
template
<
	typename TYPE,
	std::size_t SIZE
>
void pushRandomNumbers(TYPE(&array)[SIZE])//ランダムな数列の作り方
{
	std::vector<int> randomNumbers;
	for (int i = 0; i < SIZE; i++)
	{
		randomNumbers.push_back(i + 1);
	}
	for (auto& i : array)
	{
		int n = randomNumbers.size();
		n = rand() % n;
		i = randomNumbers[n];
		randomNumbers.erase(randomNumbers.begin() + n);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	clock_t start[8], finish[8];//実行時間を計測
	double totaltime[8];
	int randomArray100[100];
	int randomArray10000[100000];
	pushRandomNumbers(randomArray100);
	pushRandomNumbers(randomArray10000);
	start[0] = clock();
	int* bubbleSort100 = bubbleSort(randomArray100);
	finish[0] = clock();
	start[1] = clock();
	int* shellSort100 = shellSort(randomArray100);
	finish[1] = clock();
	start[2] = clock();
	int* heapSort100 = heapSort(randomArray100);
	finish[2] = clock();
	start[3] = clock();
	int* quickSort100 = quickSort(randomArray100);
	finish[3] = clock();
	start[4] = clock();
	int* bubbleSort10000 = bubbleSort(randomArray10000);
	finish[4] = clock();
	start[5] = clock();
	int* shellSort10000 = shellSort(randomArray10000);
	finish[5] = clock();
	start[6] = clock();
	int* heapSort10000 = heapSort(randomArray10000);
	finish[6] = clock();
	start[7] = clock();
	int* quickSort10000 = quickSort(randomArray10000);
	finish[7] = clock();
	//print(randomArray10000);
	//print(bubbleSort10000, array_length(randomArray10000));
	for (int i = 0; i < 8; i++)
	{
		totaltime[i] = ((double)(finish[i] - start[i])) / CLOCKS_PER_SEC;
		std::cout << totaltime[i] << " Seconds" << std::endl;
	}
	return 1;
}
/*/////////出力結果///////////
BubbleSort   2338
ShellSort   414
HeapSort   529
QuickSort   175
BubbleSort   24052632
ShellSort   151566
HeapSort   118809
QuickSort   33784
0 Seconds
0.001 Seconds
0 Seconds
0 Seconds
0.218 Seconds
0.002 Seconds
0.002 Seconds
0.001 Seconds
*////////////////////////////