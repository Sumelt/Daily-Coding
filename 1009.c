/*----------------------------------------------------------------

* @Author: Su

* @Description: 采用了指针写法，方法繁琐，目的训练指针熟练度 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char word[85];
	char* begin,*end,*flag;
	int i = 0;
	int length = 0;
	while((word[i] = getchar())!='\n')
		i++;
	word[i] = '\0';
	length = strlen(word);
	end = word+length;
	begin = end;
	while(begin>word&&flag!=word)
	{
		while(*begin!=' '&&begin>word)
			begin--;
		if(begin==word)
		{
			flag = word;
		}
		if(begin>word)
		{
			flag = begin;
			begin++;
		}
					
		while(begin<end)
		{
			printf("%c",*begin);
			begin++;
		}
		if(begin>word&&flag!=word)
		{
			end = flag;
			begin = end-1;
			printf("%c",*end);
		}		
	}
	return 0;
}

