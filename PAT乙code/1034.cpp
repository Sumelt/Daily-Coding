/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 08/09/18 14:54

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include<cstdio>

using namespace std;

typedef struct fraction{
	long up;
	long down;
	
} fractions;

typedef struct symbol{
	char op;
}symbols;

symbols nop;

int gcd(long a, long b)
{
//	if(b==0) return a;
//	else gcd(b,a%b);
	return !b? a:gcd(b,a%b); 
}

fractions reduction(fractions res)
{
	if(res.down<0)
	{
		res.down *=-1;
		res.up *=-1; 
	}
	else if(res.up==0)
	{
		res.down = 1;
	}

	else if(res.down!=0)
	{
		int d = gcd(abs(res.up),abs(res.down));
		res.up /=d;
		res.down /=d;
	}
	return res;
}

fractions add(fractions f1, fractions f2)
{
	fractions res;
	res.up = f1.up * f2.down + f1.down*f2.up;
	res.down = f1.down * f2.down;
	nop.op = '+';
	return reduction (res);
}

fractions minu(fractions f1, fractions f2)
{
	fractions res;
	res.up = f1.up * f2.down - f2.up * f1.down;
	res.down = f1.down * f2.down;
	nop.op = '-';
	return reduction (res);
}

fractions multi(fractions f1, fractions f2)
{
	fractions res;
	res.up = f1.up * f2.up;
	res.down = f1.down * f2.down;
	nop.op = '*';
	return reduction (res);
}

fractions divide(fractions f1, fractions f2)
{
	fractions res;
	
	res.up = f1.up * f2.down;
	res.down = f1.down * f2.up;
	nop.op = '/';
	return reduction (res);
}

void showres(fractions res)
{
	if(res.down == 1)
	{
		if(res.up<0) printf("(%ld)\n",res.up);
		else printf("%ld\n",res.up);
	 }
 	else if(res.down==0)
	  {
  		cout<<"Inf"<<endl;
  		exit(0);
  	}
	else if(abs(res.up)>res.down)
	{
		if(res.down<0||res.up<0)
			printf("(%ld %d/%d)\n",res.up/res.down, res.up%res.down*-1, res.down);
		else printf("%ld %d/%d\n",res.up/res.down, res.up%res.down, res.down);
	}		
	else{	
			int b = gcd(abs(res.up), abs(res.down));
			res.up /=b;
			res.down /=b;
			if(res.down<0||res.up<0)
				printf("(%ld/%ld)\n",res.up, res.down);
				else printf("%ld/%ld\n",res.up, res.down);
	} 	
}

void shownumb(fractions f1, fractions f2)
{
	if(abs(f1.up)>f1.down)
	{
		if(f1.up%f1.down==0)
		{
			if(f1.up<0||f1.down<0)
				printf("(%ld)",f1.up/f1.down);
				else printf("%ld",f1.up/f1.down);
		}
		
		else{
			if(f1.up<0||f1.down<0)
				printf("(%ld %d/%d)", f1.up/f1.down, f1.up%f1.down, f1.down);
				
			else printf("%ld %d/%d", f1.up/f1.down, f1.up%f1.down, f1.down);			
		}			
	}
	else 
	{
		if(f1.up==0)
			printf("0");
		else
		{
			if(f1.down==f1.up)
				printf("1");
			else if(f1.down%f1.up==0)
			{
				int a = gcd(f1.up,f1.down);
				f1.up /=a;
				f1.down /=a;
				
				if(f1.up<0||f1.down<0)
					printf("(%d/%d)", f1.up, f1.down);
				else printf("%d/%d", f1.up, f1.down);				
			}
			else
			{
				if(f1.up<0||f1.down<0)
					printf("(%d/%d)", f1.up, f1.down);
				else printf("%d/%d", f1.up, f1.down);
			}
			
		}	
	}
	
	printf(" %c ",nop.op);
	
	if(abs(f2.up)>f2.down)
	{
		if(f2.up%f2.down==0)
		{
			if(f2.up<0||f2.down<0)
				printf("(%ld)",f2.up/f2.down);
			else printf("%ld",f2.up/f2.down);
		}
		else 
		{
			if(f2.up<0||f2.down<0)			
				printf("(%ld %d/%d)", f2.up/f2.down, f2.up%f2.down, f2.down);									
			else printf("%ld %d/%d", f2.up/f2.down, f2.up%f2.down, f2.down);
		}			
	}
	else 
	{
		if(f2.up==0)
			printf("0");
		else
		{
			if(f2.down==f2.up)
				printf("1");
			else if(f2.down%f2.up==0)
			{
				int a = gcd(f2.up,f2.down);
				f2.up /=a;
				f2.down /=a;
				
				if(f2.up<0||f2.down<0)
					printf("(%d/%d)", f2.up, f2.down);
				else printf("%d/%d", f2.up, f2.down);
			}
			else
			{
				if(f2.up<0||f2.down<0)
					printf("(%d/%d)", f2.up, f2.down);
				else printf("%d/%d", f2.up, f2.down);
			}
			
		}			
	}
	printf(" = ");	
}

int main(int argc, char *argv[])
{
	string str;
	fractions f1, f2;
	
	scanf("%ld/%ld %ld/%ld",&f1.up,&f1.down,&f2.up,&f2.down);
	nop.op = '+';
	shownumb(f1, f2);
	showres(add(f1, f2));
	nop.op = '-';
	shownumb(f1, f2);
	showres(minu(f1, f2));
	nop.op = '*';
	shownumb(f1, f2);
	showres(multi(f1, f2));
	nop.op = '/';
	shownumb(f1, f2);
	showres(divide(f1, f2));
	return 0;
}
