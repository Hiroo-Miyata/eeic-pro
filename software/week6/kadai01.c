#include <stdio.h>
#include <stdlib.h>
#define MAXCT 30000
double random_float(double, double);

int main()
{
    int seed;
    int k,ct=0;
    float x,y;
    scanf("%d",&seed); /* シードの入力 */
    printf("seed = %d\n",seed);
    srand(seed);       /* 乱数の初期化 */
    for (k = 0; k < MAXCT; k ++) {
        x = random_float(-1, 1);
        y = random_float(-1, 1);
        if (x * x + y * y < 1) {
          ct++;
        }
    }

    printf("Approx. PI = %f\n",4.0*ct/MAXCT);

}  /* minとmaxの間の実数乱数を発生する関数 */
double random_float(double min, double max) {
    return min + ((max-min)*rand())/RAND_MAX;
}
