// Number guessing game.
#include<stdio.h>
#include<stdlib.h>                                                  //reqired to run rand() function.

int getGuess(int l, int h);
void evaluateGuess(int b,int target);

int getGuess(int l,int h){                                          //function to take guess from user.
int guess;
printf("Guess the output between %d and %d:\n",l,h);  
scanf("%d",&guess);                                                 //asking user to guess.
return guess;
}


void evaluateGuess(int guess,int target)                           //function to check his guess is correct or not.
{
if (target==guess) {
printf(" Congratulations!your guess is correct.");
}
else if (target<guess){
printf("too high,try again.");
}
else 
{
printf("too low,try again.");
}
}
 
 
 int main(void){
 int l,h,i=0;

 do{
 printf(" please enter a lower bound less than upper bound\n");
 printf("Enter the lower bound of your range(integer value:)\n");
 scanf("%d",&l);                                                     
 printf("Enter the upper bound of your range(integer value:)\n");    //asking the bounds from user.
 scanf("%d",&h);
 } while(l>h);

 int target= l+rand()%(h-l+1);                                    //generating  target.
 int guess;
 do {
 guess=getGuess(l, h);
 evaluateGuess(guess,target);
 i+=1;                                                          //counting number of attempts by user.
 } while(guess!=target);

 printf("your number of attempts are %d ", i);                   //displaying number of attempts.
 }
 











