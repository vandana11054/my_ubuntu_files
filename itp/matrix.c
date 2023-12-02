

10.1
//MATRIX OPERATIONS.

#include<stdio.h>
int u=3;
int y=3;
void matrixInput(int c[][3],int,int,int d[][3],int ,int);     //declaring required functions.           
void matrixAdd(int c[][3],int,int,int d[][3],int ,int);
void matrixSub(int c[][3],int,int,int d[][3],int ,int);
void matrixMul(int c[][3],int,int,int d[][3],int ,int);
void matrixTranspose(int c[][3],int,int,int d[][3],int ,int);
void matrixDisplay(int c[][3],int,int,int d[][3],int ,int);
int main(void){
    int num;
    int a,b;
    printf("please the number of rows of two arrays:");
    scanf("%d %d",&a,&b);
    int array1[a][3];
    int array2[b][3];
    int array3[a][3];
    matrixInput(array1,a,3,array2,b,3);
    printf("....Choose any operation:....\n");
    printf("1.Matrix addition\n2.Matrix subtraction\n3.Matrix multiplication\n4.Matrix Transpose\n5.Matrix display.");
    scanf("%d",&num);
    
    switch(num){
        case 1:
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
   printf(" %d",array1[m][n]);
    }
    puts("\n");
    }
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
   printf(" %d",array2[m][n]);
    }
    puts("\n");
    }
        matrixAdd(array1,a,u,array2,b,y);
        break;
        case 2:
        matrixSub(array1,a,u,array2,b,y);
        break;
        case 3:
        matrixMul(array1,a,u,array2,b,y);
        break;
        case 4:
        matrixTranspose(array1,a,u,array2,b,y);
        break;
        case 5:
        matrixDisplay(array1,a,u,array2,b,y);
        break;
    }
    printf("*");
}

void matrixInput(int c[][3],int a, int u,int d[][3],int b,int y){
    
    printf("please enter the values of first array:");
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    scanf(" %d",&c[m][n]);
    }
    }
    printf("\nplease enter the values of second array:");
    for(int m=0;m<b;m++){
    for(int n=0;n<3;n++){
    scanf(" %d",&d[m][n]);
    }
    }
}
void matrixAdd(int c[][3],int a, int u,int d[][3],int b,int y){
    if(a==b){
    int array3[a][3];
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    array3[m][n]=c[m][n]+d[m][n];
    }
    }
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    printf("array3[%d][%d]=%d",m,n,array3[m][n]);
    }
    puts("\n");
    }
    }
    else printf("INVALID MATRICES FOR ADDITION.");
}
void matrixSub(int c[][3],int a, int u,int d[][3],int b,int y){
    if(a==b){
    int array3[a][3];
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    array3[m][n]=c[m][n]-d[m][n];
    }
    }
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    printf("array3[%d][%d]=%d",m,n,array3[m][n]);
    }
    puts("\n");
    }
    }
    else printf("INVALID MATRICES FOR SUBTRACTION.");

}
void matrixMul(int c[][3],int a, int u,int d[][3],int b,int y){
    if(b==3&&a<3){
    int hold[b][3];
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
   hold[m][n]=c[m][n]*d[m][n];
    }
    }
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    printf("hold[%d][%d]=%d",m,n,hold[m][n]);
    }
    puts("\n");
    }
    }
    if(b==3&&a>=3){
    int hold[a][3];
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
   hold[m][n]=c[m][n]*d[m][n];
    }
    }
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    printf("hold[%d][%d]=%d",m,n,hold[m][n]);
    }
    puts("\n");
    }
    }
    else{
    printf("Cannot proceed multiplication plaese enter valid arrays.\n");
    printf("Such that column number of first matrix is equal to row number of second array\n");
    }
}
void matrixTranspose(int c[][3],int a, int u,int d[][3],int b,int y){
    int say;
    printf("Enter the number of array which you want to transpose:");
    scanf("%d",&say);
    if(say==1){
    int array3[3][a];
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    array3[m][n]=c[n][m];
    printf("%d ",array3[m][n]);
    }
    puts("\n");
    }
    }
    if(say==2){
    int array3[3][b];
    for(int k=0;k<b;k++){
    for(int l=0;l<3;l++){
    array3[k][l]=d[l][k];
    printf("%d ",array3[k][l]);
    }
    puts("\n");
    }
    }
    }
void matrixDisplay(int c[][3],int a, int u,int d[][3],int b,int y){
    int say;
    printf("Enter the number of array which you want to display:");
    scanf("%d",&say);
    switch(say){
    case 1:
    for(int m=0;m<a;m++){
    for(int n=0;n<3;n++){
    printf("%d ",c[m][n]);
    }
    puts("\n");
    }
    break;
    case 2:
    for(int k=0;k<b;k++){
    for(int l=0;l<3;l++){
    printf("%d ",d[k][l]);
    }
    puts("\n");
    }
    break;
    }
}
