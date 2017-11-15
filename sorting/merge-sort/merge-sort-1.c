#include <stdio.h>

#define MAX 8

int arr[MAX] = {2,4,1,6,8,5,3,7};

void merge(int left[], int l, int right[], int r, int arr[]) {
  int i = 0, j = 0, k = 0;

  while (i < l && j < r) {
    if (left[i] < right[j]) {
      arr[k] = left[i];
      i++;
    }
    else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < l) {
    arr[k] = left[i];
    k++;
    i++;
  }

  while (j < r) {
    arr[k] = right[j];
    k++;
    j++;
  }
}

void split(int arr[], int n) {
  int i, left[MAX], j, right[MAX], k = 0;

  if (n == 1)
  return;

  for (i = 0; i < n/2; i++) {
    left[i] = arr[i];
  }

  for (j = n/2; j < n; j++) {
    right[k] = arr[j];
    k++;
  }

  split(left, i);
  split(right, k);
  merge(left, i, right, k, arr);
}

void main() {
  split(arr, MAX);

  int i;
  for (i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
