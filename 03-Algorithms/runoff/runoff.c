#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int get_index_candidates(string name);
int count_preferences_for_one_rank(int rank, string name);
void bubble_sort(int last_place_candidates[]);
void initialize_votes();
void bubble_sort_candidates(candidate candidates[]);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

int get_index_candidates(string name)
{
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(name, candidates[i].name) == 0)
      {
          return i;
      }
  }
  return -1;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
      if (strcmp(name, candidates[i].name) == 0)
      {
          int idx = get_index_candidates(name);
          preferences[i][rank] = idx;
          return true;
      }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // int rank = 0;
    // int last_place_candidates[MAX_CANDIDATES]; // Array whose index is the number of votes a candidate received in the last place of the ballot
    // TODO
    // for (int i = 0; i < candidate_count; i++)
    // {
    //   // last_place_candidates[i] = count_preferences_for_one_candidate(rank, i);

    // }

    bubble_sort_candidates(candidates);
    if (candidates[0].votes < candidates[1].votes)
    {
      // eliminate candidates[0].name
      candidates[0].eliminated = true;
    }



    // if (last_place_candidates[0] < last_place_candidates[1])
    // {
    //   // eliminate candidate whose count_pref(rank, idx=?) equals last_place_candidates[0]
    // }


    return;
}

void bubble_sort_candidates(candidate candidates[])
{
    int switched = 0;
    for (int i = 0; i < (candidate_count - 1); i++)
    {
      // Bubble sort by ascending order
      for (int i = 0; i < (candidate_count - 1); i++)
          {
            if (candidates[i].votes > candidates[i+1].votes)
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


void initialize_votes()
{
  for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }
}

int count_preferences_for_one_rank(int rank, string name)
{
    int idx = get_index_candidates(name);
    initialize_votes();
    int count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (preferences[i][rank] == idx) // if 3 candidates, and "Alice" is candidate index 0, count the number of times she was place rank = 0 for example
        {
            count += 1;
            candidates[i].votes += 1;
        }
    }
    return count;
}

// void bubble_sort(int last_place_candidates[])
// {
//     int switched = 0;
//     for (int i = 0; i < (candidate_count - 1); i++)
//     {
//       // Bubble sort by descending order
//       for (int i = 0; i < (candidate_count - 1); i++)
//           {
//             if (last_place_candidates[i] < last_place_candidates[i+1])
//             {
//                 int tmp_candidate = last_place_candidates[i];
//                 last_place_candidates[i] = last_place_candidates[i+1];
//                 last_place_candidates[i+1] = tmp_candidate;
//                 switched += 1;
//                 // printf("Candidates %s and %s switched\n", candidates[i+1].name, candidates[i].name);
//             }
//           }
//       if (switched == 0)
//       {
//             break;
//       }
//     }
// }
