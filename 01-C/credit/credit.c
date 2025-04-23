#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int type_of_card(string card_numbers);
int multiplication(int n, string s);


int main(void)
{
  // string n = get_string("Number: ");
  // array =
  //
  string s = "4003600000000014";
  int length = strlen(s);
  int result_multi = multiplication(length,s);
  printf("result: %i\n", result_multi);




  int type = type_of_card(s);
  // int num = atoi(n);


}

int type_of_card(string card_numbers)
{
  int length = strlen(card_numbers);
  if (length == 15)
  {
      printf("AMEX\n");
  }
  else if (length == 16)
  {
      printf("MASTERCARD\n");
  }
  else if (length == 13) // || else if (length == 16)
  {
      printf("VISA\n");
  }
  else
  {
      printf("INVALID\n");
  }
  return 0;
}

int multiplication(int n, string s)
{
  int scores[n];
  int num;
  int sum = 0;
	for (int i = 0; i < n; i++)
	{
    if (i%2 == 0)
    {
      // printf("%i\n", num);
      int num = ((s[i] - 48)*2); // convert num : from ASCII, string to int
      // int sum = sum + num;
      // printf("sum: %i\n", sum);
      if (num < 10)
      {
        // printf("M2 - <10: %i\n", num);
        scores[i] = num;
      }
      else if (num > 9)
      {
        // printf("M2 - %i\n", num-10);
        // printf("M2 - %i\n", 1);
        scores[i] = num-9;
      }
	  }
    sum = sum + scores[i];
    if (sum < 100)
    {
      printf("sum: %i\n", sum);
    }

    // else
    // {
    //   int num = ((s[i] - 48));
    //   printf("%i\n", num);
    // }

  }
  return sum;
}
