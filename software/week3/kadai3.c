#include <stdio.h>
#include <math.h>

int main() {
  int i;
  printf("M_PI=%f\n", M_PI);
  for (i=1;i<= 1000;i++) {
    double x =  ( -5 * M_PI ) + (i * M_PI / 100);
    printf("%f %f\n", x, (sin(x) / x));
  }
  return 0;
}
