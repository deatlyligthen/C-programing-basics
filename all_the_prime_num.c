#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// prototype
int check_if_prime(int);

int main()
{
  /* gets a number from the user and sets the counting variable */

  int endNum;
  int countNum = 1;
  printf("Give me a number: ");
  scanf("%d", &endNum);

  if (endNum >= 0) /* making sure the number isn't 0 or negative */
  {

    /* counting whole numbers from 1 to the number the user picks */

    for (int startNum = 1; startNum <= endNum; startNum++)
    {

      if (check_if_prime(startNum) == 0) //  for every number, initiate the prime number checking program
      {
        continue; /* if the number isn't prime the program just carries on with no effect */
      }

      /* if the number is prime it prints the number itself and its order on the prime numbers (#2,#4)  */

      printf("#%d prime number: %d\n", countNum, startNum);
      countNum++;
    }
  }
  else
  {
    printf("Number have to be 0 or positive!!!\n"); /* only happens if the user put 0 or negative input */
  }
  printf("There are %d prime numbers \nuntil the number: %d\n", countNum - 1, endNum);
  return 0;
}

// The prime check program:
// this program works by taking every number and checking if it can be factor to other numbers besides itself and 1 without reminder
// if it can't find any other factors we know the number is a prime number
// the result is then returned to main().

int check_if_prime(int primeCheck)
{
  int countNum = 0;

  // checks every number from 2 until the number that we want to check if its a factor of the chosen number

  for (int divideNum = 2; divideNum < primeCheck && primeCheck % divideNum != 0; divideNum++)
  {
    countNum++;
  }
  if (countNum == primeCheck - 2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}