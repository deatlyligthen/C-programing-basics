#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  int total = 1;
  int endNum;
  int startNum = 1;
  printf("Enter a number: ");
  scanf("%d", &endNum);
  if (endNum >= 0)
  {
    while (startNum <= endNum)
    {
      total = total * startNum;
      startNum++;
    }
    printf("%d! = %d\n", endNum, total);
  }
  else
  {
    printf("Math problem\n");
  }
  return 0;
}