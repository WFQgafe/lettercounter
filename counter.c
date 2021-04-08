/*******************************************************************************
* 
* Purpose: Assignment #3 solution.
*
* Author: Kevin Browne
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define COUNT_SIZE 26

int main()
{
  char buffer[BUFFER_SIZE], input, curchar;
  int i = 0, count[COUNT_SIZE];
  int other = 0;

  // request and read in the string from the user
  printf("Enter text for analysis: ");
  while ( (input = getchar()) != '\n' ) {
    buffer[i++] = input;
  }
  buffer[i] = '\0';

  // set the letter counts to zero
  for (i = 0; i < COUNT_SIZE; i++) count[i] = 0;

  // Count the occurences of each letter a-z in the string (case insenstive)
  // in the count array with count[0] for 'a', count[1] for 'b' and so on.
  // We ensure the character being examined is an uppercase character with
  // toupper() and then we check if it is in the ASCII range for A-Z (65-90)
  // to determine if we need to increment a count... if it is we increment
  // the right index using 65 as an 'offset'.
  for (i = 0; i < strlen(buffer); i++) {
    curchar = toupper(buffer[i]);
    if (curchar >= 65 && curchar <= 90) count[curchar - 65]++;
    else other++;
  }

  // Create the letter analysis table
  printf("\n\nLetter Analysis Complete!");
  printf("\n\nLetter    Occurrences    Percentage\n");
  printf("*****************************************\n");
  for (i = 0; i < COUNT_SIZE; i++) {
    printf("%-10c%-15d%-15.2f\n", i + 65,
                               count[i],
                               (((float) count[i]) / strlen(buffer)) * 100);
  }
  // Output the number of other characters
  printf("%-10s%-15d%-15.2f\n","Other",
                              other,
                              (((float) other) / strlen(buffer)) * 100);
  return 0;
}
