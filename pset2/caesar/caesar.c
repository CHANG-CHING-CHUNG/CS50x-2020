#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
  if (argc == 1 || argc > 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  if (argc == 2)
  {
    for (int i = 0; i < strlen(argv[1]); i++)
    {
      if (!isdigit(argv[1][i]))
      {

        printf("Usage: ./caesar key\n");
        return 1;
      }
    }

    int x;
    sscanf(argv[1], "%d", &x);
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
      if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
      {
        char result = (plaintext[i] + x - 'a') % 26;
        printf("%c", result + 'a');
      }
      else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
      {
        char result = (plaintext[i] + x - 'A') % 26;
        printf("%c", result + 'A');
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