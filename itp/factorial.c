//calculating the factorial of a number.
#include<stdio.h>
int main()
{
int num,factorial=1;
printf("Enter a non negative integer:");
scanf("%d",&num); 
while (1){
  factorial= factorial*num; //calculating factorial of a number by multiplication and decrement.
  num--;
 if (num==1){
 break;
 }
 }
 printf("%d\n",factorial);
 return 0;
 }


