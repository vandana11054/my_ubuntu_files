#include<stdio.h>
#include<stdlib.h>
#include<time.h>


    void bingocard(int n11,int n12,int n13,int n21,int n22,int n23,int n31,int n32,int n33,char s11,char s12,char s13,char s21,char s22,char s23,char s31,char s32,char s33)
    {
	printf("%2c%2d%2c\t%2c%2d%2c\t%2c%2d%2c\t\n",s11,n11,s11,s12,n12,s12,s13,n13,s13);
	printf("%2c%2d%2c\t%2c%2d%2c\t%2c%2d%2c\t\n",s21,n21,s21,s22,n22,s22,s23,n23,s23);
	printf("%2c%2d%2c\t%2c%2d%2c\t%2c%2d%2c\t\n",s31,n31,s31,s32,n32,s32,s33,n33,s33);
    }


   int generate(int a)
   {
	a=(1+rand()%30);
	return a;
   }
	
	
int main()
{
	int n11,n12,n13;char s11,s12,s13;
	int n21,n22,n23;char s21,s22,s23;
	int n31,n32,n33;char s31,s32,s33;
	int a,b,c;
	char d;
	for(int z=1;z==1;)
	{
	   n11=(1+rand()%10),s11=' ';
	         n21=(1+rand()%10),s21=' ';
		 n31=(1+rand()%10),s31=' ';
	   while(n11==n21 || n21==n31 || n11==n31)
	   {
		n11=(1+rand()%10);
		n21=(1+rand()%10);
		n31=(1+rand()%10);
	   }
		n12=(11+rand()%10),s12=' ';
		n22=(11+rand()%10),s22=' ';
		n32=(11+rand()%10),s32=' ';
	   while(n12==n22 || n22==n32 || n12==n32)
	   {
		n12=(11+rand()%10);
		n22=(11+rand()%10);
		n32=(11+rand()%10);
	   }
		n13=(21+rand()%10),s13=' ';
		n23=(21+rand()%10),s23=' ';
		n33=(21+rand()%10),s33=' ';
		while(n13==n23 || n23==n33 || n13==n33)
		{
		n13=(21+rand()%10);
		n23=(21+rand()%10);
		n33=(21+rand()%10);
		}

		bingocard(n11,n12,n13,n21,n22,n23,n31,n32,n33,s11,s12,s13,s21,s22,s23,s31,s32,s33);
		printf("Enter -1 to start Generating Numbers:\n");
		scanf("%d",&b);
		for(int j=1;j==1;)
		{
		c=generate(a);
		printf("Enter any character to produce a number\n");
		scanf("  %c",&d);
		for(int i=1;i==1;)
		{
		switch(b)
		{
		case -1:
		printf("The Number produced is %d\n",c);
		i=0;
		if (c==n11)
		{
		s11='*';
		}
		if (c==n12)
		{
		s12='*';
		}
		if (c==n13)
		{
		s13='*';
		}
		if (c==n21)
		{
		s21='*';
		}
		if (c==n22)
		{
		s22='*';
		}
		if (c==n23)
		{
		s23='*';
		}
		if (c==n31)
		{
		s31='*';
		}
		if (c==n32)
		{
		s32='*';
		}
		if (c==n33)
		{
		s33='*';
		}
		bingocard(n11,n12,n13,n21,n22,n23,n31,n32,n33,s11,s12,s13,s21,s22,s23,s31,s32,s33);
		if(s11=='*'&&s12=='*'&&s13=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking Row 1\n");
		}
		if(s21=='*'&&s22=='*'&&s23=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking Row 2\n");
		}
		if(s31=='*'&&s32=='*'&&s33=='*')
		{
		j=0;
		printf("Congratulation You Won\n");
		printf("You have Completed Marking Row 3\n");
		}
		if(s11=='*'&&s21=='*'&&s31=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking Column 1\n");
		}
		if(s12=='*'&&s22=='*'&&s32=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking Column 1\n");
		}
		if(s13=='*'&&s23=='*'&&s33=='*')
		{
		j=0;
		printf("Congratulation You Won\n");
		printf("You have Completed Marking Column 1\n");
		}
		if(s11=='*'&&s22=='*'&&s32=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking a Diagnol\n");
		}
		if(s31=='*'&&s22=='*'&&s13=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking a Diagnol\n");
		}
		if(s11=='*'&&s13=='*'&&s31=='*'&&s33=='*')
		{
		j=0;
		printf("Congratulation You Won\a\n");
		printf("You have Completed Marking Four Corners\n");
		}
		break;
		default:
		printf("Enter -1 to start generating numbers\n");
		scanf("%d",&b);

		}
}
}
printf("If You Want to Continue Playing the Game Then Enter 1\n");
scanf("  %d",&z);
}
}

