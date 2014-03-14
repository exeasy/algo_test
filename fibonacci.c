#include <stdio.h>

int fibonacci(int n)
{
	if( n == 1 ) return 0;
	else if ( n < 4) return 1;
	int i = 3;
	int x = 0;
	int y = 1;
	for( ; i < n; i = i +2 )
	{
		x = x+y;
		y = x+y;
	}
	if(i == n)
		return x+y;
	else
		return y;
}

int main(int argc, const char *argv[])
{
	for(int i = 1; i< 20; i++)
	{
		int s = fibonacci(i);
		printf("%d\n",s);
	}
	return 0;
}
