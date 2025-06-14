// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

// added libraries
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

bool compare_two_words(const char *word, const char *poss_word);
int length_bucket(int bucket);
unsigned int hash(const char *word);
bool load(const char *dictionary);
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
  int length = 1;
  if (table[bucket] != NULL)
  {
    while (myword->next != NULL)
    {
      printf("%s\n", myword->word);
      length += 1;
      myword = myword->next;
    }

    if (table[bucket]->next == NULL)
    {
      while (myword->next != NULL)
      {
          myword = myword->next;
          length += 1;
      }
    }
    return length;
  }
  else
  {
    return -1;
  }


}

// Returns true if word is in dictionary, else false
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
      for (int i = 0; i < LENGTH_BUCKET; i++)
      {
          poss_word = poss_word->next;
          if (compare_two_words(word, poss_word->word)==1)
          {
            return true;
          }
      }
      // if the word is in the list, it breaks out of the loop, and then we compare the strings to make sure
      // otherwise, if even the last word in the correct bucket could be the word, we compare them
      if (strcmp(poss_word->word, word) == 0)
      {
        return true;
      }
      else // otherwise, the word is not in the dict
      {
        printf("ok??\n");
        return false;
      }

      printf("false??\n");
      return false;
    }
}

// Hashes word to a number
unsigned int hash(const char *word) // OK FOR NOW
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) // OKKKKK
{
    // 1. open dictionary file
    FILE *file = fopen(dictionary, "r");

    // 2. read strings from file one at a time
    if (file != NULL)
    {
        char buffer[N];
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
        }
        fclose(file);
        // printf("\nNumber of words: %p\n", &number_of_words);
        printf("Number of words: %i\n", number_of_words);
        return true;
    }
    else
    {
      return false;
    }
// return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)// OK
{
    // TODO
    char *dictionary = "/Users/marinelegall/code/CS50/05-Data-Structures/speller/dictionaries/small";
    int total_nb = 0;
    for (int i = 0; i < N; i++)
    {

      int length = length_bucket(i);
      if (length != -1)
      {
          printf("LENGTH: %i\n", length);
          total_nb += length;
      }
    }

    return total_nb;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}


int main(void)
{
    char *dictionary = "/Users/marinelegall/code/CS50/05-Data-Structures/speller/dictionaries/small";
    load(dictionary);
    int total_words = size();
    printf("\nthere are %i words in this dict\n", total_words);
    // // int bucket = hash("zz");
    // // printf("int %i\n", hello);
    // // printf("length %i\n", length_bucket(2));
    // // printf("length %i\n", length_bucket(11));
    // printf("length of Z: %i\n", length_bucket(25)); // segmentation fault
    // printf("%s\n", table[3]->word);
    // printf("\n");
    // printf("%s\n", table[2]->word);
    // printf("%s\n", table[2]->next->word);
    // printf("%s\n", table[2]->next->next->word);

    // compare_two_words("marin", "marin"); // OK

    bool true_false = check("zz");
    printf("\n1 is true, 0 is false? %i\n", true_false); // 1 is true, 0 is false

}
