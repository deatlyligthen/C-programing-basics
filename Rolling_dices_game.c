// ofri.k 21/08/22
// roll dice guessing game

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int main()
{

  // introducing the game to the user and explaining the rules
  printf("\n\nHello and welcome to the dice guessing game!!! :)\n");
  printf("The rules are simple, I tell you the first roll of the dices\n");
  printf("Then you tell me what will be the nest roll compared to the first roll\n");
  printf("Higher, lower or the same ?!\n");
  printf("And then I roll the dices once more and tell you the result to see if your prediction was correct\n\n\n");

  // setting variables for the dices rolls, total,points and to seed the random number
  int dice1, dice2;
  int total1, total2;
  int points = 0;
  time_t t;
  char guess, answer, keepPlay;

  // in order to get a truly random number, we need to seed a number to the random number generator
  srand(time(&t));

  // roll dices and tells the user what was the rolls
  // (takes a random number and then modulo it by 5 and add 1
  // this way the number we will get is between 1 and 6)
  // this do...while keeps rolling the dices as long as the user wishes to keep playing
  do
  {
    dice1 = (rand() % 5) + 1;
    dice2 = (rand() % 5) + 1;
    total1 = dice1 + dice2;
    printf("\n------Rolling the dices-------\n");
    printf("\nFirst roll of the dices was %d and %d\n", dice1, dice2);
    printf("The total sum is %d\n", total1);

    // this do...while forces the user to enter h / l / s / H / L / S to predict the nest roll

    do
    {
      printf("what do you think the nest roll will be\n");
      printf("H = Higher,L = Lower,S = Same ???\n\n");
      scanf(" %c", &guess);
      guess = toupper(guess);

      /* checking if the user enter one of the options and only if he enters one of the options the loop breaks and we can move on */

    } while (!(guess == 'H' || guess == 'L' || guess == 'S'));

    // second roll of the dices:
    printf("\n----Rolling the dices----\n\n");
    dice1 = (rand() % 5) + 1;
    dice2 = (rand() % 5) + 1;
    total2 = dice1 + dice2;

    printf("second roll of the dices was %d and %d\n", dice1, dice2);
    printf("The total sum is %d\n", total2);

    // nested if's to check:
    // 1.) if the second roll is higher/lower/the same
    // 2.) if the user prediction was true or false and if so the user gets a point

    if ((total2 - total1) > 0) /*  checking if the second roll was higher */
    {
      answer = 'H';
      if (answer == guess) /* checking the user prediction */
      {
        printf("you are correct!!! \n%d is higher then %d\n", total2, total1);
        points++;
      }
      else
      {
        printf("you are wrong :( \n%d is higher then %d\n", total2, total1);
      }
    }
    else if (total2 - total1 < 0) /* checking if second roll was lower */
    {
      answer = 'L';
      if (answer == guess) /* checking the user prediction */
      {
        printf("you are correct!!! \n%d is lower then %d\n", total2, total1);
        points++;
      }
      else
      {
        printf("you are wrong :( \n%d is lower then %d\n", total2, total1);
      }
    }
    else /* checking if the second roll is the same */
    {
      answer = 'S';
      if (answer == guess) /* checking the user prediction */
      {
        printf("you are correct!!! \n%d is the same as %d\n", total2, total1);
        points++;
      }
      else
      {
        printf("you are wrong :( \n%d is the same as %d\n", total2, total1);
      }
    }

    // ask you user if he wishes to keep playing and forces him to enter only Y or N
    printf("\ndo you want to keep playing? (Y/N)\n");
    scanf(" %c", &keepPlay);
    keepPlay = toupper(keepPlay);
    while (!(keepPlay == 'Y' || keepPlay == 'N'))
    {
      puts("\nyou must enter 'Y' or 'N'\n");
      printf("\ndo you want to keep playing? (Y/N)\n");
      scanf(" %c", &keepPlay);
      keepPlay = toupper(keepPlay);
    }
  }

  // check to see if the user wants to keep playing:
  while (keepPlay == 'Y');

  // ending the game
  printf("\nThank you for playing!\n");
  printf("your total score is %d points\n", points);
  printf("I hope to see you soon!\n");
  printf(":) :) :)\n");

  return 0;
}
