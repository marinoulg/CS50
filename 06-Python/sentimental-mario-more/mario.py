from cs50 import get_int

# Equivalent of do-while loop
while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for j in range(height):
    # Dealing with how many spaces at the beginning
    for i in range(height-j-1):
        print(" ", end="")

    # Printing the actual bricks
    print("#"*(j+1), end="")
    print("  ", end="")
    print("#"*(j+1))
