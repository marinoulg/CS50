#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int const NB_LETTERS_ALPHABET = 26;
int position_letter(char c);
int is_in_array(char c, int array[], int len_array);
int is_letter_duplicated(string text, char c);
int all_chars_unique(string text);

int main(int argc, string argv[])
{
  // Array letters should be converted to (for simplicity, all in CAPS here)
  int array_to_convert_maj[NB_LETTERS_ALPHABET];

  if (argc == 2)
  {
    int sum = 0;
    int length_argv = strlen(argv[1]);
    for (int i = 0; i < length_argv; i++)
    {
      if (isalpha(argv[1][i]))
      {
        sum += 1;
      }
    }

    int boolean = all_chars_unique(argv[1]); // Check if all letters are unique

    if (argc == 2 && sum != NB_LETTERS_ALPHABET)
    {
      printf("Key must contain 26 letters.\n");
      return 1;
    }

    else if (argc == 2 && sum == NB_LETTERS_ALPHABET && boolean == 0)
      {
        // If so, do that
        for (int i = 0; i < NB_LETTERS_ALPHABET; i++)
        {
          char c = argv[1][i];
          array_to_convert_maj[i] = toupper(c);
        }

      // Get array_to_convert_min
        int array_to_convert_min[NB_LETTERS_ALPHABET];

        for (int i = 0; i < NB_LETTERS_ALPHABET; i++)
        {
            array_to_convert_min[i] = tolower(array_to_convert_maj[i]);
        }

        string text = get_string("plaintext: ");
        int len = strlen(text);
        printf("ciphertext: ");

        for (int i = 0; i < len; i++)
        {
          char c = text[i];
          int pos = position_letter(c);

          if (isupper(c))
          {
              printf("%c", array_to_convert_maj[pos]);
          }
          else if (islower(c))
          {
              printf("%c", array_to_convert_min[pos]);
          }
          else
          {
              printf("%c", c);
          }
        }
      }
    else
    {
      return 1;
    }
    printf("\n");

  }
  else
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }
}

int position_letter(char c)
{
  int alphabet_maj[NB_LETTERS_ALPHABET] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',\
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',\
    'W', 'X', 'Y', 'Z'};
  int alphabet_min[NB_LETTERS_ALPHABET] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',\
      'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',\
      'w', 'x', 'y', 'z'};


  for (int i = 0; i < NB_LETTERS_ALPHABET; i++)
  {
    if (c == alphabet_maj[i])
    {
      // printf("Letter %c is %i\n", c, i);
      return i;
    }
    else if (c == alphabet_min[i])
    {
      // printf("Letter %c is %i\n", c, i);
      return i;
    }
  }
  return 0;
}

int is_in_array(char c, int array[], int len_array)
{
  int sum = 0;
  for (int i = 0; i < len_array; i++)
  {
    if (toupper(array[i]) == toupper(c))
    {
      sum += 1;
    }
  }
  if (sum != 1)
  {
    printf("%c is already in array\n", c);
    return 1;
  }
  else
  {
    // printf("Letter %c is not duplicated\n", c);
    return 0;
  }
}

int is_letter_duplicated(string text, char c)
{
  int len = strlen(text);
  int array_test[len];

  for (int i = 0; i < len; i++)
  {
    array_test[i] = text[i];
  }

  int boolean = is_in_array(c, array_test, len);
  // printf("boolean is %i\n", boolean);
  if (boolean == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int all_chars_unique(string text)
{
  {
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
      char c = text[i];
      int boolean = is_letter_duplicated(text, c);
      if (boolean == 1)
      {
        return 1;
      }
    }
    return 0;
  }
}
