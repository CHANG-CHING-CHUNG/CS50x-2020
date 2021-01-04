#include <stdio.h>
#include <cs50.h>
#include <math.h>

long getStartingNumber(long copyCardNumber);
void checkCardType(int length, long startingNumber);

int main(void)
{
  long cardNumber = get_long("Number: ");
  long copyCardNumber = cardNumber;
  int sum = 0;
  int countDigit = 1;
  while (copyCardNumber > 0)
  {
    if (countDigit % 2 == 0)
    {
      int digit = copyCardNumber % 10 * 2;
      if (digit > 9)
      {
        int second;
        while (digit > 9)
        {
          second = digit / 10;
          digit = digit % 10;
        }
        sum = sum + second + digit;
      }
      else
      {
        sum += digit;
      }
    }
    copyCardNumber /= 10;
    countDigit++;
  }

  copyCardNumber = cardNumber;
  countDigit = 1;
  while (copyCardNumber > 0)
  {
    if (countDigit % 2 != 0)
    {
      sum += copyCardNumber % 10;
    }
    copyCardNumber /= 10;
    countDigit++;
  }
  int length = countDigit - 1;
  int checksum = sum % 10;
  long startingNumber = getStartingNumber(cardNumber);
  if (checksum == 0)
  {
    checkCardType(length, startingNumber);
  }
  else
  {
    printf("INVALID\n");
  }
}

long getStartingNumber(long copyCardNumber)
{
  while (copyCardNumber > 100)
  {
    copyCardNumber /= 10;
  }
  return copyCardNumber;
}

void checkCardType(int length, long startingNumber)
{
  int AMEX_LENGTH = 15;
  int MASTERCARD_LENGTH = 16;
  int VISA_LENGTH_MAX = 16;
  int VISA_LENGTH_MIN = 13;

  int AMEX_START_NUMBER_1 = 34;
  int AMEX_START_NUMBER_2 = 37;

  int MASTER_START_NUMBER_1 = 51;
  int MASTER_START_NUMBER_2 = 52;
  int MASTER_START_NUMBER_3 = 53;
  int MASTER_START_NUMBER_4 = 54;
  int MASTER_START_NUMBER_5 = 55;

  int VISA_START_NUMBER = 4;
  long copyStartingNumber = startingNumber / 10;
  if (length == AMEX_LENGTH)
  {

    if (startingNumber == AMEX_START_NUMBER_1 || startingNumber == AMEX_START_NUMBER_2)
    {
      printf("AMEX\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else if (length == MASTERCARD_LENGTH && copyStartingNumber != 4)
  {

    if (startingNumber == MASTER_START_NUMBER_1 || startingNumber == MASTER_START_NUMBER_2 || startingNumber == MASTER_START_NUMBER_3 || startingNumber == MASTER_START_NUMBER_4 || startingNumber == MASTER_START_NUMBER_5)
    {

      printf("MASTERCARD\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else if (length == VISA_LENGTH_MAX || length == VISA_LENGTH_MIN)
  {
    if (copyStartingNumber == VISA_START_NUMBER)
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else
  {
    printf("INVALID\n");
  }
}