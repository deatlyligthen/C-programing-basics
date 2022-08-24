// ofri.k 23/08/22
// basketball data and review

#include <stdio.h>
#include <ctype.h>

int main()
{
  // initialise variables to set the: game points, game rebounds, game assists, counting games
  // number of game user would like to enter, game index for future use
  // and finlay the choices of the user throughout the program

  int gamePoints[10];
  int gameRebound[10];
  int gameAssists[10];
  int count = 1;
  int numberOfGames;
  int indexGame;

  char playerChoice;

  // SRA - where the user could enter the game data

  printf("\n\n*********** SRA -score ,rebounds and assists ***********");
  // this do...while loop forces the user to enter up as 10 games only
  do
  {
    printf("\n\nHow many games data would you like to enter?\n(enter a number between 1 and 10)\n");
    scanf(" %d", &numberOfGames);
    if (numberOfGames > 10 || numberOfGames < 1)
    {
      printf("invalid number, try again");
    }
  } while (numberOfGames > 10 || numberOfGames < 1);

  // user enter game points to the array:
  printf("\nplease enter your game points, rebounds and assists\n");
  printf("\nFirst, enter your score points:");
  for (indexGame = 0; indexGame < numberOfGames; indexGame++)
  {
    printf("\n#%d game: ", count);
    scanf(" %d", &gamePoints[indexGame]);
    count++;
  }
  count = 1; /* initialise the count once more to 1 to start counting again */

  // user enters number of rebounds:
  printf("\n\nGreat, now enter your game rebounds:\n");
  for (indexGame = 0; indexGame < numberOfGames; indexGame++)
  {
    printf("\n#%d game: ", count);
    scanf(" %d", &gameRebound[indexGame]);
    count++;
  }
  count = 1; /* initialise the count once more to 1 to start counting again */

  // user enters number of assists:
  printf("\n\nawesome, and lastly enter your game assists\n");
  for (indexGame = 0; indexGame < numberOfGames; indexGame++)
  {
    printf("\n#%d game: ", count);
    scanf(" %d", &gameAssists[indexGame]);
    count++;
  }

  // SRA is done, ask to user if he would like to see game review:
  printf("\nthank you!\nSRA is done, would you like to see your game review?\n");

  do /* this do...while loops is forcing the user to enter only 'Y' or 'N' */
  {
    printf("Enter as follows:\n");
    printf("'Y' for yes\n'N' for no\n");
    scanf(" %c", &playerChoice);
    playerChoice = toupper(playerChoice);
  } while (!(playerChoice == 'Y' || playerChoice == 'N')); /* only if the user enter 'Y' or 'N' the loop will break */

  // if the user wishes to accesses game review:
  if (playerChoice == 'Y')
  {

    // initialise the high/low indexes and the game performance
    int highScoreIndex = 0;
    int lowScoreIndex = 0;
    int highScore = 0;
    int lowScore = 150;
    float gamePerformance;
    indexGame = 0;

    do /* this do...while loops only loops if the user would like to see another review:  */
    {
      // introducing the system to the user:
      printf("\n\n------Game Review------");
      printf("\n\nHello and welcome to the game review!\n");
      printf("this program ask you which game review would you like to see\n");
      printf("your highest scoring game or your lowest scoring game or a specific game\n");

      do /* this do...while loop forces the user to only enter H/L/S */
      {
        printf("Please enter as follows:\n");
        printf("'H' - for highest scoring game\n'L' - for lowest scoring game\n'S' - specific game\n");
        scanf(" %c", &playerChoice);
        playerChoice = toupper(playerChoice);

        // this loop will break only if the user enter H/L/S
      } while (!(playerChoice == 'H' || playerChoice == 'L' || playerChoice == 'S'));

      // Highest scoring game:
      if (playerChoice == 'H')
      {
        // for loop to find the maximum score
        for (indexGame = 0; indexGame < numberOfGames; indexGame++)
        {
          if (gamePoints[indexGame] > highScore)
          {
            highScore = gamePoints[indexGame];
            highScoreIndex = indexGame; /* setting the game index to the highest game score */
          }
        }

        // calculate the game performance as so:
        // %70 = game scores
        // %20 = game rebound
        // %10 = game assists
        gamePerformance = ((0.7 * (gamePoints[highScoreIndex])) + (0.2 * (gameRebound[highScoreIndex])) + (0.1 * (gameAssists[highScoreIndex])));

        // after it finds the best game the program will print out the game data:
        printf("\nyour best game is your #%d game and the game review as follows\n", highScoreIndex + 1);
        printf("Number of points -------> %d", gamePoints[highScoreIndex]);
        printf("\nNumber of rebounds -------> %d", gameRebound[highScoreIndex]);
        printf("\nNumber of assists -------> %d", gameAssists[highScoreIndex]);
        printf("\noverall game performance -------> %.2f\n", gamePerformance);
      }

      // Lowest scoring game:
      else if (playerChoice == 'L')
      {

        // for loop for finding the lowest game score:
        for (indexGame = 0; indexGame < numberOfGames; indexGame++)
        {
          if (gamePoints[indexGame] < lowScore)
          {
            lowScore = gamePoints[indexGame];
            lowScoreIndex = indexGame;
          }
        }

        gamePerformance = ((0.7 * (gamePoints[lowScoreIndex])) + (0.2 * (gameRebound[lowScoreIndex])) + (0.1 * (gameAssists[lowScoreIndex])));

        // after it finds the lowest game score it prints out the game data:
        printf("\nyour worst game is your #%d game and the game review as follows\n", lowScoreIndex + 1);
        printf("Number of points -------> %d", gamePoints[lowScoreIndex]);
        printf("\nNumber of rebounds -------> %d", gameRebound[lowScoreIndex]);
        printf("\nnumber of assists -------> %d\n", gameAssists[lowScoreIndex]);
        printf("\noverall game performance -------> %.2f\n", gamePerformance);
      }

      // if the user wishes to see a specific game data
      else
      {
        // this do...while loops forces the user to only enter an available game based on how many games he entered
        do
        {
          printf("\nwhich game number would you like to see? (1-%d)\n", numberOfGames);
          scanf(" %d", &indexGame);
          if (indexGame > numberOfGames || indexGame < 1)
          {
            printf("Invalid game number");
          }
        } while ((indexGame > 10 || indexGame < 1));

        gamePerformance = ((0.7 * (gamePoints[indexGame - 1])) + (0.2 * (gameRebound[indexGame - 1])) + (0.1 * (gameAssists[indexGame - 1])));

        // after the user choose a valid game, the game data will print out:
        printf("your #%d game review as follows:\n", indexGame);
        printf("Number of points -------> %d", gamePoints[indexGame - 1]);
        printf("\nNumber of rebounds -------> %d", gameRebound[indexGame - 1]);
        printf("\nnumber of assists -------> %d", gameAssists[indexGame - 1]);
        printf("\noverall game performance -------> %.2f\n", gamePerformance);
      }

      // the program ask the user if he would like to review another game:
      printf("\nwould you like to review another game?\n");
      do /* again force the user to only enter 'Y' or 'N' */
      {
        printf("Enter as follows:\n");
        printf("'Y' for yes\n'N' for no\n");
        scanf(" %c", &playerChoice);
        playerChoice = toupper(playerChoice);
      } while (!(playerChoice == 'Y' || playerChoice == 'N'));

    } while (playerChoice == 'Y'); /* keeps running the game review as long as the user wishes */

    printf("ok, Goodbye have a wonderful day!\n");
  }
  else /* this line happens only if after the SRA the user doesn't want to see the game review: */
  {
    printf("Ok, have a wonderful day!\n");
  }
  return 0;
}