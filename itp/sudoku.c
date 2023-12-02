

10.2

#include<stdio.h>
 void inputsud(int a[4][4]);
 void display(int a[4][4]);
 void checkWin(int a[4][4]);
 void solvePuzzle(int a[4][4]);
int main(){

int num;
int game[4][4]={0};
printf("menu:\n 1. input sudoku\n 2.solve a puzzle\n 3.exit");
scanf("%d",&num);
switch(num){
case 1:
inputsud(game);
checkWin(game);
break;
case 2:
inputsud(game);
solvePuzzle(game);
checkWin(game);
break;
case 3:
printf("Exiting Game..");
break;
}
}
void display(int a[4][4]){
for(int m=0;m<4;m++){
for(int n=0;n<4;n++){
printf("|%d|",a[m][n]);
}
puts("\n");
}
}
void inputsud(int a[4][4]){
int p,q;
while(1){
printf("Enter the row number and column number of element.(enter 44,44 to exit.)");
scanf("%d %d",&p,&q);
if(p==44&&q==44){
break;
}
printf("Enter the value of the element.");
scanf("%d",&a[p][q]);
int r=0;
for(int i=0;i<4;i++){
for(int k=1;k<4&&i!=k;k++){
if(a[i][0]==a[k][0]!=0||a[i][1]==a[k][1]!=0||a[i][2]==a[k][2]!=0||a[i][3]==a[k][3]!=0) r=1;
}
}
if(((a[0][0]==a[1][1]&&a[0][0]>0)||(a[0][1]==a[1][0]&&a[1][0]>0))) r=2;
if(((a[0][2]==a[1][3]&&a[1][3]>0)||(a[1][2]==a[0][3]&&a[0][3]>0))) r=3;
if(((a[2][0]==a[3][1]&&a[3][1]>0)||(a[2][1]==a[3][0]&&a[3][0]>0))) r=4;
if(((a[2][2]==a[3][3]&&a[3][3]>0)||(a[3][2]==a[2][3]&&a[2][3]>0))) r=5;
if(r>0){
printf("INVALID ENTRIES.");
printf("please enter valid entries for same row and column numbers again.");
}
display(a);
}
}
void solvePuzzle(int a[4][4]){
int u,v;
while(1){
printf("Enter the row number and column number of element.(enter 44,44 to exit.)");
scanf("%d %d",&u,&v);
if(u==44&&v==44){
break;
}
printf("Enter the value of the element.");
scanf("%d",&a[u][v]);
display(a);
}
}
void checkWin(int a[4][4]){
int r=0;
for(int i=0;i<4;i++){
for(int k=1;k<4&&k!=i;k++){
if(a[i][0]==a[k][0]||a[i][1]==a[k][1]||a[i][2]==a[k][2]||a[i][3]==a[k][3]) r=1;
}
}
if((a[0][0]+a[0][1]+a[1][0]+a[1][1])>10) r=2;
if((a[0][2]+a[0][3]+a[1][2]+a[1][3])>10) r=3;
if((a[2][0]+a[2][1]+a[3][0]+a[3][1])>10) r=4;
if((a[2][2]+a[2][3]+a[3][2]+a[3][3])>10) r=5;
if(r==0) printf("CONGRATULATIONS.GAME WON.");
if(r>0) printf("GAME LOST.");
}
