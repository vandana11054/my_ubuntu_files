

#include<stdio.h>
int slice(char a[],int b);
int main(void){
int num,n;
printf("Enter string length:");
scanf("%d",&num);
printf("Enter string:");
char c[num];
for(int i=0;i<num;i++){
scanf(" %c",&c[i]);
}
n=slice(c,num);
for(int i=0;i<n;i++){
printf("%c",c[i]); 
} 
return 0;
}
int slice(char a[],int b){
int k=0,l=0;
int i=0;
while(1){                  //why while bcoz we need first m in our string as beggining of sliced string.
if(a[i]=='m'){
 k=i;
 break; 
}
else if(i>=b){
break;
}
i++;
}
for(int y=0;y<b;y++){     //why for bcoz we need last n in our string as ending of sliced string.
if(a[y]=='n') l=y;
}
if(a[k]=='m'&&a[l]=='n'){
for(int i=0;i<l-k+1;i++){
a[i]=a[k+i];
}
for(int i=l-k+1;i<b;i++){
a[i]=' ';
}
return (l-k)+1;
}else return b;
}
