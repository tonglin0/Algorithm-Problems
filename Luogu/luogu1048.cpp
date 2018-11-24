#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1003];

int main()
{
	memset(a,0,sizeof(a));
	int n,v,j,i;
	scanf("%d%d",&v,&n);
	for (i=1;i<=n;i++)
	{
		int vi,wi;
		scanf("%d%d",&vi,&wi);
		for (j=v;j>=vi;j--)
			a[j]=max(a[j],a[j-vi]+wi);
	}
	printf("%d\n",a[v]);
	return 0;
}
