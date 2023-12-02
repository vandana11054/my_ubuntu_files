

//CALCULATOR USING FUNCTION POINTERS.

#include<stdio.h>                                         
int fun(int a,int b,int (*func)(int ,int ));            //function that takes function pointer as argument. 
int add(int ,int );                                     //function for Addition.
int sub(int ,int );                                     //function for Subtraction.
int mul(int ,int );                                     //function for Multiplication.
int divi(int ,int );                                    //function for Division.
int main(void){
    int choice,a,b;
    int ans=0;
    printf("Required calculator operations:(enter 5 to exit)\n");
    printf("...MENU...\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division.\nEnter:");//DISPLAY MENU.
    scanf("%d",&choice);
    printf("enter values to be operated.");                                          
    scanf("%d %d",&a,&b);                                                            //Input values from user.  
if(choice==1){
    ans=fun(a,b,add);
    printf("ANSWER:%d",ans);
    }
else if(choice==2){
    ans=fun(a,b,sub);
    printf("ANSWER:%d",ans);
    }
else if(choice==3){
    ans=fun(a,b,mul);
    printf("ANSWER:%d",ans);
    }
else if(choice==4){
    ans=fun(a,b,divi);
    if(b!=0) printf("ANSWER:%d",ans);
    }
}
int add(int a,int b){
    return (a+b);
}
int sub(int a,int b){
    return (a-b);
}
int mul(int a,int b){
    return (a*b);
}
int divi(int a,int b){
    if(b!=0){
    return (a/b);
    }
    else printf("Enter non zero denominator.");
}
int fun(int a,int b,int (*func)(int ,int )){
return (*func)(a,b);                             //using function pointer to access function code.
}
