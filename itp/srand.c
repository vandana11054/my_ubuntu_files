#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int bingo(int a,int b,int c, int d,int e,int f,int g,int h,int i){
int num= 1+ rand()%30;
printf("your bingo card\n%d %d %d\n%d %d %d\n%d %d %d\n",a,d,g,b,e,h,c,f,i);
printf("*%d*",num);
return num;
}


int main(void){
srand(time(NULL));
int a,b,c,d,e,f,g,h,i,j,num;
do{
 printf("Enter three values from 1 to 10:");
 scanf("%d %d %d",&a,&b,&c);
 } while(a<1||a>10|| b<1||b>10|| c<1||c>10);
do{
 printf("Enter three values from 11 to 20:");
 scanf("%d %d %d",&d,&e,&f);
 }while(d<11||d>20|| e<11||e>20|| f<11||f>20);
do{
 printf("Enter three values from 21 to 30:");
 scanf("%d %d %d",&g,&h,&i);
 }while(g<21||g>30|| h<21||h>30|| i<21||i>30);
 
 }
