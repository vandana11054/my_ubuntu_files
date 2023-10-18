#include<stdio.h>
int main(){
int n,a=1,i=1;
printf("Enter a number:");
scanf("%d",&n);
 
 do{
 if(n%i==0){
 a+=1;
 }
 i+=1;
 }while(i<n);
  
  if(a>2) printf("Composite.");
  if(a==2) printf("Prime.");
  
 return 0;
 }
