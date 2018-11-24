#include<cstdio>
#include<algorithm>
using namespace std;

int a[10003];

int main()
{
	int vi,n,i,v,j;
	scanf("%d%d",&n,&v);
	a[0]=1;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&vi);
		for (j=v;j>=vi;j--)
			a[j]+=a[j-vi];
	}
	printf("%d\n",a[v]);
	return 0;
}
