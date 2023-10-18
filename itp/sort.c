//PROGRAM FOR SORTING NUMBERS IN ASCENDING ORDER.

#include<stdio.h>
#define SIZE 8
int a[SIZE];                                                     //array declaration.
void inputArray(int b[],int n);                                  //function declaration.
void bubbleSort(int b[],int n);
void displayArray(int b[],int n);

int main(){                                                      //main starts executing.
displayArray(a, SIZE );
return 0;
}

void inputArray(int b[],int n){                                 //function for input.
printf("Enter 8 values between -1000 and 1000:");
for(int v=0;v<SIZE;v++){
scanf(" %d",&a[v]);
}
printf("Your sequence is:");
for(int p=0;p<SIZE;p++){
printf(" %d,",a[p]);
}
}

void bubbleSort(int b[],int n){                                 //function for sorting into ascending order.
inputArray(a, SIZE );
for(int w=1;w<SIZE;++w){                                        //sink phenomena for largest numbers.
for(int r=0;r<SIZE-1;++r){                                      //for checking consecutive terms each time.
if(a[r]>a[r+1]){  //condition to be checked.
int hold=a[r];
a[r]=a[r+1];
a[r+1]=hold;
}
}
}
}

void displayArray(int b[],int n){                              //function to display output.
bubbleSort(a, SIZE );
printf("\n The sorted outcomes are:");
for(int s=0;s<SIZE;s++){
printf("%2d,",a[s]);
}
}
