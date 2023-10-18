

#include<stdio.h>
int main(){
char pi;
int count=8;
const char word[9]="beleiever";
printf("word guess game.");
printf("limit 8.");
char cS[9];
do{
printf("guess:");
scanf(" %c",&pi);
for(int i=0;i<8;i++){
if(pi==word[i]){
cS[i]=pi;
}
else {
cS[i]='_';
}
}
if(cS[0]=='_'&&cS[1]=='_'&&cS[2]=='_'&&cS[3]=='_'&&cS[4]=='_'&&cS[5]=='_'&&cS[6]=='_'&&cS[7]=='_'&&cS[8]=='_'){
count=count-1;
}
printf("Your guess is %c",pi);
printf("current status:%s",cS);
printf("attempts left:%d",count);
}while(count>0);
if(cS[0]=='b'&&cS[1]=='e'&&cS[2]=='l'&&cS[3]=='e'&&cS[4]=='i'&&cS[5]=='e'&&cS[6]=='v'&&cS[7]=='e'&&cS[8]=='r'){
printf("HURREY! your guess is right");
}
else{
printf("SORRY try again.");
}
}

