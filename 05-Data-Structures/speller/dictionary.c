// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

// added libraries
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

char *DICT = "/Users/marinelegall/code/CS50/05-Data-Structures/speller/dictionaries/large";

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

bool compare_two_words(const char *word, const char *poss_word);
int length_bucket(int bucket);
unsigned int hash(const char *word);
bool load(const char *DICT);
unsigned int size(void);

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

bool compare_two_words(const char *word, const char *poss_word) // OK
{
    // 1) in which bucket would the world be?

    if (strcmp(poss_word, word)==0)
    {
      printf("True\n");
      return true;
    }
    return false;
}

int length_bucket(int bucket) // OKKK
{
  node *myword = table[bucket];
  int length = 0;
  if (table[bucket] != NULL)
  {
    length = 1;
    while (myword->next != NULL)
    {
      // printf("%s\n", myword->word);
      length += 1;
      myword = myword->next;
    }

    // if (table[bucket]->next == NULL)
    // {
    //   while (myword->next != NULL)
    //   {
    //       myword = myword->next;
    //       length += 1;
    //   }
    // }
    printf("length bucket done.\n");
    return length;
  }
  else
  {
    return -1;
  }
}

// Returns true if word is in dictionary, else false
// bool check(const char *word) // OK
// {
//     // 1) in which bucket would the world be?
//     int possible_bucket = hash(word);
//     node *poss_word = table[possible_bucket];

//     int LENGTH_BUCKET = length_bucket(possible_bucket);

//     // 2) compare 2 words
//     if (compare_two_words(word, poss_word->word)==1)
//     {
//       return true;
//     }
//     else
//     {
//       int iterations = 0;
//       for (int i = 0; i < LENGTH_BUCKET; i++)
//       {
//           poss_word = poss_word->next;
//           if (compare_two_words(word, poss_word->word)==1)
//           {
//             return true;
//           }
//       }
//       // if the word is in the list, it breaks out of the loop, and then we compare the strings to make sure
//       // otherwise, if even the last word in the correct bucket could be the word, we compare them
//       if (strcmp(poss_word->word, word) == 0)
//       {
//         return true;
//       }
//       else // otherwise, the word is not in the dict
//       {
//         printf("ok??\n");
//         return false;
//       }

//       printf("false??\n");
//       return false;
//     }
// }

// Hashes word to a number
unsigned int hash(const char *word) // OK FOR NOW
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *DICT) // OKKKKK
{
    // 1. open dictionary file
    printf("Trying to load file: %s\n", DICT);
    FILE *file = fopen(DICT, "r");

    // 2. read strings from file one at a time
    if (file != NULL)
    {
        // if I put ```char buffer[N];``` I'm overflowing the buffer when a word is longer than 25 characters — leading to undefined behavior and a segmentation fault with large dictionaries.
        // bc this line is actually about how much space I'm allocating to read a word.
        char buffer[LENGTH + 1]; // This ensures my buffer can safely hold the longest word + null terminator.
        int number_of_words = 0;

        while (fscanf(file, "%s", buffer) != -1)
        {
            // 3. create a new node for each word
            // printf("buffer %s\n", buffer);

            node *n = malloc(sizeof(node));
            if (n != NULL)
            {
                number_of_words += 1;
                strcpy(n->word, buffer); // copy string from source to destination
                n->next = NULL;

                // 4. hash word to obtain a hash value
                int num = hash(buffer);
                node *myword = table[num];
                // printf("num hased is: %i\n\n", num);

                // 5. insert node into hash table at that location
                if (table[num] == NULL)
                {
                  table[num] = n;
                }
                else
                {
                  myword = table[num];
                  while (myword->next != NULL)
                  {
                      // printf("WHILE LOOP LOAD: %s\n", myword->word);
                      myword = myword->next;
                  }
                  // printf("%s\n", myword->word);
                  myword->next = n;
                }
            }
            if (n == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                return false;
            }
        }
        fclose(file);
        // printf("\nNumber of words: %p\n", &number_of_words);
        printf("Number of words: %i\n", number_of_words);
        // return true;
    }
    else
    {
      return false;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)// OK
{
    // TODO
    printf("enter here at size\n");
    int total_nb = 0;
    for (int i = 0; i < N; i++)
    {

      int length = length_bucket(i);
      if (length != -1)
      {
          // printf("LENGTH: %i\n", length);
          total_nb += length;
      }
    }

    return total_nb;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int bucket = 0;

    for (int i = 0; i < N; i++)
    {
      node *next_p = table[i];
      int LENGTH_BUCKET = 0;
      for (int k = 0; k < LENGTH_BUCKET; k++)
      {
        for (int j = 0; j < LENGTH_BUCKET-k; j++)
        {
          next_p = next_p->next; // gets me the last one
          // next_p->next= next_p;
        }
        free(next_p);
      }
    }
    return false;
}

bool check(const char *word) // OK
{
    // 1) in which bucket would the world be?
    int possible_bucket = hash(word);
    node *poss_word = table[possible_bucket];

    int LENGTH_BUCKET = length_bucket(possible_bucket);

    // 2) compare 2 words
    if (compare_two_words(word, poss_word->word)==1)
    {
      return true;
    }
    else
    {
      int iterations = 0;
      for (int i = 0; i < LENGTH_BUCKET-1; i++) // -1 bc I already compared with the 1st one
      {
          poss_word = poss_word->next;
          if (poss_word == NULL)
          {
            return false;
          }
          else if (compare_two_words(word, poss_word->word)==1)
          {
            return true;
          }
          else
          {
            printf("dict: %s - compare: %s\n", word, poss_word->word);
          }

          iterations += 1;
          // break; --> cannot find from 3rd word onwards but no error
      }
      printf("for-loop over\n");
      // if the word is in the list, it breaks out of the loop, and then we compare the strings to make sure
      // otherwise, if even the last word in the correct bucket could be the word, we compare them
      // if (strcmp(poss_word->word, word) == 0)
      // {
      //   return true;
      // }
      // else // otherwise, the word is not in the dict
      // {
      //   printf("false\n");
      //   return false;
      // }

      printf("false, not inside.\n");
      return false;
    }
}


int main(void)
{
    if (load(DICT)==1)
    {
      printf("Loaded.\n");
    }
    else
    {
      printf("Loading failed.\n");
    }

    // printf("\nbefore size\n");
    // int total_words = size();
    // printf("\nthere are %i words in this dict\n", total_words);
    // // // int bucket = hash("zz");
    // // // printf("int %i\n", hello);
    // // // printf("length %i\n", length_bucket(2));
    // // // printf("length %i\n", length_bucket(11));
    // // printf("length of Z: %i\n", length_bucket(25)); // segmentation fault
    // // printf("%s\n", table[3]->word);
    // // printf("\n");
    // // printf("%s\n", table[2]->word);
    // // printf("%s\n", table[2]->next->word);
    // // printf("%s\n", table[2]->next->next->word);

    // // compare_two_words("marin", "marin"); // OK

    // bool true_false = check("zoro");
    // printf("\n1 is true, 0 is false? %i\n", true_false); // 1 is true, 0 is false
    // unload();

}
