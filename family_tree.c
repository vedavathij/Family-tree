
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
    *age = 0;
    sscanf(age_input, "%d", age);
}

void link_parents(Person *child, Person *father, Person *mother) {
    child->father = father;
    child->mother = mother;
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


    // Connect the family members
link_parents(father, pgf, pgm);
link_parents(mother, mgf, mgm);
link_parents(child, father, mother);

// Print family relationships
printf("\n=== FAMILY TREE RELATIONSHIPS ===\n");

printf("\n1. YOURSELF:\n");
printf("- Name: %s | Age: %d\n", child->name, child->age);

printf("\n2. PARENTS:\n");
printf("- Father: %s | Age: %d\n",
       child->father->name, child->father->age);
printf("- Mother: %s | Age: %d\n",
       child->mother->name, child->mother->age);

printf("\n3. PATERNAL GRANDPARENTS:\n");
printf("- Grandfather: %s | Age: %d\n",
       child->father->father->name,
       child->father->father->age);
printf("- Grandmother: %s | Age: %d\n",
       child->father->mother->name,
       child->father->mother->age);

printf("\n4. MATERNAL GRANDPARENTS:\n");
printf("- Grandfather: %s | Age: %d\n",
       child->mother->father->name,
       child->mother->father->age);
printf("- Grandmother: %s | Age: %d\n",
       child->mother->mother->name,
       child->mother->mother->age);
	free(pgf);
free(pgm);
free(mgf);
free(mgm);
free(father);
free(mother);
free(child);

    return 0;
}





