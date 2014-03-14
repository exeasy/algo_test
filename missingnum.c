#include <stdio.h>

int output(int *a, int len)
{
	int s = (1+len)*len/2;
	for(int i = 0; i < len; i++ )
		s -= a[i];
	return s;
}

int main(int argc, const char *argv[])
{
	int num[10] = { 1,2,3,4,5,7,8,9,10};
	int missing = output(num,10);
	printf("%d\n",missing);
	return 0;
}
