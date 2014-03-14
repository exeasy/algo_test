#include <stdio.h>

void output(int * num, int len, int pos, int* temp,  int flag)
{
	if(pos==len)
	{
		for(int i = 0 ;i<len; i++)
			printf("%d",temp[i]);
		printf("\n");
		return;
	}
	int max =  0;
	if( flag == 1)
		max = num[pos];
	else
		max = 10;

	for(int i = 0; i< max;i ++)
	{
		temp[pos] = i;
		output(num, len, pos+1,temp, 0);
	}
	if( flag == 1)
	{
		temp[pos] = num[pos];
		output(num, len, pos+1, temp,1);
	}
}


int main(int argc, const char *argv[])
{
	int num[6] = {8,1,5,8,9,2};
	int temp[10];
	output(num,6,0,temp,1);
	return 0;
}
