#include<cstdio>
#include<algorithm>
using namespace std;

int a[30004];

int main()
{
	int n,v,i,j,vi,wi;
	scanf("%d%d",&v,&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&vi,&wi);
		wi=vi*wi;
		for (j=v;j>=vi;j--)
			a[j]=max(a[j],a[j-vi]+wi);
	}
	printf("%d\n",a[v]);
	return 0;
}
