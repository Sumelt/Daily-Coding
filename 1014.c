/*----------------------------------------------------------------

* @Author: Su

* @Description: 指针只指向一个字符的地址，哎，之前搞混淆了，白白花费时间 
一个上午也不能 AC 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void week(char);
void hours(char);
void delenter();

int main(int argc, char *argv[])
{
	char str1[61];
	char str2[61];
	char str3[61];
	char str4[61];
	int i,j;
	char temp;
	scanf("%s",str1);
	delenter;
	scanf("%s",str2);
	delenter;
	scanf("%s",str3);
	delenter;
	scanf("%s",str4);
	delenter;
	for(i=0;i<strlen(str1);i++)	
	{
		if(str1[i]>='A'&&str1[i]<='G')
		{
			for(j=0;j<strlen(str2);j++)
			{
				if(str2[j]>='A'&&str2[i]<='G')
				{
					if(str1[i]==str2[j])
					{
							week(str1[i]);
							temp = str1[i];
							break;
					}
				}
			}
			break;
		}
	}
	for(i=i+1;i<strlen(str1);i++)	
	{
		if(str1[i]>='0'&&str1[i]<='9'||str1[i]>='A'&&str1[i]<='N')
		{
			if(str1[i]!=temp)
			{
				for(j=j+1;j<strlen(str2);j++)
			  {
				if(str2[j]>='0'&&str2[j]<='9'||str2[j]>='A'&&str2[j]<='N')
				{
					if(str1[i]==str2[j])
					{
						hours(str1[i]);
						i = strlen(str1);
						break;
					}
				}
			  }
				j = 0;
			}			
		}
	}
	for(i=0,j=0;i<strlen(str3),j<strlen(str4);i++,j++)		
	{
		if(str3[i]>='a'&&str3[i]<='z'||str3[i]>='A'&&str3[i]<='Z')
		{
			if(str4[j]>='a'&&str4[j]<='z'||str4[j]>='A'&&str4[j]<='Z')
				if(str3[i]==str4[j])
					{
						printf("%02d",j);
						exit(0);
					}
		}
		
	}
	return 0;
}

void week(char day)
{
	char res[4]={0};
	switch(day)
	{
		case'A': strcpy(res,"MON");break;
		case'B': strcpy(res,"TUE");break;
		case'C': strcpy(res,"WED");break;
		case'D': strcpy(res,"THU");break;
		case'E': strcpy(res,"FRI");break;
		case'F': strcpy(res,"SAT");break;
		case'G': strcpy(res,"SUN");break;
	}
		printf("%s ",res);	
}

void hours(char hour)
{
	char res[3] = {0};
	switch(hour)
	{
		case '0': strcpy (res , "00");break;
		case '1': strcpy (res , "01");break;
		case '2': strcpy (res , "02");break;
		case '3': strcpy (res , "03");break;
		case '4': strcpy (res , "04");break;
		case '5': strcpy (res , "05");break;
		case '6': strcpy (res , "06");break;
		case '7': strcpy (res , "07");break;
		case '8': strcpy (res , "08");break;
		case '9': strcpy (res , "09");break;
		case 'A': strcpy (res , "10");break;
		case 'B': strcpy (res , "11");break;
		case 'C': strcpy (res , "12");break;
		case 'D': strcpy (res , "13");break;
		case 'E': strcpy (res , "14");break;
		case 'F': strcpy (res , "15");break;
		case 'G': strcpy (res , "16");break;
		case 'H': strcpy (res , "17");break;
		case 'I': strcpy (res , "18");break;
		case 'J': strcpy (res , "19");break;
		case 'k': strcpy (res , "20");break;
		case 'L': strcpy (res , "21");break;
		case 'M': strcpy (res , "22");break;
		case 'N': strcpy (res , "23");break;
	}
	if(res!=0)
		printf("%s:",res);
		else printf("00:");
}

void delenter()
{
	getchar();
}
