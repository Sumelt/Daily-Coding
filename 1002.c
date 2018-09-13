//
// Created by Melt on 2018/4/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void myprint(char n[], int leng);
int main( )
{
    char n ;
    int sum = 0;
    int count;
    char str[10];
	int i = 0;
    while ((n = getchar())!= '\n')
        sum+= n-'0';
    //itoa(temp,str,10);
    for(sum; sum != 0;)
    {
    	str[i] = (sum%10)+'0';
    	sum /=10;
    	i++;
    }
    str[i] = '\0';
    count = strlen(str);
    myprint(str,count);
    return 0;
}

void myprint(char n[], int leng)
{
    int i = leng;
    while (i>=0)
    {
        switch(n[i])
        {
            case '0': printf("ling");break;
            case '1': printf("yi");break;
            case '2': printf("er");break;
            case '3': printf("san");break;
            case '4': printf("si");break;
            case '5': printf("wu");break;
            case '6': printf("liu");break;
            case '7': printf("qi");break;
            case '8': printf("ba");break;
            case '9': printf("jiu");break;
        }
        if(i>0&&i!=leng)
            printf(" ");
        i--;
    }

}
