from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for j in range(height):
    for i in range(height-j-1):
        print(" ", end="")
    print("#"*(j+1))
