#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define K 5 // スロットマシンの数
#define N 100 // コインの数．採点時には1,000,000などの大きな数にする．

int bet(int k); //変更不可
int main() { //自由に変更して良い
    srand((unsigned) time(NULL));
    int credit = N, reward=0, sum=0;

    double looked_value[K];
    int try_sum = N/(K*exp(1.0));
    int i;
    for (i=0;i<K;i++){
      int looked_sum;
      int try;
      double value;
      for (try=0;try<try_sum;try++){
        reward = bet(i);
        looked_sum += reward;
        sum += reward;
      }
      looked_value[i] = looked_sum / try_sum;
    }
    int best_choice = 0;
    int bc;
    double best_value = looked_value[0];
    for (bc=1;bc<K;bc++){
      if (best_value < looked_value[bc]) {
        best_choice = bc;
        best_value = looked_value[bc];
      }
    }

    while(credit-- > 0){
        reward = bet( rand() % 5 );
        sum += reward;
    }
    printf("sum = %f\n",(double) sum / N );

    return 0;
}
// 以下の関数は変更不可
int bet(int k){ // 入力：スロットマシンの番号 出力：当選金
    // これは例であり，採点時には当選金と確率が変化する
    switch(k){
        case 0:
            if(rand() % 2 == 0){ // 2/2
                return 2;
            }else{
                return 0;
            }
            break;
        case 1:
            if(rand() % 7 == 0){ // 5/7
                return 5;
            }else{
                return 0;
            }
            break;
        case 2:
            if(rand() % 8 == 0){ // 10/8
                return 10;
            }else{
                return 0;
            }
            break;
        case 3:
            if(rand() % 40 == 0){ // 50/4０
                return 50;
            }else{
                return 0;
            }
            break;
        case 4:
            if(rand() % 200 == 0){  // 100/200
                return 100;
            }else{
                return 0;
            }
            break;
        default:
            return 0;
    }
}
