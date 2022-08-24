#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
  // variables for the sorting and filling the array:
  int outer, inner, temp, ctr;
  char userChoice;
  int nums[10];
  time_t t;

  // introducing the array to the user:
  printf("\n\n-------Bubble array sorting program-------\n\n");
  printf("what array would you like to sort?\n");
  printf("array of your choice or a random computer generated array?");
  do /* forces the user to enter only R/I/r/i */
  {
    printf("\nplease enter as follows:\n");
    printf("'R' - random computer generated array\n'P' - personal array\n");
    scanf(" %c", &userChoice);
    userChoice = toupper(userChoice);
  } while (!(userChoice == 'R' || userChoice == 'P'));

  if (userChoice == 'R')
  {
    printf("Random, great choice, I see you like to keep it exciting\nnever let them know your next step huh?\n");
    printf("\n\n*-*-*-*-*-*- filling the array *-*-*-*-*-*-\n\n");
    // makes the number truly random
    srand(time(&t));

    // filling the array
    for (ctr = 0; ctr < 10; ctr++)
    {
      nums[ctr] = (rand() % 100) + 1;
    }
  }
  else
  {
    printf("\nPersonal,interesting choice ,I see you like to keep it personal, maybe you think you can trick the system??\n");
    printf("\nwell fine then, Enter the array numbers");
    for (ctr = 0; ctr < 10; ctr++)
    {
      printf("\nenter the #%d element: ", ctr + 1);
      scanf(" %d", &nums[ctr]);
    }
  }
  // printing the array
  printf("\nthe unsorted array is: ");
  for (ctr = 0; ctr < 10; ctr++)
  {
    printf(" %d ", nums[ctr]);
  }

  // the sorting process:
  printf("\n\n\n*-*-*-*-*-*- sorting the array *-*-*-*-*-*-\n\n");
  // running over the array starting from the first element
  for (outer = 0; outer < 9; outer++)
  {
    for (inner = outer; inner < 10; inner++) /* constantly compering one number to the whole list */
    {
      if (nums[inner] < nums[outer]) /* if we found a number that is smaller to the number we compere to, we swich*/
      {
        temp = nums[outer];
        nums[outer] = nums[inner];
        nums[inner] = temp;
      }
    }
  }

  printf("\nthe sorted array is: ");
  for (ctr = 0; ctr < 10; ctr++)
  {
    printf(" %d ", nums[ctr]);
  }
  printf("\n\n\n");
  return 0;
}
