#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int nb_letters(string text, int length);
int nb_words(string text, int length);
int nb_sentences(string text, int length);
float avg_nb_letters(int nb_letters, int nb_words);
float avg_nb_sentences(int nb_sentences, int nb_words);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");
    int length = strlen(text);

    // Count number of letters
    int count_letters = nb_letters(text, length);

    // Count number of words (separated by spaces)
    int count_words = nb_words(text, length);

    // Count number of sentences (separated by ".", "?", "!")
    int count_sentences = nb_sentences(text, length);

    // Coleman-Liau index
    float L = avg_nb_letters(count_letters, count_words);
    float S = avg_nb_sentences(count_sentences, count_words);

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int nb_letters(string text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        char character = text[i];
        if (isalpha(character))
        {
            count += 1;
        }
    }
    return count;
}

int nb_words(string text, int length)
{
    int count = 1;
    for (int i = 0; i < length; i++)
    {
        char c = text[i];
        if (c == 32) // 32 is the ASCII character for the " " (space)
        {
            count += 1;
        }
    }
    return count;
}

int nb_sentences(string text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        char punct = text[i];
        if (punct == 33 || punct == 46 || punct == 63) // 33 = !, 46 = ., 63 = ?
        {
            count += 1;
        }
    }
    return count;
}

float avg_nb_letters(int nb_letters, int nb_words)
{
    return (float) nb_letters / nb_words * 100;
}

float avg_nb_sentences(int nb_sentences, int nb_words)
{
    return (float) nb_sentences / nb_words * 100;
}
