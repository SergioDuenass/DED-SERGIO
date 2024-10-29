#include <stdio.h>
#define CLEAR printf("\033[0;0H\033[2J");
/* 
  Excercise 1 : swap
  Create a function that "swaps" the contents of two variables.
  It should receive two intengers, return nothing and after it execution
  whatever what inside one variable should be inside the other and viceversa 
  
*/

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Excercise 2 : blackjack

Create a blackjack function that:
  -receives 2 numbers and a FLAG (char)
  -returns 1 of the sum of the numbers is positive (greater than 0).
  -returns 0 if the sum of the numbers is negative.
  -Stores the sum of the two numbers in number2.
  -If the sum is 21, set the FLAG to = 'W' (winner)

   IN  IN/OUT  OUT
 (num1, num2, flag)

*/

int blackjack(int n1, int n2, char * flag) {
  int sum = n1 + n2;
  n2 = sum;
  if (sum == 21) {
    *flag = 'W';
  }
  return sum > 0;

}

int main()
{
  CLEAR
  /* Exercise 1:  swap num1 and num2 value */
  int num1 = 10;
  int num2 = 20;

  printf("Antes:\n num1 = %d, num2 = %d\n", num1, num2);
  swap(&num1, &num2);
  printf("Después:\n num1 = %d, num2 = %d\n", num1, num2);

  /* Exercise 2:  Blackjack 
    Call and test your program here */
  int n1 = 10;
  int n2 = 11;
  char flag = 'L';

  int result = blackjack(n1, n2, &flag);
  printf("resultado:\n %d, flag: %c\n", result, flag);
  return 0;
}