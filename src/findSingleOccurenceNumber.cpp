/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int left, int right);
void one_loop_sort(int *arr, int left, int right);

// METHOD-1: Loop in loop O(N2)
// METHOD-2: efficient Sorting like merge sort or heap sort and running a loop in steps of 3 O(nlogn)
// METHOD-3: Hashing method. Here space is needed O(n)



// METHOD-2: Sorting (Merge Sort)
int findSingleOccurenceNumber(int *A, int len)
{
	int i;
	if (A == NULL || len <= 0)
		return -1;

	merge_sort(A, 0, len - 1);

	for (i = 0; i < len; i += 3)
	{
		if (A[i] != A[i + 1])
			return A[i];
	}

	return -1;
}

/*
// METHOD - 3: Hashing
int findSingleOccurenceNumber(int *A, int len)
{
	int *hash = (int*)calloc(256, sizeof(int));
	int i;
	if (A == NULL || len <= 0)
		return -1;

	for (i = 0; i < len; i++)
		hash[A[i]]++;

	for (i = 0; i < len; i++)
	{
		if (hash[A[i]] == 1)
			return A[i];
	}
	return -1;
}

*/


void merge_sort(int *arr, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		one_loop_sort(arr, left, right);
	}
}

void one_loop_sort(int *arr, int left, int right)
{
	int mid = (left + right) / 2;
	int i, j, k, l_size = mid - left + 1, r_size = right - mid;
	int *left_arr = (int*)malloc(sizeof(int)* l_size), *ryt_arr = (int*)malloc(sizeof(int)*r_size);

	for (i = 0; i < l_size; i++)
		left_arr[i] = arr[left + i];
	for (i = 0; i < r_size; i++)
		ryt_arr[i] = arr[mid + 1 + i];

	i = 0;
	j = 0;
	k = left;
	while (i < l_size && j < r_size)
	{
		if (left_arr[i] <= ryt_arr[j])
		{
			arr[k] = left_arr[i];
			i++;
		}
		else
		{
			arr[k] = ryt_arr[j];
			j++;
		}
		k++;
	}

	while (i < l_size)
	{
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	while (j < r_size)
	{
		arr[k] = ryt_arr[j];
		j++;
		k++;
	}

}
/*
// METHOD - 1: Simple method (loop in loop) O(n2)
int findSingleOccurenceNumber(int *A, int len) 
{
	int i, j, flag = 0;

	if (A == NULL)
		return -1;

	for (i = 0; i < len; i++)
	{
		flag = 0;
		for (j = 0; j < len; j++)
		{
			if (A[i] == A[j] && i != j)
			{
				flag = 1;
				break;
			}

		}
		if (flag == 0)
			return A[i];
	}

	return -1;
}

*/



