

//bubble sort using PASS BY REFERENCE.

#include<stdio.h>
void bubbleSort(int *a,int n);
int main(void){
    int num;
    printf("Enter number of elements which are to be sorted:");
    scanf("%d",&num);                       //user defines the number of elements to be sorted.
    int arr[num];                           //Declaring an array to contain elements.
    printf("enter the values:");            //prompt for input of elements from user.
    for(int i=0;i<num;i++){                 //loop for taking input from user.
    scanf(" %d",&arr[i]);
    }
     bubbleSort(&arr[0],num);               //function call for bubble sort.
     printf("The sorted outcomes are:");    //prompt for sorted outcomes.
     for(int t=0;t<num;t++){                //loop for printing sorted outcomes.
     printf(" %2d",arr[t]);                 
     }
}
void bubbleSort(int *a,int n){
    int *ptr= *&a;                          //storing value at address of 1st element of array.
    for(int p=1;p<n;p++){                   //bubble sort algorithm using pointer variable.
    for(int r=0;r<n-1;r++){
    if(*(ptr+r)>*(ptr+r+1)){
    int hold=*(ptr+r);
    *(ptr+r)=*(ptr+r+1);
    *(ptr+r+1)=hold;
    }
    }
    }
}  
