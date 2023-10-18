#include<stdio.h>
int main(){
int n,a=1;
printf("Enter a number:");
scanf("%d",&n);
 
 for(int i=2;i<n;i++){
 if(n%i==0){
 a+=1;
 }
 }
  
  if(a>1) printf("Composite.");
  if(a==1) printf("Prime.");
  
 return 0;
 }
