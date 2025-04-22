# Mario (part 1)

Toward the end of World 1-1 in Nintendo’s Super Mario Bros., Mario must ascend right-aligned pyramid of bricks, as in the below.

screenshot of Mario jumping up a right-aligned pyramid

In a file called ```mario.c``` in a folder called ```mario-less```, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:
```

       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```

But prompt the user for an int for the pyramid’s actual height, so that the program can also output shorter pyramids like the below:
```
  #
 ##
###
```
Re-prompt the user, again and again as needed, if their input is not greater than 0 or not an int altogether.

## How to Test
Does your code work as prescribed when you input:

- -1 or other negative numbers?
- 0?
- 1 or other positive numbers?
- letters or words?
- no input at all, when you only hit Enter?

## Correctness
In your terminal, execute the below to check your work’s correctness.
```
check50 cs50/problems/2025/x/mario/less
```
## Style
Execute the below to evaluate the style of your code using ```style50```.
```
style50 mario.c
```
## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/problems/2025/x/mario/less
```
