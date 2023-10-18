 //Simulating a BANK ACCOUNT.
 
 
 #include<stdio.h>

float  deposit(float);
float withdraw(float);
float displayBalance(float);
int  displayTransactionCount(int);
int transaction(void);

float balance=1000.00;                    //intial bank balance.
float amount=0.00;
int count;                                // variable for number of transactions.

int main(){
int choice;
while(1){                                 //termination of program is user friendly.
printf("\nBank Account Simulation:\n");
printf("........................\n");
printf(" 1. Deposit\n 2. Withdraw\n 3. Display Balance\n 4. Display Transactin Count\n 5. Quit\n");    //display menu.
printf("Enter your choice:");
scanf("%d",&choice);                      //user's choice.

switch(choice){
case 1:
balance=deposit(amount);
break;
case 2:
balance=withdraw(amount);
break;
case 3:
balance=displayBalance(balance);
break;
case 4:
count=displayTransactionCount(count);
break;
case 5:
printf("Thank You.Exiting the program!");
break;
default:
break;
}
if (choice==5){
break;                               //quit bank simulation.
}
}
}
  
  int transaction(){                 //keeping count on transaction.
  static int count = 0;
  count++;
  return count;
  }
  
  float deposit(float amount){                     //function for depositing amount.
  printf("Enter the amount to deposit:");
  scanf("%f",&amount);
  balance=balance+amount;
  count=transaction();
  printf("Your balance is %f.",balance);
  return balance;
  }
  
  float withdraw(float amount){                    //function for withdrawing  amount.
  printf("Enter the amount to withdraw:");
  scanf("%f",&amount);
  balance=balance-amount;
  count=transaction();
  printf("Your balance is %f.",balance);
  return balance;
  }
  
  float displayBalance(float balance){            //function for checking current balance amount.
  printf("Your current balance is  %f.",balance);
  return balance;
  }
  
  int displayTransactionCount(int count){         //function to display number of transactions.
  printf("Total number of transactions made %d.",count);
  return count;
  }//END
