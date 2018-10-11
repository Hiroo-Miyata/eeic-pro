#include <stdio.h>
#include <math.h>
#define NALPHA 26
int main()
{
  int count[NALPHA][NALPHA];
  double prob[NALPHA][NALPHA];
  int c, i, j, sum; int first, second, minidx, maxidx;
  double entropy;

  for( i = 0 ; i < NALPHA ; i++ ) {
    for( j = 0 ; j < NALPHA ; j++ ) {
      count[i][j] = 0;
    }
  }
  second = ' ';

  while( ( c = getchar() ) != EOF ) { // 現在読み込んだ文字はcに代入されている
    first = second;
    second = c;
    if( first >= 'a' && first <= 'z' && second >= 'a' && second <= 'z' ) {
      count[first-'a'][second-'a']++; // アルファベットが続く場合はカウントアップ
    }
  }

  for( i = 0 ; i < NALPHA ; i++ ) { // 確率を計算するループ
    sum = 0;

    for( j = 0 ; j < NALPHA ; j++ ) {
      sum += count[i][j];
    }
    for( j = 0 ; j < NALPHA ; j++ ) {
      prob[i][j] = (double)count[i][j]/(double)sum;
    }
  }

  for( i = 0 ; i < NALPHA ; i++ ) { //表示
    entropy = 0;
    for( j = 0 ; j < NALPHA ; j++ ) {
      if( prob[i][j] > 0.0 ) {
        entropy -= (prob[i][j]) * log2(prob[i][j]);
      }

    }
    printf( "[%c]: ent = %e\n", 'a'+i, entropy);
  }
  return 0;
 }
