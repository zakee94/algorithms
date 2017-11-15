/*  i-th order statistic means the i-th smallest element in the array
 *  One way to do this is to sort the array and then print out the i-th element,
 *  but this can maximum give us an O(nlogn) ti,e complexity.
 *  However by randomized selection we can achieve O(n) time !
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define SIZE 10

int arr[SIZE] = {2,9,-8,1,6,8,5,3,4,7};

// Randomly choose a pivot
// Probablistic analysis showns it gives us an average of O(n) time complexity
int choose_pivot(int arr[], int start, int end) {
  return rand()%(end-start) + start;
}

void swap(int arr[], int i, int j) {
  int temp;

  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// Implemented by choosing rightmost element as pivot
// In-place RSelecting by Lomuto partitioning
int RSelect(int arr[], int start, int end, int st_order) {
  if (start >= end)
    return arr[start];

  int piv_index = choose_pivot(arr, start, end);
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
    return RSelect(arr, start, i-1, st_order);

  if (i < st_order)
    return RSelect(arr, i+1, end, st_order);

}

int main() {
  int i;
  srand(time(NULL));

  cin >> i; // Assume value of i : (0 <= i <= SIZE)
  cout << i << "-th  order statistic : " << RSelect(arr, 0, SIZE-1, i-1) << "\n";

  return 0;
}
