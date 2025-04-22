# Plurality

Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

For this problem, you’ll implement a program that runs a plurality election, per the below.

For this problem, you’ll extend the functionality of “distribution code” provided to you by CS50’s staff.

## How to Test
Be sure to test your code to make sure it handles…

- An election with any number of candidate (up to the ```MAX``` of ```9```)
- Voting for a candidate by name
- Invalid votes for candidates who are not on the ballot
- Printing the winner of the election if there is only one
- Printing the winner of the election if there are multiple winners

## Correctness
```
check50 cs50/problems/2025/x/plurality
````

## Style
```
style50 plurality.c
```

## How to Submit
```
submit50 cs50/problems/2025/x/plurality
```
