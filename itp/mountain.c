//the elements in array are in increasing and decreasing sequence.
#include<stdio.h>
int main(){
int n[6];

for(int i=0;i<6;i+=1){
printf("Enter element(%d):",(i+1));
scanf("%d",&n[i]);
}

     if(n[0]<n[1]&& n[1]<n[2]&&n[2]<n[3]&& n[3]<n[4]&& n[4]>n[5]){            //Mountain sequence possibilities.
printf("Yes");
}
else if(n[0]<n[1]&& n[1]<n[2]&&n[2]<n[3]&& n[3]>n[4]&& n[4]>n[5]){
printf("Yes");
}
else if(n[0]<n[1]&& n[1]<n[2]&&n[2]>n[3]&& n[3]>n[4]&& n[4]>n[5]){
printf("Yes");
}
else if(n[0]<n[1]&& n[1]>n[2]&&n[2]>n[3]&& n[3]>n[4]&& n[4]>n[5]){
printf("Yes");
}
else  printf("No");                              //all other sequences other than increasing and decreasing sequences.
}
