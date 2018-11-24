#include<cstdio>
using namespace std;

int main()
{
	freopen("1426.in","r",stdin);
	freopen("1426.out","w",stdout);
	double s,x,a,b,d=0;
	scanf("%lf%lf",&s,&x);
	a=s-x;b=s+x;
	double d0=7.0;
	while(d<a)
	{
		d+=d0;
		d0*=0.98;
	}
	if (d+d0>b) printf("n\n");
		else printf("y\n");
	return 0;
}
