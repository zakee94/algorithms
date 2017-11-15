// This implementation for 1D takes O(nlogn) time.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 8

int arr[MAX] = {15,-2,2,8,4,7,20,12};

// Merge Sort starts -->
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
// Merge Sort ends -------------------------------------------------------------

int min(int a, int b) {
  int mini;

  if (b > a)
    mini = a;
  else
    mini = b;

  return mini;
}

int split_pair(int arr[], int dl, int dr, int n) {
  float mid = ((float)arr[n/2]+(float)arr[(n/2)-1])/2, d = min(dl, dr);
  int sub = 0, i;

  for (i = 0; i < n; i++) {
    if (abs(arr[i]-mid) < d) {
      sub = abs(arr[i] - sub);
    }
  }
  return sub;
}

int pair(int arr[], int n) {
  int k = 0, i, j, dl, dr, dm, left[n], right[n], mini;

  if (n == 2)
    return abs(arr[0]-arr[1]);

    for (i = 0; i < n/2; i++) {
      left[i] = arr[i];
    }

    for (j = n/2; j < n; j++) {
      right[k] = arr[j];
      k++;
    }

  dl = pair(left, i);
  dr = pair(right, k);
  dm = split_pair(arr, dl, dr, n);

  if (dm < dl && dm < dr)
    mini = dm;
  else
    mini = min(dl, dr);

  return mini;
}

void main() {
  split(arr, MAX);
  printf("%d\n", pair(arr, MAX));
}
