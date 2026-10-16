
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;


Person *create_person(const char *name, int age) {
    Person *person = malloc(sizeof(Person));

    if (person == NULL) {
        return NULL;
    }

    strcpy(person->name, name);
    person->age = age;

    person->father = NULL;
    person->mother = NULL;

    return person;
}

void read_person_info(const char *role, char *name, int *age) {
    char age_input[20];

    printf("Enter name for %s: ", role);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter age for %s: ", role);
    fgets(age_input, 20, stdin);
    sscanf(age_input, "%d", age);
}

int main(void) {
    char name[50];
    int age;

    Person *pgf, *pgm, *mgf, *mgm;
    Person *father, *mother, *child;

    read_person_info("Paternal Grandfather", name, &age);
    pgf = create_person(name, age);

    read_person_info("Paternal Grandmother", name, &age);
    pgm = create_person(name, age);

    read_person_info("Maternal Grandfather", name, &age);
    mgf = create_person(name, age);

    read_person_info("Maternal Grandmother", name, &age);
    mgm = create_person(name, age);

    read_person_info("Father", name, &age);
    father = create_person(name, age);

    read_person_info("Mother", name, &age);
    mother = create_person(name, age);

    read_person_info("Yourself", name, &age);
    child = create_person(name, age);

    printf("\nAll seven family members entered.\n");

    return 0;
}