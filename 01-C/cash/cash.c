#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int n = get_positive_int();

    int a = n / 25;
    int rest = n - (a * 25);

    int b = rest / 10;
    int new_rest = rest - (b * 10);

    int c = new_rest / 5;
    int new_rest_2 = new_rest - (c * 5);

    int sum_pieces = a + b + c + new_rest_2;

    printf("%i\n", sum_pieces);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 1);
    return n;
}
