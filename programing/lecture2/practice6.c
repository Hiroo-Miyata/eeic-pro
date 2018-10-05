#include <stdio.h>

int gcd(int, int);

int main() {
  int x;
  int y;
  int z;
  for (x=1;x<1000;x++) {
    for (y=1;y<x;y++) {
      for (z=1;z<1000;z++) {
        if ((x*x) + (y*y) == (z*z)) {
          // printf("きたよ！");
          if (gcd(x,y) == 1) {
            printf("%d^2 + %d^2 = %d^2\n", x, y, z);
          }
        }
      }
    }
  }
}


int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
