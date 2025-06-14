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

// TODO: Choose number of buckets in hash table
// You will likely want to increase this depending on your own implementation of hash.
const unsigned int N = 26;

// Hash table
node *table[N];
// = an array of node pointers
// = an array where every element in the array is a pointer to a node.

bool compare_two_words(const char *word, const char *poss_word) // OK ?
{
    // 1) in which bucket would the world be?

    if (strcmp(poss_word, word)==0)
    {
      return true;
    }
    return false;
}

int length_bucket(int bucket) // segmentation error/fault
{
  node *myword = table[bucket];
  int length = 0;
  if (table[bucket] != NULL)
  {
    do
    {
      printf("%s\n", myword->word);
      length += 1;
      myword = myword->next;

    } while (myword->next != NULL);
    printf("\n");
    return length;
  }
  else // if (table[bucket] == NULL)
  // {
  //   table[bucket] = myword;
  // }

  {
    return -1;
  }


}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // 1) in which bucket would the world be?
    int possible_bucket = hash(word);
    node *poss_word = table[possible_bucket];

    int LENGTH_BUCKET = length_bucket(possible_bucket);

    // 2) compare 2 words
    if (compare_two_words(word, poss_word->word)==1)
    {
      // printf("yes true\n");
      return true;
    }
    else
    {
      int iterations = 0;
      // if (compare_two_words(word, poss_word->word)!=1)
      for (int i = 0; i<LENGTH_BUCKET; i++)
      {
          // do
          // {

          poss_word = poss_word->next;
          //   iterations += 1;
          // }
          // while compare_two_words(word, poss_word->word);
          if (compare_two_words(word, poss_word->word)==1)
          {
            return true;
          }
          break;
      }
      // else
      // {
      //   printf("ABORT MISSION\n");
      //   return false;
      // }



      // if (iterations > 12)
      // {
      //   printf("abort\n");
      // }

      // break;
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
            // printf("%s\n", buffer);

            node *n = malloc(sizeof(node));
            if (n != NULL)
            {
                number_of_words += 1;
                strcpy(n->word, buffer); // copy string from source to destination
                n->next = NULL;

                // 4. hash word to obtain a hash value
                int num = hash(buffer);
                // printf("num hased is: %i\n\n", num);

                // 5. insert node into hash table at that location
                if (table[num] == NULL)
                {
                  table[num] = n;
                }
                // else if (table[num]->next == NULL)
                // {
                //   table[num]->next = n;
                //   printf("ENTER HERE\n");
                //   printf("WORD IS %s\n", table[num]->word);
                //   // printf("WORD IS %s\n", table[num]->next->word);
                //   // printf("pointerrrr IS %p\n", table[num]->next->word);
                //   // printf("pointerrrr IS %p\n", (table[num]->next->next));
                //   // int nb_iterations = 0;
                //   // while (table[num] != NULL)
                //   // {
                //   //     // table[num]->next;
                //   //     nb_iterations += 1;
                //   //     printf("BEFORE: %p\n", table[num]);
                //   //     table[num] = table[num]->next;
                //   //     printf("AFTER: %p\n", table[num]);
                //   //     printf("nb iterations: %i\n", nb_iterations);
                //   //     // node *my_pointer = table[num]->next;
                //   // }
                //   // printf("my pointer: %p \n", my_pointer);
                //   // table[num].next_one = n;
                // }
                else
                {
                  node *myword = table[num];
                  while (myword->next != NULL)
                  {

                      printf("WHILE LOOP LOAD: %s\n", myword->word);
                      myword = myword->next;

                  }
                  // printf("%s\n", myword->word);
                  myword = n;
                }


                // else if (table[num]->next->next == NULL)
                // {
                //   table[num]->next->next = n;
                // }
                // else if (table[num]->next->next->next == NULL)
                // {
                //   table[num]->next->next->next = n;
                // }
                // else if (table[num]->next->next->next->next == NULL)
                // {
                //   table[num]->next->next->next->next = n;
                // }
            }
        }
        fclose(file);
        // printf("\nNumber of words: %p\n", &number_of_words);
        printf("Number of words: %i\n", number_of_words);

        // printf("string %s\n", table[2]->word);
        // printf("string %s\n", table[2]->next->word);
        // printf("string %s\n", table[2]->next->next->word);
        // printf("string %s\n", table[11]->word);
        // printf("string %s\n", table[12]->word);
        // printf("string %s\n", table[13]->word);
        // printf("string %s\n", table[25]->word);
        // printf("string %s\n", table[25]->next->word);
        // printf("string %s\n", table[25]->next->next->word);
        // printf("string %s\n", table[25]->next->next->next->word);
        // printf("string %s\n", table[25]->next->next->next->next->word);
        return true;
    }
    else
    {
      return false;
    }
// return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    char *dictionary = "/Users/marinelegall/code/CS50/05-Data-Structures/speller/dictionaries/small";
    printf("ok cool\n");
    // if (load(dictionary) == true)
    // {
    //   printf("ok\n");
    //   return 0;
    // }
    // else
    // {
    //   return -1;
    // }

    int total_nb = 0;
    for (int i = 0; i < N; i++)
    {
      // if (table[i]->next != NULL)
      // {
      int length = length_bucket(i);
      if (length != -1)
      {
          printf("LENGTH: %i\n", length);
          total_nb += length;
      }

      // }
      // else
      // {
      //   i += 1;
      //   printf("here %i is \n", i);

      // }

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
    // int total_words = size();
    // printf("\nthere are %i words in this dict\n", total_words);
    // // int bucket = hash("zz");
    // // printf("int %i\n", hello);
    // // printf("length %i\n", length_bucket(2));
    // // printf("length %i\n", length_bucket(11));
    printf("length of C: %i\n", length_bucket(2)); // segmentation fault
    // printf("%s\n", table[3]->word);
    // printf("%p\n", table[3]->next);

    // bool true_false = check("zzo");
    // printf("\n1 is true, 0 is false? %i\n", true_false); // 1 is true, 0 is false

}
