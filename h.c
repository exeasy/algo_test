#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
unsigned int prime[1024*1024];
#define SET_BIT_Y(x) prime[x/32] |= 1<<(x%32)
#define SET_BIT_N(x) prime[x/32] &= ~(1<<(x%32))
#define GET_BIT(x) (prime[x/32]>>(x%32))&1

int precompute(unsigned int max)
{
	if( max == 2)
	{/* code */
		SET_BIT_Y(2);
		SET_BIT_Y(1);
		return 0;
	}
	precompute((int)sqrt((float)max));
	for(int i = 2 ; i <= (int)sqrt((float)max); i ++)
	{
		if ( GET_BIT(i) == 1 )
		{
			for ( int j = 2 ; j <= max/i ; j++)
			{
				int k = i*j;
				SET_BIT_N(k);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int t = 0;
	scanf("%d",&t);
	memset(prime, 0xFF, 1024*1024*sizeof(int));
	precompute(1024*64);
//	for(int i = 0 ; i< 100;i ++)
//	{
//		if( GET_BIT(i)==1)
//			printf("%d\n",i);
//	}
//	printf("%d\n",GET_BIT(2));
	for(int i  = 0; i< t ;i++)
	{
		unsigned int min ,max;
		scanf("%d %d",&min,&max);
		int max_len = 0, min_len = max-min;
		int first = 0;
		int dis = 0;
		int max_i,max_j,min_i,min_j;
		int flag = 0 ;
		for(int i =  min ; i<= max ; i++)
		{
			int k = i;
			if(first == 0 && GET_BIT(k))
			{
				first = i;
			}
			else if( first != 0 && GET_BIT(k))
			{
				flag= 1;
				dis = i - first;
				if( dis > max_len)
				{
					max_len  = dis;
					max_i = first;
					max_j = i;
				}
				if ( dis < min_len)
				{
					min_len = dis;
					min_i = first;
					min_j = i;
				}
//				printf("%d\n",min_len);
				first = i;
			}
		}
		if (flag == 0)
			printf("-1\n");
		else
		printf("%d %d %d %d\n",min_i,min_j,max_i,max_j);
	}
	return 0;
}
