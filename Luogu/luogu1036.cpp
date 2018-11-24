#include<cstdio>
#include<cmath>
using namespace std;

int a[24];
int n;
//bool vis[24];
int ans=0;

bool isprime(int x)
{
	int m=(int)(sqrt(x)+0.1);
	for (int i=2;i<=m;i++)
		if (x%i==0)
			return false;
	return true;
}

void work(int p,int k,int s,int t)
{
	if (p==n+1)
	{
		//if (t==k) printf("%d\n",s);
		if (t==k&&isprime(s))
			ans++;
		return ;
	}
	if (n-p+1<k-t) return ;
	work(p+1,k,s+a[p],t+1);
	work(p+1,k,s,t);
}

int main()
{
	int i,k;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//memset(vis,0,sizeof(vis));
	work(1,k,0,0);
	printf("%d\n",ans);
	return 0;
}

