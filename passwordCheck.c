// ofriK 21/08/2022
// password check program

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  // initialising variables for password check
  // and for the password and username

  int digit, smallLetter, bigLetter, special, length;
  char username[20], password[25];
  length = special = bigLetter = smallLetter = digit = 0;

  // interacting with the user to get a username and a password that he chooses
  printf("pick a username (username can't contain spaces): ");
  scanf(" %s", username);

  printf("pick a password, the password must be at least 5 characters and contain:\n");
  printf("#1 lowercase letter\n#2 uppercase letter\n#3 a number\n#4 special character\n");
  scanf(" %s", password);

  printf("\n-------running a password check-------\n");

  // running the password check (for every character in the password the program check if it a lowercase/uppercase/number/special character
  // the program also checks the length of the password
  for (int index = 0; index < strlen(password); index++)
  {
    if (islower(password[index])) /* checks for lowercase letter */
    {
      smallLetter = 1;
    }
    else if (isupper(password[index])) /* checks for uppercase letter */
    {
      bigLetter = 1;
    }
    else if (isdigit(password[index]))
    {
      digit = 1; /* checks for a number */
    }
    else
    {
      special = 1; /* checks for a special character */
    }
    if (strlen(password) >= 5) /* checks the length of the password */
    {
      length = 1;
    }
  }
  // only if the password contain everything it should then:

  if (smallLetter && bigLetter && digit && special && length)
  {
    printf("\nPassword check passed successfully!\n");
    printf("your username is : %s \n", username);
    printf("your password is: %s\n", password);
  }

  // tells the user that he failed the password check
  else
  {
    printf("\npassword check failed, try again\n");
  }

  return 0;
}
