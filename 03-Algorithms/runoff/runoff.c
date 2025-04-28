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
bool is_eliminated(string name);
void add_1_vote(int voter, int rank);
int recursive_find_min(int idx_min_candidate);
bool recursive_is_tie(int idx);

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
            else
            {
              vote(i,j,name);
              printf("Ballot %i voted for their %ist preference for %s\n", i,j, name);
            }

        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    printf("We hold a runoff\n");
    while (true)
    {
        // Calculate votes given remaining candidates
        printf("We tabulate votes\n");
        tabulate();

        // Check if election has been won
        printf("Does the election have a winner?\n");
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);
        printf("The minimum number of votes for 1 candidate is %i\n", min);
        printf("Is this election a tie? %i\n", tie);
        printf("\n");

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
        printf("The election is not a tie, and so we eliminate candidates\n");
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
          printf("Before, candidate %s had %i votes\n", candidates[i].name, candidates[i].votes);
          candidates[i].votes = 0;
          printf("After resetting votes, candidate %s had %i votes\n", candidates[i].name, candidates[i].votes);
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Example: the first voter's top preferred candidate (preferences[0][0]) is name (= Alice ?, // idx = 0)
    int idx = get_index_candidates(name);
    // for (int i = 0; i < candidate_count; i++)
    // {
    //   if (strcmp(candidates[i].name, name) == 0)
    //   {
    //     preferences[voter][rank] = i;
    //     return true;
    //   }
    // }

    if (idx != -1) // Meaning, if the vote is valid
    {
      preferences[voter][rank] = idx;
      return true;
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Update vote counts for all non-eliminated candidates.
    int rank = 0;
    for (int voter_idx = 0; voter_idx < voter_count; voter_idx++)
    {
          add_1_vote(voter_idx, rank);
          // rank starts at 0, but recursive function so if candidate whose rank is 0 is eliminated, rank += 1, aka it goes to candidate whose rank is 1 (and if eliminated, recursive again)
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int MAJORITY = ((int) voter_count/2) + 1; // that way, it truncates voter_count/2 if float
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= MAJORITY)
        {
          printf("%s\n", candidates[i].name);
          return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int j = 0;
    int idx_min_candidate = recursive_find_min(j);

    return candidates[idx_min_candidate].votes;
}

int recursive_find_min(int idx_min_candidate)
{
    // if idx_min_candidate reaches the last candidate, return it
    if (idx_min_candidate == candidate_count - 1)
    {
        return idx_min_candidate;
    }

    int current_idx = idx_min_candidate;
    int next_idx = recursive_find_min(idx_min_candidate + 1);

    // Compare current candidate and next candidate
    if (candidates[current_idx].eliminated)
    {
        return next_idx;
    }
    if (candidates[next_idx].eliminated)
    {
        return current_idx;
    }

    if (candidates[current_idx].votes <= candidates[next_idx].votes)
    {
        return current_idx;
    }
    else
    {
        return next_idx;
    }
}



// Return true if the election is tied between all the remaining candidates, false otherwise
bool is_tie(int min)
{
  int sum = 0; // How many candidates have the same number of votes, which is the least number of votes
  int total_possible = 0; // How many candidates are not (yet) eliminated
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].eliminated == false)
    {
        total_possible += 1;
        if (candidates[i].votes == min)
        {
          sum += 1;
        }
    }
  }
  if (sum == total_possible)
  {
    return true;
  }
  return false;
}



// Eliminate the candidate (or candidates) in last place, aka who has the minimum number of votes
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
      if (candidates[i].votes == min)
      {
        candidates[i].eliminated = true;
      }
    }
    return;
}



// Others
int get_index_candidates(string name)
{

  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(candidates[i].name, name) == 0)
      {
        // printf("idx is %i\n",i);
        return i;
      }
  }
  return -1;
}

bool is_eliminated(string name)
{
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].eliminated == true)
      {
          return true;
      }
  }
  return false;
}


void add_1_vote(int voter, int rank)
{
    // if rank is greater than candidate_count, return
    if (rank >= candidate_count)
    {
        return;
    }

    int candidate_idx = preferences[voter][rank];

    // If candidate is not eliminated, add one vote
    if (!candidates[candidate_idx].eliminated)
    {
        candidates[candidate_idx].votes += 1;
    }
    else // if candidate has indeed been eliminated, consider instead the next choice of the voter
    {
        rank += 1;
        add_1_vote(voter, rank);
    }
}
