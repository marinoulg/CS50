#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
      {
          printf("Usage: %s key\n", argv[0]);
          return 1;
      }
    else if (argc == 2)
      {
        int key = 0;

        string key_str = argv[1];
        int length = strlen(argv[1]);

        if (length == 1)
          {
              char c = argv[1][0];
              key = (int) c - 48; // convert from ascii character to int
              printf("key (int) is %i\n", key);
          }
        else
          {
              int effective_len = length - 1;
              int array[length];
              for (int i = length - 1; i >= 0; i--)
                {
                    char c = argv[1][i];
                    key = (int) c - 48;
                    if ((int) key > 9)
                      {
                          printf("Usage: %s key\n", argv[0]);
                          return 1;
                      }
                    else
                    {
                        key = (int) pow(10, effective_len - i) * key;
                        array[i] = key;
                    }
                }

              int sum = 0;
              for (int i = 0; i < length; i++)
                {
                  sum += array[i];
                }
            key = sum;
          }

          string str = get_string("Plaintext: ");
          printf("Ciphertext: ");

          if (key)
            {

                int length = strlen(str);
                int how_many = key % 26;


                for (int i = 0; i < length; i++)
                {
                  // if letter
                  char char_ = (str[i]);

                  if (isupper(char_) && isalpha(char_)) // uppercase letter
                    {
                        int nb_letters_left = 'z' - (char_ + 32);
                        // printf("how_many = %i, nb_letters_left = %i\n", how_many, nb_letters_left);
                        int rest = how_many - nb_letters_left;

                        if (rest < 0) // 25 letters left for a key moving of 3
                          {
                            printf("%c", (char_ + how_many));
                          }
                        else if (rest > 0)
                          {
                            // printf("rest is %i\n", rest);
                            printf("%c", (65 + (rest - 1))); // -(-1) = +1 & A = 65
                          }
                    }
                  else if (islower(char_) && isalpha(char_)) // lowercase letter
                    {
                      // printf("%c", char_);
                      int nb_letters_left = 'Z' - (char_ - 32);
                      int rest = how_many - nb_letters_left;

                      if (rest < 0) // 25 letters left for a key moving of 3
                          {
                            printf("%c", (char_ + how_many));
                          }
                        else if (rest > 0)
                          {
                            // printf("rest is %i\n", rest);
                            printf("%c", (97 + (rest - 1))); // -(-1) = +1 & a = 97
                          }
                    }
                  else
                  {
                    printf("%c", char_);
                  }

                }
                printf("\n");
            }
      }
    else
      {
          printf("Usage: %s key\n", argv[0]);
          return 1;
      }
}

// Text: "A", key = 3;
// how_many = key%26;
// 65 + (32) + key%26 --> (A + 32) + 3%26 = a + how_many

// new_letter = A + 32
// nb_letters_left = Z - new_letter = 122 - 97 = 25 letters left
// --> 3 < 25:
// --> a + key%26 = 97 + 3 = 100 = "d"

// ------------

// Text: "XAXA", key = 3;
// A --> "d" --> "D";
// how_many = key%26;
// nb_letters_left = Z - (t + 32) --> 122 - (88 + 32) = 2;
// but: key = 3 => X --> a --> A
