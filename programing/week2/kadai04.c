#include <stdio.h>
#include <math.h>

int is_prime(int);

int main () {
  double mul = 1;
  int i;
  for (i=2;i<=1000000;i++) {
    if (is_prime(i) == 1) {
      mul = mul * (1 - (1 / pow(i, 2)));
    }
  }
  double pi = sqrt((6 / mul));
  printf("%15.14lf\n", pi);
}


int is_prime(int n) {
  int i;
  for (i=2;i<n;i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
