#include<cstdio>
#include<cstdlib>
#include<cstring>
#define vc(n) c[(n)+13]
using namespace std;

bool a[28],b[40],c[40];
int ans=0,n;
int d[29];

void dfs(int k)
{
	if (k==n+1)
	{
		ans++;
		if (ans<=3)
		{
			for (int i=1;i<=n-1;i++)
				printf("%d ",d[i]);
			printf("%d\n",d[n]);
		}
	}
	for (int i=1;i<=n;i++)
		if (!a[i]&&!b[k+i]&&!vc(k-i))
		{
			d[k]=i;a[i]=true;b[k+i]=true;vc(k-i)=true;
			dfs(k+1);
			a[i]=false;b[k+i]=false;vc(k-i)=false;
		}
}

int main()
{
	int i;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
