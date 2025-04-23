#include <cs50.h>
#include <stdio.h>

int main(void)
{

  string name = get_string("What's your name?\n");
  // Print the name prompted
  printf("hello, %s\n", name);
}
