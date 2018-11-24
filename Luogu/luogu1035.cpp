#include<cstdio>
#define eps 1e-8
using namespace std;

int main()
{
	int i;
	double k,s;
	scanf("%lf",&k);
	s=0;
	i=1;
	for (;;)
	{
		s=s+1.0/i;
		if (s>k)
		{
			printf("%d\n",i);
			return 0;
		}
		i++;
	}
	return 0;
}
