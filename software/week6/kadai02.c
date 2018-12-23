#include <stdio.h>

double pie( double x0, int N );

int main() {
  for (int i = 1; i <= 100; i ++) {
      printf("N = %d => pie = %lf\n", i, pie(0.1, i));
  }
  printf("N = 1000 => pie = %lf\n", pie(0.1, 1000));
  return 0;
}

double pie(double x0, int N) {
    int x = x0 * 1000;
    for (int i = 0; i < N; i ++) {
        if (x <= 500) {
            x = 2 * x;
        } else {
            x = 2000 - 2 * x;
        }
    }
    return (double)x / 1000;
}
