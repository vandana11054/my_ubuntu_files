
//program to calculate the difference between first and last digits of a number.


#include<stdio.h>
#include<math.h>  //required for pow function.

int main(){
int num;
printf("Enter a number:");
scanf("%d", &num);
int y=(num%10);
printf("Last digit of your number is %d.\n",y);
int x = 1;

while(1){     //to calculate first digit of your number.
  int n=floor(num/pow (10,x));
  if(n==0){
  break;
  }
x=x+1;
}

  int a=  floor(num/ pow(10,(x-1)));
  printf("First digit of your number is %d\n",a);
  printf("difference between first and last digits of your number is %d.",(a-y));
  return 0;
 }
