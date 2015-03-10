#include <vector>
#include <iostream>

//#include <sys/time.h>
#include <random>

using namespace std;

default_random_engine eng;
uniform_int_distribution<int> dist(1, 1000);

void insertion_sort(vector<int> &A)
{
	size_t size = A.size();
	for (int i = 0; i < size; i++)
	{
		int key = A[i];
		int j = i - 1;
		while ((j >= 0) & (A[j] > key))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}

}

int partition(vector<int> &A, int l, int r)
{
	int pivot = A[r];
	int i = l - 1;
	int j = r;
	for (;;)
	{
		while ((A[++i] < pivot) & (i <= r))
		{
		}
		while ((A[--j] > pivot) & (j >= l))
		{
		}
		if (i < j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
		{
			break;
		}
	}

	int temp2 = A[i];
	A[i] = A[r];
	A[r] = temp2;

	return i;

}

void quick_sort(vector<int> &A, int l, int r)
{
	if (l < r)
	{
		int q = partition(A, l, r);
		quick_sort(A, l, q - 1);
		quick_sort(A, q + 1, r);
	}

}

int main()
{
	int size;
	//timeval start, end; // type defined in sys/time.h.
	//double start_sec, end_sec, t_sec;

	cout << endl << " ----- insertion/quicksort comparison ----- " << endl;
	cout << endl << "How many elements to sort: - ";  cin >> size;

	vector<int> B = {};
	for (int k = 0; k < size; k++)
	{
		B.push_back(dist(eng));
	}

	// make a copy of B to use in quicksort
	vector<int> C = B;

	/*cout << endl << "Insertion sort of Integer data initially in random order: " << endl;
	if (size >= 5)
	{
		for (int i = 5; i > 0; i--)
		{
			cout << B[size - i] << " ";
		}
	}*/
	
	cout << endl;

	cout << endl << "Quick Sort of Integer data initially in random order: " << endl;

	//// get time at start of quicksort
	//gettimeofday(&start, NULL);

	quick_sort(C, 0, size-1);

	//// get time at end of quicksort
	//gettimeofday(&end, NULL);

	//// convert to seconds and print out
	//start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
	//end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
	//t_sec = end_sec - start_sec;
	//cout << "For N = " << size << " # seconds = " << t_sec << "\n";

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

