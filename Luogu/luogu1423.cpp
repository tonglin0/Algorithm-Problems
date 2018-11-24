#include<cstdio>
using namespace std;

int main()
{
	double s=0,tmp=2.0;
	double ta;
	int n,i,ans;
	scanf("%lf",&ta);
	for (i=1;s<=ta;i++)
	{
		s+=tmp;
		tmp*=0.98;
	}
	printf("%d\n",i-1);
	return 0;
}
