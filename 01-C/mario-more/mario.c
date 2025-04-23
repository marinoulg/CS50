#include <cs50.h>
#include <stdio.h>

// Prototypes
int get_row(int input);
int get_row_backwards(int input);
int get_space(int input);
int get_positive_int(void);

// Main function
int main(void)
{
    int num = get_positive_int();

    for (int i = 0; i < num; i++)
    {
        get_space(num - i);
        get_row(i + 1);
        printf("  ");
        get_row(i + 1);
        printf("\n");
    }
}

// Helper functions
int get_space(int input)
{
    for (int i = 0; i < input - 1; i++)
    {
        printf(" ");
    }
    return 0;
}

int get_row_backwards(int input)
{
    for (int i = 0; i < input; i++)
    {
        printf("#");
    }
    printf("\n");
    return 0;
}

int get_positive_int(void)
{
    int n; // initialize variable
    do
    {
        n = get_int("Number: "); // you procede to give this variable a value
    }
    while (n < 1);
    return n; // you want a function to have a return value
}

int get_row(int input)
{
    for (int i = 0; i < input; i++)
    {
        printf("#");
    }
    return 0;
}
