#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  int num_multiplication;
  printf("\nEnter a number: ");
  scanf("%d", &num_multiplication);
  for (int number = 0; number <= 10; number++)
  {
    printf("%d * %d = %d\n", num_multiplication, number, num_multiplication * number);
  }
  return 0;
}
