#include <stdio.h>
#include <stdlib.h>

void array_string(int);

int main() {
  array_string(0);
  array_string(2);
  array_string(1);
  array_string(0);
}

void array_string(int f) {
  char strarray[3][10] = {"pen", "apple", "pineapple"};
  int s;
  for (s=0;s < sizeof(strarray[f]);s++){
    if (s == 3 && strarray[f][s] == 'e') {

    }else{
      printf("%c", strarray[f][s]);
    }
  }
  printf(" ");
  return;
}
