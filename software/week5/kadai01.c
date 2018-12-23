#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 10
#define WIDTH 10

int main() {
    char matrix[HEIGHT][WIDTH];
    //配列にデータの入力
    for (int i = 0; i < HEIGHT; i ++) {
        for (int j = 0; j < WIDTH; j ++) {
            if (i == j) {
                matrix[i][j] = '*';
            } else {
                matrix[i][j] = ' ';
            }
        }
    }　
    //1秒ごとに表示
    for (int i = 0; i < HEIGHT; i ++) {
        system("clear");
        //表示
        for (int j = 0; j <= i; j ++) {
            for (int k = 0; k < WIDTH; k ++) {
                printf("%c ",matrix[j][k]);
            }
            printf("\n");
        }
        //白いやつが動かないようにする
        for (int j = i; j < HEIGHT - 1; j ++) {
            printf("\n");
        }
        sleep(1);
    }
    return 0;
}
