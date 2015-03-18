/**
 * \file Heap.cpp
 *
 * \author Hannah White
 * 
 * Brief: This program creates a min-heap from randomly generated integers.
 */

#include <stdlib.h>
#include <random>
#include <iostream>
#include <vector>

using namespace std;

void Heapify(vector<int> &h, int i)
{
	int smallest = i;
	int l = (i * 2);
	int r = (i * 2) + 1;

	// determine the smallest of l, r, i
	if ((l < h.size()) && (h[l] < h[i]))
	{
		smallest = l;
	}

	if ((r < h.size()) && (h[r] < h[smallest]))
	{
		smallest = r;
	}

	if (smallest != i)
	{
		int temp = h[i];
		h[i] = h[smallest];
		h[smallest] = temp;
		Heapify(h, smallest);
	}

}


void Build_Heap(vector<int> &h)
{
	for (int i = floor((h.size() - 1) / 2); i >= 0; i--)
	{
		Heapify(h, i);
	}
}

int main()
{
	uniform_int_distribution<int> dist(0, 400);
	default_random_engine eng;

	int size;
	vector<int> heap;

	eng.seed(rand());

	cout << "Enter an array size: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		int num = rand();
		eng.seed(rand());
		heap.push_back(dist(eng));
	}


	cout << "Input Array: ";
	for (auto x : heap)
	{
		cout << x << " ";
	}
	cout << endl;

	Build_Heap(heap);


	cout << "Heap built from the input array: ";
	for (auto y : heap)
	{
		cout << y << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}
