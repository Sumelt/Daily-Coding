/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
typedef char* point;
void check(point);

int main(int argc, char *argv[])
{
	char arry[20];
	short n,i=0,j;
	scanf("%d",&n);
	getchar();
	arry[i++] = getchar();
	for(j = 0;j<n;j++)
	{
		while((arry[i++] = getchar())!='\n');
		arry[i-1] = '\0';
		check(arry);
		//printf("%s----\n",arry);
		i = 0;
	}
	return 0;
}

void check(point temp)
{
	point p = temp,t;
	point a = temp;;
	bool flag = 1;
	short count = 0;
	for(p;*p!='\0';p++)
	{
		if(*p == 'P')
		{
			while(a!=p)					//head adjust begin
			{
				if(*a=='A')
					{
						a++;
						count++;
					}
					else
					{
						flag = 0;
						printf("NO\n");
						return ;
					} 

			}					
			if(count==1)
			{
				printf("NO\n");
				return ;
			}							//head adjust end
								
			count = 0;
			t = p+1;
			for(t;*t!='\0';t++)
			{
				if(*t == 'T')			
				{
					a = t+1;
					while(*a!='\0')					//tail adjust begin
					{
							if(*a=='A')
						{
							a++;
							count++;
						}
						else
						{
							flag = 0;
							printf("NO\n");
							return ;
						} 

					}						
					if(count==1)
					{
						printf("NO\n");
						return ;
					}							//tail adjust end
									
					count = 0;
					a = p+1;			//middle adjust begin
					while(a!=t)
					{
						if(*a=='A')
							{
								a++;
								count++;
							}
						else 
						{	
							printf("NO\n");
							flag = 0;
							return ;
						}
					}				//middle adjust end
					if(count==0)
					{
						printf("NO\n");
						return ;
					}
					t--;               //t--,prevent 124 line result 
					if(flag)
						{
							printf("YES\n");
							return ;
						}
				}				
			}
		}
	}
	if(*p=='\0'||*t=='\0')
		printf("NO\n");	
}

