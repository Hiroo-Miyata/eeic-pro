#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10

int main() {
    char matrix[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i ++) {
        for (int j = 0; j < WIDTH; j ++) {
            matrix[i][j] = '-';
        }
    }
    while(1) {
        char c;
        int x, y;
        if (scanf("%d", &x) == 0) {
          printf("Usage: Int Int String");
          break;
        }
        if (scanf("%d", &y) == 0) {
          printf("Usage: Int Int String");
          break;
        }
        if (scanf("%s", &c) == 0) {
          printf("Usage: Int Int String");
          break;
        }
        matrix[x][y] = c;
        system("clear");
        for (int i = 0; i < HEIGHT; i ++) {
            for (int j = 0; j < WIDTH; j ++) {
                printf("%c ",matrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
