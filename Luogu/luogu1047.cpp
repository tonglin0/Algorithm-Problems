#include<cstdio>
using namespace std;

bool a[10005];

int main()
{
	int n,i,l,r,m;
	scanf("%d%d",&m,&n);
	for (i=0;i<=m;i++)
		a[i]=true;
	while(n--)
	{
		scanf("%d%d",&l,&r);
		for (i=l;i<=r;i++)
			a[i]=false;
	}
	int ans=0;
	for (i=0;i<=m;i++)
		if (a[i])
			ans++;
	printf("%d\n",ans);
	return 0;
}
