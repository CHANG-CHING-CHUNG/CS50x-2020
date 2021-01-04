#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int height;
  do
  {
    height = get_int("Height: ");

  } while (height < 1 || height > 8);
  int n = 1;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < height; j++)
    {
      if (j < height - n)
      {
        printf(" ");
      }
      else
      {
        printf("#");
      }
    }
    printf("  ");
    for (int j = 0; j < n; j++)
    {

      printf("#");
    }
    n++;
    printf("\n");
  }
}