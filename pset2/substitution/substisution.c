#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
  if (argc == 1 || argc > 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }
  if (argc == 2)
  {
    for (int j = 0; j < strlen(argv[1]); j++)
    {
      for (int k = j + 1; k < strlen(argv[1]); k++)
      {
        if (argv[1][j] == argv[1][k])
        {
          printf("Key contains duplicate letters\n");
          return 1;
        }
      }
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
      if (isdigit(argv[1][i]))
      {

        printf("Usage: ./substitution key\n");
        return 1;
      }
    }

    if (strlen(argv[1]) != 26)
    {
      printf("Key must contain 26 characters.\n");
      return 1;
    }

    int x;
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
      if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
      {
        int result = (plaintext[i] - 'a') % 26;
        printf("%c", tolower(argv[1][result]));
      }
      else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
      {
        int result = (plaintext[i] - 'A') % 26;
        printf("%c", toupper(argv[1][result]));
      }
      else
      {
        printf("%c", plaintext[i]);
      }
    }
    printf("\n");
    return 0;
  }
}