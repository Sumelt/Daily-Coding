/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <stdio.h>
typedef struct info{
	char name[11];
	char number[11];
	short socore;
}stu;

int main(int argc, char *argv[])
{
	stu student[2];
	stu temp;
	short count,flag;
	short i=0,j=0;
	scanf("%d",&count);
	flag = count;
	getchar();
	while(count!=0)
	{	

		while((temp.name[j]=getchar())!=' ')
			j++;
		temp.name[j] = '\0';
		j = 0;
		while((temp.number[j]=getchar())!=' ')
			j++;
		temp.number[j] = '\0';
		j = 0;
		scanf("%d",&temp.socore);
		getchar();

		if(count==flag)
		{
			student[0]=temp;
			student[1]=temp;
		}
		if(student[0].socore<temp.socore)
			student[0] = temp;
		if(student[1].socore>temp.socore)
			student[1] = temp;
		count--;
	}
		printf("%s %s\n",student[0].name,student[0].number);
		printf("%s %s\n",student[1].name,student[1].number);
	return 0;
}

