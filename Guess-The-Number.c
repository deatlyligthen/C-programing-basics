#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  int SecretNum = 12;
  int Guess;
  int TryNum = 0;
  printf("Hello there Gamer! \nYou have 5 tries to guess the secret number \nIf you guess correctly you win but if you haven't figure out the number after five tries you lose, pretty simple right?\n");
  while (Guess != SecretNum && TryNum <= 5)
  {
    printf("Try #%d\n", TryNum);
    printf("Enter a number: ");
    scanf("%d", &Guess);
    /*  Help    */
    int Howfar = (Guess - SecretNum);
    if (Howfar > 0)
    {
      printf("Too big!\n");
    }
    else if (Howfar < 0)
    {
      printf("Too small!\n");
    }
    if (Howfar == 1 || Howfar == -1)
    {
      printf("You Are very close!\n");
    }

    if ((Howfar <= 5 && Howfar > 1) || (Howfar >= -5 && Howfar < -1))
    {
      printf("Your'e in the ballpark!\n");
    }
    if (Howfar >= 10 || Howfar <= -10)
    {
      printf("You are far away!\n");
    }

    if (TryNum >= 0 && Guess != SecretNum)
    {
      printf("Try again!\n");
    }
    TryNum++;
    if (TryNum == 5 && Guess != SecretNum)
    {
      printf("Last try\n");
    }
  }
  if (Guess == SecretNum && TryNum == 1)
  {
    printf("You Won!! and on the first try! that's very impressive! Horray!\n");
  }
  else if (Guess == SecretNum)
  {
    printf("You Win! Good job!\n");
  }
  else
  {
    printf("You Lose! Go Home!\n");
  }
  return 0;
}
