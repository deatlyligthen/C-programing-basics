#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{

  // gathering sources picking the array length and kind:
  int lengthChoice;
  char playerChoice;
  int ctr;

  // introducing the program
  printf("\n\n------- Insertion Array Sorting -------\n\n");
  printf("Hello and welcome to the IAS, pick a length for the array and the array kind\n");
  printf("Random computer generated array or personal array");
  printf("\nFirst let's start with the length of the array\nHow long would you like the array to be?");

  // forces the user to only enter the valid options:
  do
  {
    printf("\nPlease allow up to 100 elements and at least 2 elemets\n");
    scanf(" %d", &lengthChoice);
  } while (lengthChoice > 100 || lengthChoice < 2);

  int testArray[lengthChoice];

  printf("Great now let's pick the array type");
  do
  {
    printf("\nEnter as follows:\n'R' - random computer generated array\n'P' - personal array\n");
    scanf(" %c", &playerChoice);
    playerChoice = toupper(playerChoice);
  } while (!(playerChoice == 'P' || playerChoice == 'R'));

  if (playerChoice == 'R')
  {
    time_t t;
    printf("Random, great choice, I see you like to keep it exciting\nnever let them know your next step huh?\n");
    printf("\n\n*-*-*-*-*-*- Filling the array *-*-*-*-*-*-\n\n");
    // makes the number truly random
    srand(time(&t));

    // filling the array
    for (ctr = 0; ctr < lengthChoice; ctr++)
    {
      testArray[ctr] = (rand() % 1000) + 1;
    }
  }
  else
  {
    printf("\nPersonal,interesting choice ,I see you like to keep it personal, maybe you think you can trick the system??\n");
    printf("\nwell fine then, Enter the array numbers");
    for (ctr = 0; ctr < lengthChoice; ctr++)
    {
      printf("\nenter the #%d element: ", ctr + 1);
      scanf(" %d", &testArray[ctr]);
    }
  }

  // printing the unsorted array
  printf("\n\nthe unsorted array: ");
  for (ctr = 0; ctr < lengthChoice; ctr++)
  {
    printf(" %d ", testArray[ctr]);
  }

  // sorting the array using insertion sorting algorithm:
  printf("\n\n\n*-*-*-*-*-*- Sorting the array *-*-*-*-*-*-\n\n");
  for (int arrayIndex = 1; arrayIndex < lengthChoice; arrayIndex++)
  {
    int numberCheck = arrayIndex;

    // while loop running and swapping the number as long as:
    // 1.) we are not at the end of our array
    // 2.) the number we check is smaller then the number to his left
    while (numberCheck > 0 && testArray[numberCheck] < testArray[numberCheck - 1])
    {
      // swap the places:

      int temp;
      temp = testArray[numberCheck];
      testArray[numberCheck] = testArray[numberCheck - 1];
      testArray[numberCheck - 1] = temp;

      // move the next element
      numberCheck--;
    }
  }
  // printing the sorted array:

  printf("\nthe sorted array is now: ");
  for (ctr = 0; ctr < lengthChoice; ctr++)
  {
    printf(" %d ", testArray[ctr]);
  }
  printf("\n\n");
  return 0;
}
