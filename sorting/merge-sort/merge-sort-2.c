// Another implementation of merge sort but this time
// passing index of array rather than array.
// In-place partitioning by Lomuto method.

#include <stdio.h>

#define MAX 8

int arr[MAX] = {2,4,1,6,8,5,3,7}, new[MAX];

void copy(int arr[], int new[], int start, int end) {
  int i, k = 0;

  for (i = start; i <= end; i++) {
    arr[i] = new[k];
    k++;
  }
}

void merge(int arr[], int new[], int start, int mid, int end) {
  int i = start, j = mid+1, k = 0;

  while (i <= mid && j <= end) {
    if (arr[i] < arr[j]) {
      new[k] = arr[i];
      i++;
    }
    else {
      new[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    new[k] = arr[i];
    k++;
    i++;
  }

  while (j <= end) {
    new[k] = arr[j];
    k++;
    j++;
  }
}


void split(int arr[], int new[], int start, int end) {
  int i, mid;

  mid = (end + start)/2;

  if (start == end)
    return;

  split(arr, new, start, mid); //left
  split(arr, new, mid+1, end); //right
  merge(arr, new, start, mid, end); //merge

  /* Why this method "copy()" ?
     Note in merge() that we are saving the merged changes inot a new array, new[]
     We cant put the merged changes directly in arr[] as this would lead to conflicts
     while further execution of merge().
        Hence we need to copy back the changes from new[] to original array to
     successfully implement the sort.
  */
  copy(arr, new, start, end);
}

void main() {
  split(arr, new, 0, MAX-1);

  int i;
  for (i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
