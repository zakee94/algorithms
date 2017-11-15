// This implementation for 2D takes O(n(logn)) time.
// We use inbuilt qsort()-ing function of C.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 8
#define FLT_MAX 9999.99

struct Point {
  int x;
  int y;
};
typedef struct Point Point;

// Basic Calculations functions -->
float min(float a, float b) {
  float mini;

  if (b > a)
    mini = a;
  else
    mini = b;

  return mini;
}

float distance(Point p1, Point p2) {
  return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

int compareX(const void *a, const void *b) {
  Point *l = (struct Point *)a;
  Point *r = (struct Point *)b;

  return (l->x - r->x);
}

int compareY(const void *a, const void *b) {
  Point *l = (struct Point *)a;
  Point *r = (struct Point *)b;

  return (l->y - r->y);
}
// End of basic functions ------------------------------------------------------

// For n <= 3 brute force gives best possible time, hence using it
// Also can be used to return from pair we shall see in that function
float brute(Point p[], int n) {
    float mini = FLT_MAX;
    int i, j;

    for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
        if (distance(p[i], p[j]) < mini)
          mini = distance(p[i], p[j]);
      }
    }
    return mini;
}

// For split cases
float split_pair(Point py[], float dl, float dr, int n) {
  Point strip[MAX];
  int k = 0, i, j;
  float mid = ((float)py[n/2].x+(float)py[(n/2)-1].x)/2, d = min(dl, dr);

  // Make a new array consisting of only those points which are less than 'd'
  // strip[] --> a thin strip from mid-point of radius 'd'
  // array consisting of points in that strip
  for (i = 0; i < n; i++) {
    if (abs(py[i].x-mid) < d) {
      strip[k] = py[i];
      k++;
    }
  }

  /* Now from the smallest Y coordinate push up upto a distance 'd'
   and among a strip of breadth(diameter) = '2d' let's search for smallest distance
    ____________
    |          |  --> We search inside a rectangle of dimesion = '2d x d' for each "n"
    |__________|      Magically we only have to search for 6 times.

   Hence a total of 6n operations rather than n^2. Magically algorithmic, ain't it ?
  */
  for (i = 0; i < k; i++) {
    for (j = i+1; j < k && strip[j].y < d+strip[i].y; j++) {
      if (distance(strip[i], strip[j]) < d)
        d = distance(strip[i], strip[j]);
    }
  }

  return d;
}

float pair(Point px[], Point py[], int n) {
  int i, j, k = 0;
  float mini, dl, dr, dm;
  Point left_x[MAX], right_x[MAX], left_y[MAX], right_y[MAX];

  if (n <= 3)
    return brute(px,n);

    // Divide into 2 halves (X ways)
    for (i = 0; i < n/2; i++) {
      left_x[i] = px[i];
    }

    for (j = n/2; j < n; j++) {
      right_x[k] = px[j];
      k++;
    }

    // Divide into 2 halves (Y ways)
    for (i = 0; i < n/2; i++) {
      left_y[i] = py[i];
    }

    k = 0;
    for (j = n/2; j < n; j++) {
      right_y[k] = py[j];
      k++;
    }

    // Conquer each half separately
    dl = pair(left_x, left_y, i);
    dr = pair(right_x, right_y, k);
    dm = split_pair(py, dl, dr, n); // Note passing of py[], a pre Y-way sorted
                                    // array rather than px[]                                    
    if (dm < dl && dm < dr)
      mini = dm;
    else
      mini = min(dl, dr);

    return mini;
}

void main() {
    Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(p) / sizeof(p[0]), i;

    Point px[n];
    Point py[n];
    for (i = 0; i < n; i++)
    {
        px[i] = p[i];
        py[i] = p[i];
    }

    // Rather than sorting when needed we sort with every recursion
    // Hence pasiing of 2 ways sorted arrays
    qsort(px, n, sizeof(Point), compareX);
    qsort(py, n, sizeof(Point), compareY);

    printf("%f\n", pair(px, py, n));
}

/* Refrences :-
  1. The most clear --> http://www.cs.mcgill.ca/~cs251/ClosestPair/ClosestPairDQ.html
  2. The best --> Stanford lectures.
  3. Coding help --> geekforgeeks.
*/
