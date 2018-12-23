#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1000

char* change_raw(char* raw, int length);

int main() {
    FILE *fpr;
    if ((fpr = fopen("data.txt", "r")) == NULL) {
        return 1;
    } else {
        char raw[LENGTH];
        fgets(raw, LENGTH, fpr);
        fclose(fpr);
        char *changed = change_raw(raw, LENGTH);
        FILE *fpw;
        fpw = fopen("data_zip.txt", "w");
        fputs(changed, fpw);
        fclose(fpw);

    }
    return 0;
}
//標準出力ではなく、読み込みなので、10以上の連続数を表示するのが難しかったので、2^3までで表示するようにしている
char* change_raw(char* raw, int length) {
    char *changed, first;
    int continuous, index;
    changed = malloc(length);
    index = 0;
    continuous = 1;
    first = '\0';
    for (int i = 1;i < strlen(raw); i ++) {
        if (raw[i] == first) {
            if (i == strlen(raw) - 1) {
                continuous ++;
                changed[index] = first;
                changed[index + 1] = continuous + '0';
                changed[index + 2] = '\0';
                printf("%c%d", first, continuous);
            } else {
                continuous ++;
            }
        } else if (first != '\0') {
            if (i == strlen(raw) - 1) {
                changed[index] = first;
                changed[index + 1] = continuous + '0';
                printf("%c%d", first, continuous);
                first = raw[i];
                continuous = 1;
                index += 2;
                changed[index] = first;
                changed[index + 1] = continuous + '0';
                printf("%c%d", first, continuous);
            } else {
                changed[index] = first;
                changed[index + 1] = continuous + '0';
                printf("%c%d", first, continuous);
                first = raw[i];
                continuous = 1;
                index += 2;
            }
        } else {
            first = raw[i];
        }
    }
    return changed;
}
