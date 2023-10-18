//program to find the minimum element of 6 membered array.

#include<stdio.h>
int main(){
int n[5];
int a=0,b=0;
for(int i=0;i<5;i+=1){
printf("Enter element(%d):",(i+1));
scanf("%d",&n[i]);
}

while(n[0]<n[1]){                                                        //conditions to be executed when first element is less than second element.
if ((n[0]<n[2])&&(n[0]<n[3])&&(n[0]<n[4])){
a=n[0];
}
else if ((n[0]>n[2])&& (n[0]>n[3])&&(n[0]<n[4])){
if(n[2]>n[3]) a=n[3];
else a=n[2];
}
else if ((n[0]>n[2])&& (n[0]<n[3])&&(n[0]>n[4])){
if(n[2]>n[4]) a=n[4];
else a=n[2];
}
else if ((n[0]<n[2])&& (n[0]>n[3])&&(n[0]>n[4])){
if(n[3]>n[4]) a=n[4];
else a=n[3];
}
else if ((n[0]>n[2])&& (n[0]>n[3])&&(n[0]>n[4])){
if(n[2]>n[4] && n[3]>n[4]) a=n[4];
if(n[2]>n[3] && n[4]>n[3]) a=n[3];
if(n[3]>n[2] && n[4]>n[2]) a=n[2];
}
else if ((n[0]>n[4])&& (n[0]<n[2]) && (n[0]<n[3])) a=n[4];
else if ((n[0]>n[3])&& (n[0]<n[2]) && (n[0]<n[4])) a=n[3];
else if ((n[0]>n[2])&& (n[0]<n[3]) && (n[0]<n[4])) a=n[2];
if (a>0){
printf("%d",a);
}
break;
}

while(n[0]>n[1]){                                                      //conditions to be executed when first element is more than second element.
if ((n[1]<n[2])&&(n[1]<n[3])&&(n[1]<n[4])){
b=n[1];
}
else if ((n[1]>n[2])&& (n[1]>n[3])&&(n[1]<n[4])){
if(n[2]>n[3]) b=n[3];
else b=n[2];
}
else if ((n[1]>n[2])&& (n[1]<n[3])&&(n[1]>n[4])){
if(n[2]>n[4]) b=n[4];
else b=n[2];
}
else if ((n[1]<n[2])&& (n[1]>n[3])&&(n[1]>n[4])){
if(n[3]>n[4]) b=n[4];
else b=n[3];
}
else if ((n[1]>n[2])&& (n[1]>n[3])&&(n[1]>n[4])){
if(n[2]>n[4] && n[3]>n[4]) b=n[4];
if(n[2]>n[3] && n[4]>n[3]) b=n[3];
if(n[3]>n[2] && n[4]>n[2]) b=n[2];
}
else if ((n[1]>n[4])&& (n[1]<n[2]) && (n[1]<n[3])) b=n[4];
else if ((n[1]>n[3])&& (n[1]<n[2]) && (n[1]<n[4]))b=n[3];
else if ((n[1]>n[2])&& (n[1]<n[3]) && (n[1]<n[4])) b=n[2];
if (b>0){
printf("%d",b);
}
break;
}
printf("\n*");                                                        //program termination indicator.
return 0;
}
