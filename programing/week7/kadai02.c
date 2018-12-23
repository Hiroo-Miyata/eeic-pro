#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[20];
    int age;
    double weight;
    double height;
    struct person *next;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [input file]\n", argv[0]);
        return 1;
    }

  	FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    struct person *person1, *first;
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
            first = person2;
        } else {
            person1 -> next = person2;
        }
        person1 = person2;
    }
    fclose(fp);

    for (person1 = first; person1 != NULL; person1 = person1 -> next) {
        printf("name: %s, age: %d, weight: %f, height: %f\n", person1 -> name, person1 -> age, person1 -> weight, person1 -> height);
    }

	return 0;
}
