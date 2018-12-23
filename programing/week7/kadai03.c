#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[20];
    int age;
    double weight;
    double height;
    struct person *previous;
    struct person *next;
};

struct person *first, *last;

void delete(struct person *p, char *s) {
    while (p != NULL) {
        if (strcmp(p -> name, s) == 0) {
            if (p -> previous == NULL) {
                p -> next -> previous = NULL;
                first = p -> next;
            } else if (p -> next == NULL) {
                p -> previous -> next = NULL;
                last = p -> previous;
            } else {
                p -> previous -> next = p -> next;
                p -> next -> previous = p -> previous;
            }
        }
        p = p -> next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [input file]\n", argv[0]);
        return 1;
    }

  	FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    struct person *person1;
    person1 = NULL;

    char name[20];
    int age;
    double weight;
    double height;

    while (fscanf(fp, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) != EOF) {
        struct person *person2;
        person2 = (struct person *) malloc(sizeof(struct person));
        strcpy(person2 -> name, name);
        person2 -> age = age;
        person2 -> height = height;
        person2 -> weight = weight;
        person2 -> next = NULL;
        if (person1 == NULL) {
            person2 -> previous = NULL;
            first = person2;
        } else {
            person2 -> previous = person1;
            person1 -> next = person2;
        }
        person1 = person2;
    }
    last = person1;
    fclose(fp);

    char del_name[20];
    printf("誰のデータを消去しますか？\n");
    scanf("%s", del_name);
    delete(first, del_name);

    for (person1 = first; person1 != NULL; person1 = person1 -> next) {
        printf("name: %s, age: %d, weight: %f, height: %f\n", person1 -> name, person1 -> age, person1 -> weight, person1 -> height);
    }

	return 0;
}
