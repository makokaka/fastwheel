#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int val, int left, int right)
{
	if (left > right)
		return -1;
	if (arr[left] == val)
		return left;
	if (arr[right] == val)
		return right;
	// asending
	int mid = left + (right - left)/2;
	if (arr[mid] == val)
		return mid;

	if (arr[left] < arr[right]) {
		if (val > arr[mid] && val < arr[right]) {
			return search(arr, val, mid, right);
		}
		if (val > arr[left] && val < arr[mid]) {
			return search(arr, val, left, mid);
		}
		return -1;
	} else {
		if (val > arr[right] && val < arr[left])
			return -1;
		if (arr[left] < arr[mid]) {
			if (val > arr[left] && val < arr[mid])
				return search(arr, val, left, mid);
			return search(arr, val, mid, right);
		} else {
			if (val > arr[mid] && val < arr[right])
				return search(arr, val, mid, right);
			return search(arr, val, left, mid);
		}
	}
}

int main()
{
	int arr_test[] = {6, 7, 8, 9, 10, 11, 1, 2, 3, 4};
	int left = 0, right = sizeof(arr_test)/sizeof(int) - 1;
	printf("%d\n", search(arr_test, 10, left, right));
	printf("%d\n", search(arr_test, 5, left, right));
	return 0;
}
