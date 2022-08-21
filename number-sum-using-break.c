#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  // initiate variables
  int num;
  int total;

  // Loop always true (1)
  while (1)
  {
    // get a number from the user
    printf("Give me a number: ");
    scanf("%d", &num);
    // if the number is≤0 terminates Loop
    if (num <= 0)
    {
      break;
    }
    // where the operation of adding up the numbers is happening
    total = total + num;
  }
  printf("The sum of all these numbers are: %d\n", total);
  return 0;
}
