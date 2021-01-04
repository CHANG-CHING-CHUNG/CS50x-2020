#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
float getAverageOfLetters(float letterCount, float wordCount);
float getAverageOfSentences(float sentenceCount, float wordCount);
int calculateReadability(float AverageOfLetters, float AverageOfSentences);
void outputResult(int resultIndexNum, string originalString);
int main(void)
{
  string originalString = get_string("Text: ");
  float wordCount = 0;
  float sentenceCount = 0;
  float letterCount = 0;
  int len = strlen(originalString);
  for (int i = 0; i < len; i++)
  {
    if ((originalString[i] >= 'A' && originalString[i] <= 'Z') || (originalString[i] >= 'a' && originalString[i] <= 'z'))
    {
      letterCount++;
    }
    if (originalString[i] == ' ')
    {
      wordCount++;
    }
    if (originalString[i] == '!' || originalString[i] == '?' || originalString[i] == '.')
    {
      sentenceCount++;
    }
  }
  wordCount++;
  float L = getAverageOfLetters(letterCount, wordCount);
  float S = getAverageOfSentences(sentenceCount, wordCount);

  int resultIndexNum = calculateReadability(L, S);
  outputResult(resultIndexNum, originalString);
}

float getAverageOfLetters(float letterCount, float wordCount)
{
  return letterCount / wordCount * 100;
}

float getAverageOfSentences(float sentenceCount, float wordCount)
{
  return sentenceCount / wordCount * 100;
}

int calculateReadability(float AverageOfLetters, float AverageOfSentences)
{
  return round(0.0588 * AverageOfLetters - 0.296 * AverageOfSentences - 15.8);
}

void outputResult(int resultIndexNum, string originalString)
{
  if (resultIndexNum >= 16)
  {
    printf("Grade 16+\n");
  }
  else if (resultIndexNum < 1)
  {
    printf("Before Grade 1\n");
  }
  else
  {
    printf("Grade %d\n", resultIndexNum);
  }
}