# Cash

Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents). You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy. When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!). In a file called ```cash.c``` in a folder called ```cash```, implement a program in C that prints the minimum coins needed to make the given amount of change, in cents, as in the below:
```
Change owed: 25
1
````

But prompt the user for an ```int``` greater than 0, so that the program works for any amount of change:
```
Change owed: 70
4
```

Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an ```int``` at all!).

## Greedy Algorithms
Fortunately, computer science has given cashiers everywhere ways to minimize numbers of coins due: greedy algorithms.

According to the National Institute of Standards and Technology (NIST), a greedy algorithm is one “that always takes the best immediate, or local, solution while finding an answer. Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, but may find less-than-optimal solutions for some instances of other problems.”

What’s all that mean? Well, suppose that a cashier owes a customer some change and in that cashier’s drawer are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). The problem to be solved is to decide which coins and how many of each to hand to the customer. Think of a “greedy” cashier as one who wants to take the biggest bite out of this problem as possible with each coin they take out of the drawer. For instance, if some customer is owed 41¢, the biggest first (i.e., best immediate, or local) bite that can be taken is 25¢. (That bite is “best” inasmuch as it gets us closer to 0¢ faster than any other coin would.) Note that a bite of this size would whittle what was a 41¢ problem down to a 16¢ problem, since 41 - 25 = 16. That is, the remainder is a similar but smaller problem. Needless to say, another 25¢ bite would be too big (assuming the cashier prefers not to lose money), and so our greedy cashier would move on to a bite of size 10¢, leaving him or her with a 6¢ problem. At that point, greed calls for one 5¢ bite followed by one 1¢ bite, at which point the problem is solved. The customer receives one quarter, one dime, one nickel, and one penny: four coins in total.

It turns out that this greedy approach (i.e., algorithm) is not only locally optimal but also globally so for America’s currency (and also the European Union’s). That is, so long as a cashier has enough of each coin, this largest-to-smallest approach will yield the fewest coins possible. How few? Well, you tell us!

## How to Test
For this program, try testing your code manually. It’s good practice:

- If you input ```-1```, does your program prompt you again?
- If you input ```0```, does your program output ```0```?
- If you input ```1```, does your program output ```1``` (i.e., one penny)?
- If you input ```4```, does your program output ```4``` (i.e., four pennies)?
- If you input ```5```, does your program output ```1``` (i.e., one nickel)?
- If you input ```24```, does your program output ```6``` (i.e., two dimes and four pennies)?
- If you input ```25```, does your program output ```1``` (i.e., one quarter)?
- If you input ```26```, does your program output ```2``` (i.e., one quarter and one penny)?
- If you input ```99```, does your program output ```9``` (i.e., three quarters, two dimes, and four pennies)?

## Correctness
In your terminal, execute the below to check your work’s correctness.
```
check50 cs50/problems/2025/x/cash
```
## Style
Execute the below to evaluate the style of your code using ```style50```.
```
style50 cash.c
```
## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/problems/2025/x/cash
```
