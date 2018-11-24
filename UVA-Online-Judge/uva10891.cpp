#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
#define s(i,j) (sum[j]-sum[i-1])
using namespace std;

int sum[104];
int dp[104][104];
bool vis[104][104];

int find(int a,int b)
{
  if (vis[a][b])
    return dp[a][b];
  vis[a][b]=true;
  if (a==b)
    return dp[a][b]=s(a,a);
  dp[a][b]=s(a,b);
  for (int i=a;i<b;i++)
    dp[a][b]=max(dp[a][b],s(a,i)+s(i+1,b)-find(i+1,b));
  for (int i=a+1;i<=b;i++)
    dp[a][b]=max(dp[a][b],s(i,b)+s(a,i-1)-find(a,i-1));
  return dp[a][b];
}

int main()
{
  freopen("10891.in","r",stdin);
  freopen("10891.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    sum[0]=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&sum[i]);
      sum[i]+=sum[i-1];
	}
	memset(vis,0,sizeof(vis));
	for (i=0;i<=n;i++)
	  for (j=0;j<=n;j++)
	    dp[i][j]=-INF;
	printf("%d\n",find(1,n)-(s(1,n)-find(1,n)));
  }
  return 0;
}
