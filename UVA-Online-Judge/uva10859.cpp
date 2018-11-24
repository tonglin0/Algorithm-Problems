#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define M 2000
using namespace std;

vector<int> g[1004];
bool vis[1003][2];
int dp[1003][2];

int find(int u,int pre,int d)
{
  if (vis[u][d])
    return dp[u][d];
  vis[u][d]=true;
  if (pre==0)
  {
    int s1=M;
    for (int i=0;i<g[u].size();i++)
      s1+=find(g[u][i],u,1);
    int s2=0;
    for (int i=0;i<g[u].size();i++)
      s2+=find(g[u][i],u,0);
    return dp[u][d]=min(s1,s2);
  }
  if (d==0)
  {
    dp[u][d]=M+1;
    for (int j=0;j<g[u].size();j++)
      if (g[u][j]!=pre)
        dp[u][d]+=find(g[u][j],u,1);
    return dp[u][d];
  }
  int s1=M;
  for (int i=0;i<g[u].size();i++)
    if (g[u][i]!=pre)
      s1+=find(g[u][i],u,1);
  int s2=1;
  for (int i=0;i<g[u].size();i++)
    if (g[u][i]!=pre)
      s2+=find(g[u][i],u,0);
  return dp[u][d]=min(s1,s2);
}

int main()
{
  freopen("10859.in","r",stdin);
  freopen("10859.out","w",stdout);
  int n,ca,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d",&n,&m);
    for (i=0;i<=n;i++)
      g[i].clear();
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      u++;v++;
      g[u].push_back(v);
      g[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	int ans=0;
	for (i=1;i<=n;i++)
	  if (!vis[i][0])
	    ans+=find(i,0,0);
	printf("%d %d %d\n",ans/M,m-ans%M,ans%M);
  }
  return 0;
}
