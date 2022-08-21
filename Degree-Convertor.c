#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// celsius to fahrenheit convertor:

double C_to_F(double celsius_1)
{
  double fahrenheit_1 = (celsius_1 * 1.8) + 32;
  return fahrenheit_1;
}

// fahrenheit to celsius convertor:

double F_to_C(double fahrenheit_2)
{
  double celsius_2 = (fahrenheit_2 - 32) * (5.0 / 9);
  return celsius_2;
}

int main()
{
  double celsius;
  double fahrenheit;
  char degreePick;

  // ask the user for a type of degree they want to convert

  printf("\npick a degree you want to convert:\n'C' for celsius\n'F' for fahrenheit\n");
  scanf(" %c", &degreePick);

  // if the user choose celsius:

  if (degreePick == 'C')
  {
    printf("Enter a celsius degree: ");
    scanf("%lf", &celsius);
    printf("%.2f in celsius is %.2f in fahrenheit\n", celsius, C_to_F(celsius));
  }

  // if the user choose fahrenheit:

  else if (degreePick == 'F')
  {
    printf("Enter a Fahrenheit degree: ");
    scanf("%lf", &fahrenheit);
    printf("%.2f in fahrenheit is %.2f in celsius\n", fahrenheit, F_to_C(fahrenheit));
  }

  // if the user pick invalid letter:

  else
  {
    printf("invalid Letter :(\n");
  }
  return 0;
}
