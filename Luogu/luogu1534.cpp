#include<cstdio>
#include<cstring>
using namespace std;

int a[3003],b[3003];

int main()
{
	int x,y,n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i]=x+y;
	}
	memset(b,0,sizeof(b));
	for (i=1;i<=n;i++)
		b[i]=b[i-1]+a[i]-8;
	int ans=0;
	for (i=1;i<=n;i++)
		ans+=b[i];
	printf("%d\n",ans);
	//printf("%d\n",b[n]);
	return 0;
}
