// ofri-kuperberg 13/08/22
// favorite and least favorites movies program

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  // setting variables for taking: number of movies, ratings and names
  int numMovies, favRate, leastRate, rating, count;
  char movie[40], favMovie[40], leastMovie[40];
  // for compering the fav and least:
  favRate = 0;
  leastRate = 10;
  count = 1;

  // keeps asking for a number of movies until the user enter at least 2 movies
  do
  {
    printf("\nthis program will tell you your favorite and least favorite movies this year\n");
    printf("how many movies have you seen this year?\n");
    scanf(" %d", &numMovies);
    if (numMovies < 1)
    {
      printf("you haven't seen any movies this year?\nso never mind have a wonderful day\n\n");
    }
    if (numMovies == 1)
    {
      printf("only one movie?\nfor this program to work you need to enter at least two movies.... sorry\n\n");
    }
  } while (numMovies <= 1);

  // asking for names and rating of all the movies the user enters
  for (int countMovies = 1; countMovies <= numMovies; countMovies++)
  {
    printf("Enter the #%d movie name", count);
    printf(" (if the title is more then 1-word, add '-' between words)\n");
    scanf(" %s", movie);
    printf("great, what is your rating for the movie? (enter an integer from 1 to 10)\n");
    scanf(" %d", &rating);
    ++count;

    // checking to see the favorite movie and the least favorite movie:

    if (rating > favRate)
    {
      strcpy(favMovie, movie);
      favRate = rating;
    }
    if (rating < leastRate)
    {
      strcpy(leastMovie, movie);
      leastRate = rating;
    }
  }
  // printing the favorite and least favorite movies:

  printf("\n\nyour favorite movie this year is: \"%s\"\n", favMovie);
  printf("and the rating you gave it is: %d\n\n", favRate);

  printf("your least favorite movie is: \"%s\"\n", leastMovie);
  printf("and the rating you gave it is: %d\n\n\n", leastRate);
  return 0;
}