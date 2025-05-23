#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void bubble_sort(candidate candidates[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name) && strcmp(name, candidates[i].name) != 0)
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(name, candidates[i].name) == 0)
        {
            // printf("Nb of votes before: %i\n", candidates[i].votes);
            candidates[i].votes += 1;
            // printf("Nb of votes after: %i\n", candidates[i].votes);
            return true;
        }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    bubble_sort(candidates);

    if (candidates[0].votes > candidates[1].votes)
    {
        printf("%s\n", candidates[0].name);
        // printf("Winner is %s with %i votes\n", candidates[0].name, candidates[0].votes);
    }
    else
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].votes == candidates[0].votes)
            {
                printf("%s\n", candidates[i].name);
            }
            else
            {
                break;
            }
        }
    }
    return;
}

void bubble_sort(candidate candidates[])
{
    int switched = 0;
    for (int i = 0; i < (candidate_count - 1); i++)
    {
      // Bubble sort by descending order
      for (int i = 0; i < (candidate_count - 1); i++)
          {
            if (candidates[i].votes < candidates[i+1].votes)
            {
                candidate tmp_candidate = candidates[i];
                candidates[i] = candidates[i+1];
                candidates[i+1] = tmp_candidate;
                switched += 1;
                // printf("Candidates %s and %s switched\n", candidates[i+1].name, candidates[i].name);
            }
          }
      if (switched == 0)
      {
            break;
      }
      }
}
