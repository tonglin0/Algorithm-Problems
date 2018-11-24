#include<cstdio>
#include<cstring>
using namespace std;

int ans=0;
bool vis[2003];
int a[2003];

void find(int n)
{
	if (vis[n])
	{
		ans+=a[n];
		return ;
	}
	int tmp=ans;
	ans++;
	for (int i=1;i<=n/2;i++)
		find(i);
	vis[n]=true;
	a[n]=ans-tmp;
}

int main()
{
	int n;
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	find(n);
	printf("%d\n",ans);
	return 0;
}
