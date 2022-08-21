#include <stdio.h>
#include <string.h>

int main()
{

  // gathering sources for sorting an array:
  int myArray[5];
  int count = 1;
  for (int arrayIndex = 0; arrayIndex < 5; arrayIndex++)
  {

    printf("\nEnter the #%d array element: ", count);
    scanf(" %d", &myArray[arrayIndex]);
    count++;
  }

  // calculate the last array index
  int arrayLength = ((sizeof(myArray)) / (sizeof(myArray[0])));

  // printing the unsorted array
  printf("\nthe array was: ");
  for (int i = 0; i < arrayLength; i++)
  {
    printf(" %d ", myArray[i]);
  }

  // sorting the array using insertion sorting algorithm:

  for (int index = 1; index < arrayLength; index++)
  {
    int numberCheck = index;
    while (numberCheck > 0 && myArray[numberCheck] < myArray[numberCheck - 1])
    {
      // swap the places:

      int temp;
      temp = myArray[numberCheck];
      myArray[numberCheck] = myArray[numberCheck - 1];
      myArray[numberCheck - 1] = temp;

      // move the next element
      numberCheck--;
    }
  }
  // printing the sorted array:

  printf("\nthe sorted array is now: ");
  for (int i = 0; i < arrayLength; i++)
  {
    printf(" %d ", myArray[i]);
  }

  return 0;
}
