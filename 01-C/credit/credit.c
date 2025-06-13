#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int type_of_card(string card_numbers);
int multiplication_bis(int n, string s);

int main(void)
{
  string s = get_string("Number: ");

  // string s = "1234567890"; //  4003600000000014
  // printf("%s\n", s);
  int length = strlen(s);
  // printf("length: %i\n", length);
  int result_multi = multiplication_bis(length,s);

  if (result_multi == 0)
  {
      // int type =
      type_of_card(s);
  }
  else
  {
      printf("INVALID\n");
  }
}

int type_of_card(string card_numbers)
{
  int length = strlen(card_numbers);
  if (length == 15 && card_numbers[0] == '3' && (card_numbers[1] == '4' || card_numbers[1] == '7'))
  {
      printf("AMEX\n");
  }
  else if ((length == 13 || length == 16) && card_numbers[0] == '4')
  {
      printf("VISA\n");
  }
  else if (length == 16 && card_numbers[0] != 4 && card_numbers[0] == '5'&& (card_numbers[1] == '1' || card_numbers[1] == '2' || card_numbers[1] == '3' || card_numbers[1] == '4' || card_numbers[1] == '5'))
  {
      printf("MASTERCARD\n");
  }

  else
  {
      printf("INVALID\n");
      return -1;
  }
  return 0;
}

int multiplication_bis(int n, string s)
{
  // n is the length of the string s

  int next = n-2;
  int others = n - 1;
  // printf("others: %i\n", others);

  int sum = 0;
  int sum_others = 0;

  while (next >= 0 || others >= 0)
  {
    // printf("s of second to last is %i, %c\n", s[next], s[next]);
    int nb = (s[next] - 48) * 2;
    // printf("idx: %i\n", next);
    // printf("nb: %i\n", nb);
    // printf("sum: %i\n", sum);
    // printf("\n");

    if (0 < nb  && nb < 10)
    {
      // printf("YES %i\n", nb);
      sum += nb;
    }
    else if (0 < nb  && nb < 20)
    {
      // printf("before sum: %i\n", sum);
      sum+= (nb-10) + 1;
      // printf("after sum: %i\n", sum);
    }
    // else if (nb < 30)
    // {
    //   sum+= (nb-20) + 2;
    // }
    // else if (nb < 40)
    // {
    //   sum+= (nb-30) + 3;
    // }
    // else if (nb < 50)
    // {
    //   sum+= (nb-40) + 4;
    // }
    // else if (nb < 60)
    // {
    //   sum+= (nb-50) + 5;
    // }

    next = next - 2;

    int other = (s[others] - 48);
    // printf("%i\n", other);

    sum_others += other;

    others = others - 2;
    // printf("other_idx, others %i, %i\n", others, other);
  }
  // printf("outside loop - other %i\n", others);

  // printf("sum: %i\n", sum);
  // printf("sum others: %i\n", sum_others);

  int total_sum = sum + sum_others;
  // printf("Total sum: %i\n", total_sum);

  int modulo = total_sum % 10;
  // printf("Modulo: %i\n", modulo);

  if (total_sum % 10 == 0)
  {
    // printf("Valid.\n");
    return 0;
  }

  else if (total_sum % 2 != 0)
  {
    // printf("Invalid.\n");
    return 1;
  }
  else
  {
    return 2;
  }
}
