#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10

int main() {
    int is_data_exist = 1;
    char matrix[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i ++) {
        for (int j = 0; j < WIDTH; j ++) {
            matrix[i][j] = '-';
        }
    }
    FILE *fpr;
    if ((fpr = fopen("data.txt", "r")) == NULL) {
        printf("data.txtが存在しません．\n");
    } else {
        char str[HEIGHT * WIDTH];
        fgets(str, HEIGHT * WIDTH + 1, fpr);
        for (int i = 0; i < HEIGHT; i ++) {
            for (int j = 0; j < WIDTH; j ++) {
                matrix[i][j] = str[i * WIDTH + j];
            }
        }
        is_data_exist = 0;
    }
    fclose(fpr);

    while(1) {
        if (is_data_exist) {
            char *input, c;
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
        }

        FILE *fpw;
        fpw = fopen("data.txt", "w");
        for (int i = 0; i < HEIGHT; i ++) {
            for (int j = 0; j < WIDTH; j ++) {
                fputc(matrix[i][j], fpw);
            }
        }
        fclose(fpw);
        system("clear");
        for (int i = 0; i < HEIGHT; i ++) {
            for (int j = 0; j < WIDTH; j ++) {
                printf("%c ",matrix[i][j]);
            }
            printf("\n");
        }
        is_data_exist = 1;
    }

    return 0;
}
