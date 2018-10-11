#include <stdio.h>
#include <stdlib.h>

#define winrate 80

char* get_hand(int);
char* result_fight(int);

int main() {
  srand(1);
  while (1) {
    int my_hand;
    int ai_hand;
    int result;

    char c[100];
    scanf("%c", c);
    if (rand() % 100 < winrate) {
        result = 1;
    }else{
      if (rand() % 2 == 0) {
        result = 0;
      }else {
        result = -1;
      }
    }
    if ( c[0] == 'g' || c[0] == 'G') {
      my_hand = 0;
      ai_hand = result + my_hand;
      printf("あなたは%sを出しました．私は%sを出しました．あなたの%s！\n", get_hand(my_hand), get_hand(ai_hand), result_fight(result));
    }else if (c[0] == 'c' || c[0] == 'C') {
      my_hand = 1;
      ai_hand = result + my_hand;
      printf("あなたは%sを出しました．私は%sを出しました．あなたの%s！\n", get_hand(my_hand), get_hand(ai_hand), result_fight(result));
    }else if (c[0] == 'p' || c[0] == 'P') {
      my_hand = 2;
      ai_hand = result + my_hand;
      printf("あなたは%sを出しました．私は%sを出しました．あなたの%s！\n", get_hand(my_hand), get_hand(ai_hand), result_fight(result));
    }else if (c[0] == 'q' || c[0] == 'Q') {
      printf("プログラムを終了します．\n");
      exit(0);
    }else {

    }
  }
  return 0;
}

char *result_fight(int num) {
  if (num == 1) {
    return "勝ち";
  }else if ( num == 0 ) {
    return "引き分け";
  }else {
    return "負け";
  }
}

char *get_hand(int hand) {
  if (hand == 0 || hand == 3) {
    return "グー";
  }else if (hand == 1) {
    return "チョキ";
  }else if (hand == 2 || hand == -1) {
    return "パー";
  }
}
