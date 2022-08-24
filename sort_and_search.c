#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  // variables for searching the data
  int ctr;
  int searchNum;
  int found = 0;
  int check = 0;

  // data for the ID and the Balance:
  int coustId[10] = {123, 647, 346, 865, 243, 432, 658, 132, 776, 654};
  float coustBalance[10] = {0.00, 12.23, 54.87, 112.34, 54.0, 225.21, 142.0, 34.5, 123.3, 55.678};

  // if you want to see the unsorted data delate the comment symbol (//)

  // printf("\n\n------- Unsorted data -------\n\n");
  // for (ctr = 0; ctr < 10; ctr++)
  // {
  //   printf("\n\n#%d\nID: %d", ctr + 1, coustId[ctr]);
  //   printf("\nBalance: %.3f", coustBalance[ctr]);
  // }

  // sorting the data
  int tempId;
  float tempBalance;

  for (int arrayIndex = 1; arrayIndex < 10; arrayIndex++)
  {
    int numberCheck = arrayIndex;

    // while loop running and swapping the number as long as:
    // 1.) we are not at the end of our array
    // 2.) the number we check is smaller then the number to his left
    while (numberCheck > 0 && coustId[numberCheck] < coustId[numberCheck - 1])
    {
      // swap the places of ID:
      tempId = coustId[numberCheck];
      coustId[numberCheck] = coustId[numberCheck - 1];
      coustId[numberCheck - 1] = tempId;

      // swap the places of Balance:
      tempBalance = coustBalance[numberCheck];
      coustBalance[numberCheck] = coustBalance[numberCheck - 1];
      coustBalance[numberCheck - 1] = tempBalance;

      // move the next element
      numberCheck--;
    }
  }

  // if you want to see the sorted data delate the comment symbol (//)

  // printf("\n\n------- Sorted data -------\n\n");
  // for (ctr = 0; ctr < 10; ctr++)
  // {
  //   printf("\n\n#%d\nID: %d", ctr + 1, coustId[ctr]);
  //   printf("\nBalance: %.3f", coustBalance[ctr]);
  // }

  do /* this do...while lets the user to enter his ID until the program finds a match */
  {

    printf("\n\n------ Balance check ------");
    printf("\n\nHello and welcome the the balance check program, please enter your ID: ");
    scanf(" %d", &searchNum);

    // for loop that runs over the sorted ID's and breaks if:
    // 1.) ID found
    // 2.) we got to a ID that is bigger then the ID the user entered, meaning the ID isn't in the system
    for (ctr = 0; ctr < 10; ctr++)
    {
      check++;
      if (coustId[ctr] == searchNum) /* ID found, break the loop */
      {
        found = 1;
        break;
      }
    }

    if (coustId[ctr] > searchNum)
    /* we found ID bigger then the ID the user entered = ID isn't in the system = break the loop */
    {
      break;
    }

    if (found) /* If user ID was found the program return and valuate the data to the user */
    {
      if (coustBalance[ctr] > 100) /* Balance too high  */
      {
        printf("your current balance is ₪%.2f\n", coustBalance[ctr]);
        printf("your balance is over ₪100 and therfore you can't make anymore transactions\n");
      }
      else /* Balance OK */
      {
        printf("your current balance is ₪%.2f\n", coustBalance[ctr]);
        printf("your balance is below ₪100, you are good!\n");
      }
    }
    else /* If the system couldn't find user ID, program tells the user and then starting again */
    {
      printf("couldn't find costumer ID please try again");

      // tool for programer to make sure the program doesn't go through all the ID without cause (comment in to activate)
      // printf("\nprogram had to check %d ID", check);
    }
    check = 0;
  } while (!found);
  return 0;
}
