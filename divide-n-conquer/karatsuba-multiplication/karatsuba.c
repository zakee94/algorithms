// Karatsuba method for multiplication of two n-digit numbers.
// [ DIVIDE & CONQUER]

#include <stdio.h>
#include <math.h>

// Calculate digits of a given num.
int digits(int n) {
  int i = 0;

  while (n != 0){
    n = n/10;
    i++;
  }

  return i;
}

int kat_mult(int x, int y) {
  int n, a, b, c, d, ac, bd, mult;

  //If num is of single digit we directly multiply.
  if ((digits(x) == 1) || (digits(y) == 1))
    return x*y;

  n = digits(x)/2;

  // Division of the number from middle
  // x -> a & b, y -> c & d
  b = x%(int)pow(10,(n));
  a = x/(int)pow(10,(n));
  d = y%(int)pow(10,(n));
  c = y/(int)pow(10,(n));

  // 3 recursive calls
  ac = kat_mult(a, c);
  bd = kat_mult(b, d);
  mult = kat_mult((a+b), (c+d));

  // (a+b)(c+d) = ac+bc+ad+bd, To find ad+bc we use Gauss Method
  return ((int)pow(10,n*2)*ac) + ((int)pow(10,(n))*(mult-ac-bd)) + bd;

}

void main() {
  int a, b;

  scanf("%d%d", &a, &b);
  printf("%d\n", kat_mult(a, b));
  printf("%d\n", a*b);
}
