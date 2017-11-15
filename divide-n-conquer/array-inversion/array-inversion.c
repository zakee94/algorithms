// Count the number of inversion in an array using merge sort
// worst case -> O(nlogn), we find it completely similar to merge sort
#include <stdio.h>
#include <stdlib.h>

typedef long long unsigned int integer;

integer merge(integer left[], integer l, integer right[], integer r, integer arr[]) {
  integer i = 0, j = 0, k = 0, count = 0;

  while (i < l && j < r) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    }
    else {
      arr[k] = right[j];
      j++;
      // Note Carefully ->
      count = count + (l-i); // The only differnece between merge sort and this !
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

  return count;
}

integer split(integer arr[], integer n) {
  integer i, left[n], j, right[n], k = 0, x, y, z;

  if (n == 1)
  return 0;

  for (i = 0; i < n/2; i++) {
    left[i] = arr[i];
  }

  for (j = n/2; j < n; j++) {
    right[k] = arr[j];
    k++;
  }

  return split(left, i) + split(right, k) + merge(left, i, right, k, arr);
}

void main() {
  integer i, size, j, d;
  scanf("%llu", &d);

  for ( j = 0; j < d; j++) {
      scanf("%llu", &size);
      integer* arr = (integer*)malloc(sizeof(integer)*size);

      for (i = 0; i < size; i++)
        scanf("%llu", &arr[i]);

      printf("%llu\n", split(arr, size));
  }
}
