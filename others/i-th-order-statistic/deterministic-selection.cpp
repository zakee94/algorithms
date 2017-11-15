/*  i-th order statistic means the i-th smallest element in the array
 *  One way to do this is to sort the array and then print out the i-th element,
 *  but this can maximum give us an O(nlogn) ti,e complexity.
 *  However by deterministic selection we can achieve O(n) time !
 */

/*  Also known as BFPRT or PICK algorithm.
 *  Founded by Blum, Floyd, Pratt, Rivest & Tarjan in 1973.
 *  Considered an impractical algorithm because of more auxillary space consumption
 *  than randomized selection, and is actually slower than it during practical benchmarking.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;
#define SIZE 20

int arr[SIZE] = {2,9,10,1,6,8,5,3,4,7,19,18,17,20,16,15,14,12,13,11};

void swap(int arr[], int i, int j) {
  int temp;

  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int getIndex(int arr[], int start, int end, int element) {
    int i;

    for (i = start; i <= end; i++)
        if (arr[i] == element)
            return i;
}

// Main or crux function which calculates "Median of Medians"
int computeMedian(int arr[], int start, int end) {
    if (start >= end) {
      free(medians);
      return arr[start];
  }

    int size_med_arr = (end - start + 1) / 5;
    int i = 0;
    int* medians;

    if (size_med_arr != 0 && ((end - start + 1) % 5) == 0)
        medians = (int*)malloc(sizeof(int) * (size_med_arr));
    else if (size_med_arr != 0 && ((end - start + 1) % 5) != 0)
        medians = (int*)malloc(sizeof(int) * (size_med_arr + 1));
    else
        medians = (int*)malloc(sizeof(int) * 1);

    while (end - start > 3) {
        sort(arr + start, arr + start + 5);

        medians[i] = arr[start + 2];
        i++;
        start = start + 5;
    }
    if (start <= end) {
        sort(arr + start, arr + end + 1);
        medians[i] = arr[(start + end + 1)/2];
    }
    else
        i--;

    computeMedian(medians, 0, i);
}

// Implemented by choosing rightmost element as pivot
// In-place DSelecting by Lomuto partitioning
int DSelect(int arr[], int start, int end, int st_order) {
  if (start >= end)
    return arr[start];

  int piv_index = getIndex(arr, start, end, computeMedian(arr, start, end));
  swap(arr, end, piv_index); // Swap the random pivot with rightmost element

  int i = start, j;
  for (j = start; j <= end; j++) {
    if (arr[j] < arr[end]) {
      swap(arr, i, j);
      i++;
    }
  }
  swap(arr, i, end);

  if (i == st_order)
    return arr[i];

  if (i > st_order)
    return DSelect(arr, start, i-1, st_order);

  if (i < st_order)
    return DSelect(arr, i+1, end, st_order);

}

int main() {
  int i;

  cin >> i; // Assume value of i : (0 <= i <= SIZE)
  cout << i << "-th  order statistic : " << DSelect(arr, 0, SIZE-1, i-1) << "\n";

  return 0;
}
