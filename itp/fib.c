#include<stdio.h>

 long int fib(int n){
long int f;
if (n==0) {
return 0;
}
else if(n==1){
return 1;
}
else {
f=fib(n-1) + fib(n-2);
return f;
}
}

int main(){
int n;
long int f;
printf("Enter the number of element of fibonnaci series:");
scanf("%d",&n);
f=fib(n);
printf("%ld\n",f);
return 0;
}
