//Lucas series generator.

#include<stdio.h>
int main(){
int num;
printf("Enter a number:");   
scanf("%d",&num);       //for taking input of number of values required.
int k=2,l=1,m=0,i=0;    //In Lucas series first number=k=2,Second number=l=1.(m be the number which is the sum of previous two Luca's numbers).
printf("%d\n",k);
printf("%d\n",l);

while(i<num-2){         //already first two numbers are printed.
   m=k+l;
   printf("%d\n",m);    //printing series.
   k=l;
   l=m;
   i=i+1;
}

return 0;
}

