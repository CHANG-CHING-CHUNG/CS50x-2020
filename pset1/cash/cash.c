#include <stdio.h>
#include <cs50.h>
#include <math.h>

int computeCoins(int quarter, int dime, int nickel, int penny, int count, int cents);

int main(void)
{

  float dollars;
  int count = 0;
  int quarter = 25;
  int dime = 10;
  int nickel = 5;
  int penny = 1;

  do
  {
    dollars = get_float("Change owed: ");

  } while (dollars < 0);
  int cents = round(dollars * 100);
  int coins = computeCoins(quarter, dime, nickel, penny, count, cents);
  printf("%i\n", coins);
}

int computeCoins(int quarter, int dime, int nickel, int penny, int count, int cents)
{

  while (cents > 0)
  {
    if (cents >= quarter)
    {
      cents -= quarter;
      count++;
    }
    else if (cents >= dime)
    {
      cents -= dime;
      count++;
    }
    else if (cents >= nickel)
    {
      cents -= nickel;
      count++;
    }
    else if (cents >= penny)
    {
      cents -= penny;
      count++;
    }
  }
  return count;
}