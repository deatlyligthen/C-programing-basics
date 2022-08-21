#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  double FirstNum;
  char function;
  double SecondNum;
  printf("Hello give me the first number, a function and a second number:  ");
  scanf("%lf %c %lf", &FirstNum, &function, &SecondNum);

  if (function == '+')
  {
    printf("The sum of those number are: %.2f \n", FirstNum + SecondNum);
  }
  else if (function == '-')
  {
    printf("the Subtraction of those number are: %.2f \n", FirstNum - SecondNum);
  }
  else if (function == '*')
  {
    printf("the multiplication of those number are: %.2f \n", FirstNum * SecondNum);
  }
  else if (function == '/')
  {
    printf("The division of those numbers are: %.2f \n", FirstNum / SecondNum);
  }
  else
  {
    printf("Invalid operation\n");
  }

  return 0;
}
