#include<cstdio>
#include<cstring>
using namespace std;

bool a[20004];

int main()
{
	int n,v,i,j;
	scanf("%d%d",&v,&n);
	a[0]=true;
	for (i=1;i<=n;i++)
	{
		int vi;
		scanf("%d",&vi);
		for (j=v;j>=vi;j--)
			a[j]=a[j]||a[j-vi];
	}
	for (i=v;i>=0;i--)
		if (a[i])
		{
			printf("%d\n",v-i);
			return 0;
		}
}
