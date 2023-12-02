

//Code for creating database of cricket players.
#include <stdio.h>
#include<stdlib.h>
struct  Player{                                                //struct to contain details of each player.
int *Id;
char *Name[50];
int *age;
float *battingAvg;
float *bowlingAvg;
};

struct Player* createPlayer();                                //function to add a player to database.
void displayPlayer(struct Player*);                           //function to display player info.
void freePlayer(struct Player*);                              //function to free the data allocated during run time.

int main(void)
{
int num;
int all=0;
 struct Player* one=NULL;
 struct Player **All=NULL;                                    //pointer to a pointer of struct player type.(array of pointers application)
while(1){                                                     //Sentenial controlled.
 printf("...Functions...\n");
 printf("1.Add player\n2.Display player\n3.Display all players\n4.exit\n");
 printf("Enter the required function: ");
 scanf("%d",&num);
 switch (num){
 case 1:
 all++;
 one=createPlayer();                                          //add player.
 break;
 case 2:
 if(one!=NULL){
 displayPlayer(one);                                          //print player info.
 }
 else{
 printf("No player to display");
}
 break;
 case 3:
All=(struct Player**)malloc(all*sizeof(struct Player*));     //array of pointers.
for(int i=0;i<all;i++){
All[i]=createPlayer();
}
for(int k=0;k<all;k++){
displayPlayer(All[k]);
}
for(int i=0;i<all;i++){
freePlayer(All[i]);
}
free(All);
break;
default:
break;
}
if(num==4){
printf("Thankyou for exiting**");
break;
}
}
}
struct Player* createPlayer(){                                          //using direct struct variable name,pointers for accesing struct members.
struct Player* a=(struct Player*)malloc(sizeof(struct Player));   
a->Id=(int* )malloc(sizeof(int));
for(int i=0;i<50;i++){
a->Name[i]=(char*  )malloc(sizeof(char)*50);
}
a->age=(int* )malloc(sizeof(int));
a->battingAvg=(float* )malloc(sizeof(float));
a->bowlingAvg=(float*)malloc(sizeof(float));
printf("Enter Id number:");
scanf("%d",(a->Id));
printf("enter name:");
scanf("%s",a->Name[0]);
printf("enter age:");
scanf("%d",(a->age));
printf("enter batting average:");
scanf("%f",(a->battingAvg));
printf("enter bowling average:");
scanf("%f",(a->bowlingAvg));
return a;
}
void displayPlayer(struct Player* y){
printf("Name %14s \n",y->Name[0]);
printf("ID number %9d \n",*(y->Id));
printf("age %15d \n",*(y->age));
printf("batting average %10f \n",*(y->battingAvg));
printf("bowling average %10f \n",*(y->bowlingAvg));
}
void freePlayer(struct Player* s){                                           //Memory management(if not done segmentation fault)
for(int i=0;i<50;i++){
free(s->Name[i]);
} 
free(s->Id);
free(s->age);
free(s->battingAvg);
free(s->bowlingAvg);
free(s);
}
