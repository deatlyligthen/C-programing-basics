#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  int primeCheck;
  int countNum = 0;
  printf("Enter a number to check if it is a prime number or not: ");
  scanf("%d", &primeCheck);
  if (primeCheck <= 1)
  {
    printf("Number must me bigger then 1\n");
  }
  else
  {
    for (int divideNum = 2; divideNum < primeCheck && primeCheck % divideNum != 0; divideNum++)
    {
      countNum++;
    }
    if (countNum == primeCheck - 2)
    {
      printf("The number: %d is a prime number\n", primeCheck);
    }
    else
    {
      printf("The number %d isn't a prime number\n", primeCheck);
    }
  }
  return 0;
}
