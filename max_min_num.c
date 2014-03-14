#include <stdio.h>

int maxmin_cpt(int *a, int len, int* max, int* min)
{
	*max = 0-9999;
	*min = 9999;
	int i  =0;
	for(i = 0; i < len ; i = i+2 )
	{
		if( a[i] < a[i+1] )
		{
			if( a[i+1] > *max )
				*max = a[i+1];
			if ( a[i] < *min)
			{
				*min = a[i];
			}
		}
		else
		{
			if( a[i] > *max )
				*max = a[i];
			if ( a[i+1] < *min)
				*min = a[i+1];
		}
	}
	if ( i == len)
	{
		if( a[len-1] > *max)
			*max = a[len-1];
		if ( a[len-1] < *min)
			*min = a[len-1];
	}
}

int main(int argc, const char *argv[])
{
	int s[8] = { 1, 9 , 3, 5, 2 ,6 ,10 ,99 };
	int max,min;
	maxmin_cpt(s,8,&max,&min);
	printf("%d %d\n",max,min);
	return 0;
}
