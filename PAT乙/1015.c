/*----------------------------------------------------------------

* @Author: Su

* @Description: 吐血 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stdus{
	unsigned long numb;
	int desc;
	int caisc;
	int num;
}stdu;
int mycomp(const void * p1, const void * p2);
int main(int argc, char *argv[])
{
	unsigned long count;
	int low,heg;
	long number;
	int i = 0;
	scanf("%ld %d %d%",&count,&low,&heg);
	stdu students[count];
	stdu students1[100];int j = 0;
	stdu students2[100];int k = 0;
	stdu students3[100];int q = 0;
	stdu students4[100];int t = 0;
	stdu students5[100];int w = 0;
	while(count-->0)
	{
		scanf("%lu %d %d",&students[i].numb,&students[i].desc,
		&students[i].caisc);
		if(students[i].desc>=low&&students[i].caisc>=low)
		{
			students[i].num = students[i].desc+students[i].caisc;
			i++;
		}
					
	}
	count = i;
	printf("%d\n",count);
	/*count = i;
	for(i=0;i<count;i++)
		printf("%ld %d %d\n",students[i].numb,students[i].desc,students[i].caisc);
	*/
	for(i=0;i<count;i++)
	{
		if(students[i].desc>=heg&&students[i].caisc>=heg)
		{
			students1[j++] = students[i];
		}
		else if(students[i].desc>=heg&&students[i].caisc<heg)
		{
			students2[k++] = students[i];
			//printf("%lu \n",students2)
		}
		else if(students[i].desc<heg&&students[i].caisc<heg)
		{
			if(students[i].desc>students[i].caisc)
				students3[q++] = students[i];
			else
			    students4[t++] = students[i];
		}
		else
		{
			students5[w++] = students[i];
		}
	}
	if(j>0)
	{
		//printf("********1\n");
		//printf("%d\n",j);
		qsort(&students1,j,sizeof(struct stdus),mycomp);
		for(i=0;i<j;i++)
		printf("%lu %d %d\n",students1[i].numb,students1[i].desc,
		students1[i].caisc);
	}
	
	if(k>0)
	{
		//printf("********2\n");
		//printf("%d\n",k);
		qsort(&students2,k,sizeof(struct stdus),mycomp);
		for(i=0;i<k;i++)
		printf("%lu %d %d\n",students2[i].numb,students2[i].desc,
		students2[i].caisc);
	}
	
	
	if(q>0)
	{
		//printf("********3\n");
		//printf("%d\n",q);
		qsort(&students3,q,sizeof(struct stdus),mycomp);
		for(i=0;i<q;i++)
		printf("%lu %d %d\n",students3[i].numb,students3[i].desc,
		students3[i].caisc);	
	}
	if(t>0)
	{
		//printf("********4\n");
		//printf("%d\n",t);
		qsort(&students4,t,sizeof(struct stdus),mycomp);
		for(i=0;i<t;i++)
		printf("%lu %d %d\n",students4[i].numb,students4[i].desc,
		students4[i].caisc);
	}
	if(w>0)
	{
		//printf("********5\n");
		//printf("%d\n",w);
		qsort(&students5,w,sizeof(struct stdus),mycomp);
		for(i=0;i<w;i++)
		{
			
		}
		printf("%lu %d %d\n",students5[i].numb,students5[i].desc,
		students5[i].caisc);
	}
	return 0;
}

/* sort by increasing value */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values   */
    const stdu * a1 = (const stdu *) p1; 
    const stdu * a2 = (const stdu *) p2;//需要强制转换成指定的排序类型

    if (a1->num > a2->num)   //这里改变排序顺序，<小到大，>大到小。负数放前面->小到大
        return -1;
    else if (a1->num == a2->num)
    {
    	if(a1->desc>a2->desc)
    		return -1;
   		else if(a1->desc==a2->desc)
				if(a1->numb>a2->numb)
					return -1;
    }
        
    else return 1;
        
}
