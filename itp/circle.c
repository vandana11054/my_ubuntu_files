   
    //program to find the location of arbitrary point with respect to a circle.
   #include<stdio.h>
   #include<math.h>
   
   int a,b,r;
   int x,y,count=0;
   
   int circle(int x,int y){    //defining a function named circle.
   if( pow(x-a,2)+pow(y-b,2) < pow(r,2) ){
   printf(" (%d,%d) lies inside the circle.\n",x,y);
   count=count+1;
   }
   else  {
   printf(" (%d,%d) lies outside or on  the circle.\n",x,y);
   }
   }
   
   int main(){
   printf("Enter the x coordinate of  center of your circle:");     //fixing parameters of a circle.
   scanf("%d",&a);
   printf("Enter the y coordinate of center of  your circle:");
   scanf("%d",&b);
   printf("Enter the radius of your circle:");
   scanf("%d",&r);
   while(1){
       printf("Enter the x coordinate of any point:");             //taking required point as input from user.
       scanf("%d",&x);
       printf("Enter the y coordinate of any point:");
       scanf("%d",&y);
       circle(x,y);
       printf("Enter 4444 as y coordinate to stop.\n");
   if (y==4444){                                                   //terminating condition.
   break;
   }
   }
   printf("%d points are inside the circle.",count);               //number of points (given by user) lying inside circle.
   return 0;
   }
