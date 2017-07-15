#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//mergesort


void merge(int A[], int p, int q, int r)
{
	//p <= q < r (indices for the subarrays)
	//--> create left as arr[p...q], right as arr[q...r - 1]

	int size_l = q - p + 1; //size of left array
	int size_r = r - q; //size of right array

	int left[size_l + 1], right[size_r + 1]; //left and right arrays

	int MAXINT = 2147483647; //sentinel

	for(int i = 0; i < size_l + 1; i++) left[i] = A[p + i]; //initializer for left
	for(int j = 0; j < size_r + 1; j++) right[i] = A[q + j]; //initializer for right

	left[size_l] = MAXINT;
	right[size_r] = MAXINT;

	int i = 0, j = 0; //"pointers" to each location within left and right

	for(int k = p; k < r; k++)
	{
		if(left[i] <= right[j]) //check which one is smaller
		{
			A[k] = left[i]; //set value of the current index to the smaller one
			i++; //increment "pointer" in left
		}

		else
		{
			A[k] = right[j]; //set the value of the current index to the smaller one
			j++; //increment "pointer" in right
		}
	}
}



void mergesort(int A[], int p, int r)
{
	//q isn't an argument because we're defining it to be mid

	if(p < r) //safety lolol
	{
		int q = ceil((p + r)/2);
		mergesort(A, p, q); //recurse
		mergesort(A, q + 1, r); //recurse
		merge(A, p, q, r); //merge once you reach the bottom, then keep merging while going back up
	}
}

