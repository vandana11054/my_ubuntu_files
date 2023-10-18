// code to Temperature conversion.

#include<stdio.h>
int main()
{
int fahrenheit1,fahrenheit2; 
printf("Enter the value of starting fahrenheit temperature:(in integers)\n");
scanf("%d",&fahrenheit1); //takes fahrenheit starting input.
printf("Enter the value of ending fahrenheit temperature:(in integers)\n");
scanf("%d",&fahrenheit2); //takes fahrenheit ending input.

for( int i=fahrenheit1; i<=fahrenheit2 ;i++){ //calculates temperature conversion and displays table.
 float Celsius = (float) ((i) -32) * 5/9;
 float Kelvin = (float)(Celsius + 273.15);
 printf("  Fahrenheit:%d\tCelsius:%f\t Kelvin:%f\t\n",i,Celsius,Kelvin);
}
return 0;
}
