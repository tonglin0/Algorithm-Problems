#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 3005
#define INF (int)1e9
using namespace std;

int top;
int head[MN],next[MN],vi[MN],wi[MN];
int num[MN];
int dp[MN][MN];

void addedge(int u,int v,int w)
{
  vi[top]=v;
  wi[top]=w;
  next[top]=head[u];
  head[u]=top++;
}

void dfs(int u)
{
  for (int i=head[u];i!=-1;i=next[i])
  {
    int v=vi[i];
    dfs(v);
    for (int j=num[u];j>=0;j--)
      for (int k=num[v];k>=0;k--)
        dp[u][j+k]=max(dp[u][j+k],dp[u][j]+dp[v][k]-wi[i]);
    num[u]+=num[v];
  }
}

int main()
{
  freopen("1155.in","r",stdin);
  freopen("1155.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  top=0;
  memset(head,-1,sizeof(head));
  for (i=1;i<=n-m;i++)
  {
    scanf("%d",&k);
    while(k--)
    {
      int v,w;
      scanf("%d%d",&v,&w);
      addedge(i,v,w);
	}
	num[i]=0;
  }
  for (i=0;i<=n;i++)
    for (j=0;j<=m;j++)
      dp[i][j]=(j==0?0:-INF);
  for (i=n-m+1;i<=n;i++)
  {
    scanf("%d",&dp[i][1]);
    num[i]=1;
  }
  dfs(1);
  int ans;
  for (i=num[1];i>=0;i--)
    if (dp[1][i]>=0)
    {
      ans=i;
      break;
	}
  printf("%d\n",ans);
  return 0;
}
