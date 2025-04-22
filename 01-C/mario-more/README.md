# Mario (part 2)
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

screenshot of Mario jumping over adjacent pyramids

In a file called ```mario.c``` in a folder called ```mario-more```, implement a program in C that recreates that pyramid, using hashes (```#```) for bricks, as in the below:
```
   #  #
  ##  ##
 ###  ###
####  ####
```

And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive ```int``` between, say, 1 and 8, inclusive.

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

## How to Test Your Code
Does your code work as prescribed when you input

- ```-1``` (or other negative numbers)?
- ```0```?
- ```1``` through ````8```?
- ```9``` or other positive numbers?
- letters or words?
- no input at all, when you only hit Enter?

You can also execute the below to evaluate the correctness of your code using ```check50```. But be sure to compile and test it yourself as well!

## Correctness
In your terminal, execute the below to check your work’s correctness.
```
check50 cs50/problems/2025/x/mario/more
```
## Style
Execute the below to evaluate the style of your code using ```style50```.
```
style50 mario.c
```

## How to Submit
In your terminal, execute the below to submit your work.
```
submit50 cs50/problems/2025/x/mario/more
```
