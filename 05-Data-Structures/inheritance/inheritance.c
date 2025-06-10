// Simulate genetic inheritance of blood type
#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2]; // every person will have an array of 2 parents, where each of those parents is a pointer to another person
    char alleles[2]; // every person will have an array of size 2 of 2 alleles, representing which 2 alleles this particular person has
} person;

// in example:
  // considering person baby:
  // baby.parents[0] is a pointer to person dad (himself having parents, and 2 alleles). Imagine dad.alleles = ["A", "B"]
  // baby.parents[1] is a pointer to person mom (same). Imagine mom.alleles = ["O", "O"]
  // baby.alleles[0] = "A" & baby.alleles[1] = "O" (for ex)


const int GENERATIONS = 3; // simulate the nb of generations of data we will simulate generating
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();
int random_0_or_1();


int main(void)
{
    // Seed random number generator
    srandom(time(0)); // randomly choose "0" or "1" for index of alleles chosen

    // Create a new family with three generations
    person *p = create_family(GENERATIONS); // returns a pointer to the most recent generation of person in that family
      // example: if GENERATIONS = 3, the pointer points to the grandchild

    // Print family tree of blood types, as a hierarchical tree, printing type which blood type each person in the family has
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // The create_family function takes an integer (generations) as input and should allocate (as via malloc)
    // one person for each member of the family of that number of generations, returning a pointer to the person in the youngest generation.
    // For example, create_family(3) should return a pointer to a person with two parents, where each parent also has two parents.

    // TODO: Allocate memory for new person
    person *child = malloc(sizeof(person));
    // use that person to potentially generate ancestors if there are more generations you need to work with

    // If there are still generations left to create
    // I need to recursively create those previous generations
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        // using the return values I get from those create_family functions, I'll update these new person's parents,
        // seting parents[0] equal to the result of 1 recursive call, and parents[1] to the result of some other recursive call

        (*child).parents[0] = parent0;
        (*child).parents[1] = parent1;

        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        // inheriting 1 allele from each parent at random

        // get the alleles
        int r0 = random_0_or_1();
        char allele0 = (*parent0).alleles[r0];
        int r1 = random_0_or_1();
        char allele1 = (*parent1).alleles[r1];

        // assign the alleles to the child
        child->alleles[0] = allele0;
        child->alleles[1] = allele1;

    }

    // If there are no generations left to create
    // aka, if there are no parent data
    // aka, only generating an individual person with no parents

    else
    {
        // TODO: Set parent pointers to NULL
        // if that's the case, both of the parent pointers should be set to NULL
        child->parents[0] = NULL;
        child->parents[1] = NULL;

        // TODO: Randomly assign alleles
        // use random_allele()

        // get the alleles
        char allele0 = random_allele();
        char allele1 = random_allele();

        // assign the alleles to the child
        child->alleles[0] = allele0;
        child->alleles[1] = allele1;

    }

    // TODO: Return newly created person
    return child;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    // if the input to free_family is NULL, no action to be taken.
    if (p == NULL)
    {
        return;
    }

    // TODO: Free parents recursively
    // call the free_family function on each of the child's 2 parents
    person *dad_pointer = (*p).parents[0];
    person *mom_pointer = (*p).parents[1];
    free_family(dad_pointer);
    free_family(mom_pointer);

    // TODO: Free child
    // use free(child)
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = random() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}

int random_0_or_1()
{
    int r = random() % 2;
    if (r == 0)
    {
        return 0;
    }
    else
    {
      return 1;
    }
}
