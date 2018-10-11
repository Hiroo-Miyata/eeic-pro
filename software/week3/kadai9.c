#include <stdio.h>
#include <math.h>

#define NALPHA 26 //アルファベットの種類
int main()
{
  int count[NALPHA];
  int c, i;
  int string_sum = 0;
  for( i = 0 ; i < NALPHA ; ++i ) { //カウント結果を記録する配列を初期化する
    count[i] = 0;
  }

  while( ( c = getchar() ) != EOF ) {
    if(c >= 'a' && c <= 'z') { // cがaからzの間アルファベットであれば、、、
      count[c-'a']++; // 該当するアルファベットのカウント結果を+1する。
      string_sum++;
    }
  }

  double entropy = 0;
  for( i = 0 ; i < NALPHA ; i++ ) {
    if (count[i] != 0) {
      entropy -= ((double)count[i]/string_sum) * log2((double)count[i]/string_sum);
    }
    // printf("%d,%f\n", count[i], log2((double)count[i]/string_sum));
  }
  // printf("%d,%f\n", string_sum, entropy);
  printf("エントロピーは、%eです\n", entropy);
  return 0;
}
