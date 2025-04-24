#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int input_word(int player);

int main(void)
{
  int player1 = 1;
  int player2 = 2;
  int sum1 = input_word(player1);
  int sum2 = input_word(player2);

  if (sum1 > sum2)
  {
    printf("Player 1 wins!\n");
  }
  else if (sum1 < sum2)
  {
    printf("Player 2 wins!\n");
  }
  else
  {
    printf("Tie!\n");
  }
}


int input_word(int player)
{
		string word = get_string("Player %i: ", player);
    int num = 0;
    int length = strlen(word);
    int scores[length];
    int score = 0;
    for (int idx_letter = 0; idx_letter < length; idx_letter++)
    {
      char letter = tolower(word[idx_letter]);
      if (letter == 'a' || letter == 'e' || letter == 'i'|| letter == 'l' || \
          letter == 'n' || letter == 'o' || letter == 'r' || letter == 's' || \
          letter == 't' || letter == 'u')
      {
          num =  1;
      }
      else if (letter == 'd' || letter == 'g')
      {
          num = 2;
      }
      else if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p')
      {
          num = 3;
      }
      else if (letter == 'f' || letter == 'h' || letter == 'v' || letter == 'w' || \
               letter == 'y')
      {
          num = 4;
      }
      else if (letter == 'k')
      {
          num = 5;
      }
      else if (letter == 'j' || letter == 'x')
      {
          num = 8;
      }
      else if (letter == 'q' || letter == 'z')
      {
          num = 10;
      }
      else
      {
          num = 0;
      }
        scores[idx_letter] = num;
        score = score + num;
    }
    return score;
}
