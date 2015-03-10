//
//  InsertionQuickSort.cpp
//  CSE 331 Sorting Algorithms
//
//  Created by Hannah White on 2/7/15.
//  Copyright (c) 2015 Hannah White. All rights reserved.
//

#include <vector>
#include <iostream>
#include <random>

using namespace std;

default_random_engine eng;
uniform_int_distribution<int> dist(1, 1000);

void insertion_sort(vector<int> &A)
{
	size_t size = A.size();
	for (int i = 0; i < size; i++)
	{
		int j = i;
		while (j > 0 && A[j] < A[j - 1]){
			int temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
}

void quickSort(vector<int> &A, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = A[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i <= j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(A, left, j);
	if (i < right)
		quickSort(A, i, right);
}

int main()
{
	// short integer random number generator from stdlib
	//int rand(void);

	int size;
	//timeval start, end; // type defined in sys/time.h.
	double start_sec, end_sec, t_sec;

	cout << endl << " ----- insertion/quicksort comparison ----- " << endl;
	cout << endl << "How many elements to sort: - ";  cin >> size;

	// build a vector of random values
	vector<int> B;
	for (int k = 0; k < size; k++)
	{
		B.push_back(dist(eng));
	}

	// make a copy of B to use later in quicksort
	vector<int> C = B;

	cout << endl << "Insertion sort of Integer data initially in random order: " << endl;

	// get time at start of function
	//gettimeofday(&start, NULL);

	insertion_sort(B);

	//gettimeofday(&end, NULL);

	// convert to seconds and print
	/*start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
	end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
	t_sec = end_sec - start_sec;
	cout << "For N = " << size << " # seconds = " << t_sec << "\n";*/

	cout << "First five sorted elements: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	cout << "Last five sorted elements: " << endl;
	for (int i = 5; i > 0; i--)
	{
		cout << B[size - i] << " ";
	}
	cout << endl;

	cout << endl << "Quick Sort of Integer data initially in random order: " << endl;

	// get time at start of quicksort
	//gettimeofday(&start, NULL);

	quickSort(C, 0, size - 1);

	// get time at end of quicksort
	//gettimeofday(&end, NULL);

	// convert to seconds and print out
	/*start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
	end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
	t_sec = end_sec - start_sec;
	cout << "For N = " << size << " # seconds = " << t_sec << "\n";*/

	cout << "First five sorted elements: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;

	cout << "Last five sorted elements: " << endl;
	for (int i = 5; i > 0; i--)
	{
		cout << C[size - i] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}