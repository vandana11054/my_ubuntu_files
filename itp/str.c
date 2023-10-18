

 #include<stdio.h>

 void concatenateStrings(char str1[],char str2[]);
 int findStringLength(char str[]);
 int compareStrings(char str1[],char str2[]);
 void copyString(char dest[],char src[]);
 void reverseString(char str[]);
 int quit(int choice); 
 int len=0;
 char str1[10];
char str2[10];

int main(){
int choice,num;
char str[10],dest[10],src[10];
printf("Enter a word:");
scanf("%s",str1);
printf("Enter a word:");
scanf("%s",str2);

while(1){                                 //termination of program is user friendly.
printf("Menu of choice.\n");
printf("........................\n");
printf("1. concatenateStrings\n 2.findStringLength\n 3. compareStrings\n 4. copyString\n 5.reverseString\n 6. Quit\n");    //display menu.
printf("Enter your choice:");
scanf("%d",&choice);                      //user's choice.

switch(choice){
case 1:
concatenateStrings(str1,str2);
break;
case 2:
len=findStringLength(str);
break;
case 3:
num=compareStrings( str1, str2);
break;
case 4:
 copyString( dest, src);
break;
case 5:
reverseString(str);
break;
default:
break;
}

if (choice==6){
printf("*");
break;                               //quit .
}
}
}
  
  void concatenateStrings(char str1[],char str2[]){
  int h=0;
  char str3[20];
  while(str1[h]!='\0'){
  str3[h]=str1[h];
  h+=1;
  }
  int j=0;
  while(str2[j]!='\0'){
  str3[h]=str2[j];
  h+=1;
  j+=1;
  }
  printf("%s",str3);
  }
  
  int findStringLength(char str[]){
  int number,i,p,r=0;
  printf("enter a number of string whose length is to be calculated:");
  scanf("%d",&number);
  if (number==1){
  for(int i=0;str1[i]!='\0';i++){
  r=i;
  }
  printf("str1 length is %d",r+2);
  }
  else if (number==2){
  for(int p=0;str2[p]!='\0';p++){
  r=p;
  }
  printf("str2 length is %d",r+2);
  }
  else printf("Enter 1 or 2");
  len=r+2;
  return len;
  }
  
  
   int compareStrings(char str1[],char str2[]){
   int c,d,e=0,f=0,g;
   len=findStringLength(str1);
   do{
   c=(int) str1[e];
   d=(int) str2[f];
   if(c==d) g=0;
   if(c<=d) g=-1;
   if(c>=d) g=1;
   e++;
   f++;
   }while(c=d);
   if(g==0) printf("equal strings.");
    if(g<0) printf(" string1 is greater.");
    if(g>0) printf("string2 is greater.");
    }
   
   void copyString(char dest[],char src[]){
   int length;
   printf("\n enter the number of string which is source:");
   scanf("%d",&length);
   if (length==1){
   str2==str1;
   printf("%s\n",str2);
   }
   else{
   str1==str2;
   printf("%s\n",str1);
   }
   }
  
  void reverseString(char str[]){
  int num,a,b;
  printf("Enter the number of string which is to be reversed:");
  scanf("%d",&num);
  if(num==1){
  len=findStringLength(str1);
  for(int a=len;a>=0;a--){
  printf("%c\n", str1[a]);
  }
  }
  if(num==2){
  len=findStringLength(str2);
  for(int b=len;b>=0;b--){
  printf("%c\n", str2[b]);
  }
  }
  }
   


  
  
  
  
  
