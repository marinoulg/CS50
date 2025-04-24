#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int avg_nb_letters(string text);
int sums(string text);
int sum_per_word(int start_index, string text);
float average(int length, int array[]);


int main(void)
{
  // Coleman-Liau
  // string text = get_string("Provide a text: ");
  string text = ("two fishes go swimming in the lake");
  int length = strlen(text);
  int array[length];
  int new_idx = 0;

  // int sum = avg_nb_letters(text);
  // printf("The final sum is %i", sum);
  // printf("\n\n%c%c%c\n", text[0], text[1], text[2]);
  // float avg = sums(text);
  // printf("avg is %f\n", avg);
  // int idx = 0;
  // for (int i = 0; i < length; i++)
  // {
  //     if (i == idx)
  //     {
  //       int idx = sum_per_word(i, text);
  //       printf("index: %i\n", idx);
  //       i = idx+1;
  //     }
  //     else if (i == length)
  //     {
  //       printf("i = n");
  //     }
  // }


  // Test sentence : two fishes go swimmming.
  // int pos = -1;
  // int idx = -1;
  // int new_idx = idx + 1;
  // pos = sum_per_word(new_idx, text) - (pos+1);
  // printf("index: %i\n", pos); // i = 3
  // array[0] = pos;

  // new_idx = pos+1;
  // pos = sum_per_word(new_idx, text) - (pos+1);
  // printf("index2: %i\n", pos) ; // i2 = 6
  // array[1] = pos - (pos+1);

  // new_idx = pos+1;
  // pos = sum_per_word(new_idx, text) - (pos+1);
  // printf("index3: %i\n", pos) ; // i2 = 6
  // array[2] = pos - (pos+1);

  int i = sum_per_word(0, text);
  printf("index: %i\n", i); // i = 3
  array[0] = i;

  int i2 = sum_per_word(i+1, text);
  printf("index2: %i\n", i2 - (i+1)); // i2 = 6
  array[1] = i2 - (i+1);

  int i3 = sum_per_word(i2 + 1, text);
  printf("index3: %i\n", i3 - (i2 + 1)); // i = 2
  array[2] = i3 - (i2 + 1);

  int i4 = sum_per_word(i3+1, text);
  printf("index4: %i\n", i4 - (i3 +1)); // i2 = 9
  array[3] = i4 - (i3 +1);

  int i5 = sum_per_word(i4+1, text);
  printf("index4: %i\n", i5 - (i4 +1));
  array[4] = i5 - (i4 +1);

  int i6 = sum_per_word(i5+1, text);
  printf("index4: %i\n", i6 - (i5 +1));
  array[5] = i6 - (i5 +1);

  int i7 = sum_per_word(i6+1, text);
  printf("index4: %i\n", i7);
  array[6] = i7;
  // si c'est le dernier, on ne soustrait pas !

  // // int sum = (array[0] + array[1] + array[2] + array[3] + array[4] + array[5] + array[6]);
  // // float avg = sum / (float) 7;
  // float avg = average(7, array);
  // printf("Average number of letters per word is: %f\n", avg);











  // // Output
  // int x = 10; // to modify

  // if (x > 15)
  // {
  //   printf("Grade +16");
  // }
  // else if (x < 1)
  // {
  //   printf("Before Grade 1");
  // }
  // else
  // {
  //   printf("Grade %i", x);
  // }
}


int avg_nb_letters_per_100(string text)
{
  int sum = 0;
  for (int i = 0; i < 100; i++)
  {
      if (strlen(text) < 100)
      {
        char char_ = tolower(text[i]);
        if (char_ == 'a' || char_ == 'b' || char_ == 'c' || char_ == 'd' ||\
            char_ == 'e' || char_ == 'f' || char_ == 'g' || char_ == 'h' ||\
            char_ == 'i' || char_ == 'j' || char_ == 'k' || char_ == 'l' ||\
            char_ == 'm' || char_ == 'n' || char_ == 'o' || char_ == 'p' ||\
            char_ == 'q' || char_ == 'r' || char_ == 's' || char_ == 't' ||\
            char_ == 'u' || char_ == 'v' || char_ == 'w' || char_ == 'x' ||\
            char_ == 'y' || char_ == 'z')
            {
              sum += 1;
              printf("Sum: %i (%c)\n", sum, char_);
            }
      else
        {
          printf("Nothing added. New sum: %i (%c)\n", sum, char_);
          sum += 0;
        }
      }
  }
  return sum;
}

int avg_nb_letters(string text)
{
    int length = (strlen(text));
    int sum = 0;
    if (length < 100)
    {
      int avg = avg_nb_letters_per_100(text);
      return avg;
    }
    else
    {
      // do
      // {

      // }
      // while ..;
    }
    return sum;
  }

// int avg_nb_sentences(string text)
// {

// }

// Average function
float average(int length, int array[])
{
	// Calculate average
	int sum = 0; // initializing value
	for (int i = 0; i < length; i++)
	{
		sum += array[i];
	}
	return sum / (float) length;
}


int sums(string text)
{
  int n = strlen(text);
  int array[n];
  int sum = 0;
  float avg = 0;
	for (int i = 0; i < n; i++)
	{
		char char_ = tolower(text[i]);
    if (char_ == 'a' || char_ == 'b' || char_ == 'c' || char_ == 'd' ||\
      char_ == 'e' || char_ == 'f' || char_ == 'g' || char_ == 'h' ||\
      char_ == 'i' || char_ == 'j' || char_ == 'k' || char_ == 'l' ||\
      char_ == 'm' || char_ == 'n' || char_ == 'o' || char_ == 'p' ||\
      char_ == 'q' || char_ == 'r' || char_ == 's' || char_ == 't' ||\
      char_ == 'u' || char_ == 'v' || char_ == 'w' || char_ == 'x' ||\
      char_ == 'y' || char_ == 'z')
      {
        sum += 1;
        printf("%i %c\n", sum, char_);
      }
    else
    {
      array[i] = sum;
      sum = 0;
    }


     // create an array whose index is the number of letters per words
      // printf("%i %c\n",array[i], char_);
	}
  if (n < 101)
  {
    avg = average(n, array);
  }
  // else
  // {
  //   avg = average(100, array);
  // }
  printf("array 0: %i, array 1: %i\n", array[0], array[2]);
  return avg;
}

int sum_per_word(int start_index, string text)
{
  int n = strlen(text);
  int array[n];
  int sum = 0;
  float avg = 0;
	for (int i = start_index; i < n; i++)
	{
		char char_ = tolower(text[i]);
    if (char_ == 'a' || char_ == 'b' || char_ == 'c' || char_ == 'd' ||\
      char_ == 'e' || char_ == 'f' || char_ == 'g' || char_ == 'h' ||\
      char_ == 'i' || char_ == 'j' || char_ == 'k' || char_ == 'l' ||\
      char_ == 'm' || char_ == 'n' || char_ == 'o' || char_ == 'p' ||\
      char_ == 'q' || char_ == 'r' || char_ == 's' || char_ == 't' ||\
      char_ == 'u' || char_ == 'v' || char_ == 'w' || char_ == 'x' ||\
      char_ == 'y' || char_ == 'z')
      {
        sum += 1;
        printf("%i %c\n", sum, char_);
      }
    else
    {
      return i;
    }
  }
  return sum;
}
