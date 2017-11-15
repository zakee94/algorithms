#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8

int arr[MAX] = {2,7,1,6,8,5,3,4};

// Randomly choose a pivot
// Probablistic analysis showns it gives us an average of O(nlogn) time complexity
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
// In-place partitioning by Lomuto method
void partition(int arr[], int start, int end) {
  if (start >= end)
    return;

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

  partition(arr, start, i-1);
  partition(arr, i+1, end);
}

void main() {
  srand(time(NULL));
  partition(arr, 0, MAX-1);

  int i;
  for (i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
