/*----------------------------------------------------------------

* @Author: Su

* @Description: �����Դ���������ںþã�ģ���ֹ����� 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	char a[1001];
	int b;
	int len,i;
	int res = 0;
	bool flag = false;
	scanf("%s",a);
	scanf("%d",&b);
	len = strlen(a);
	for(i=0;i<len;i++)
	{
		res = a[i]-'0'+res*10;
		if(res>=b)
			printf("%d",res/b);
		else if(i!=0)
			{
				printf("0");  
				flag = true;  //�̲�����ʱ ,2/7 = 0
			}
		res = res%b;
	}
	if(!flag)
		printf("0");
	printf(" %d",res);
	return 0;
}

