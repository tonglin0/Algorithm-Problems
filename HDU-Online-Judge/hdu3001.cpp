#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
using namespace std;

int dis[14][14];
int tri[14];
int dig[59069][14];
int dp[59069][14];

int main()
{
  freopen("3001.in","r",stdin);
  freopen("3001.out","w",stdout);
  int n,i,j,k,m;
  tri[0]=1;tri[1]=3;
  for (i=2;i<=11;i++)
    tri[i]=tri[i-1]*3;
  memset(dig,0,sizeof(dig));
  for (i=0;i<59060;i++)
  {
    k=i;
    for (j=0;j<=11&&k;j++)
    {
      dig[i][j]=k%3;
      k/=3;
	}
  }
  while(scanf("%d%d",&n,&m)==2)
  {
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        dis[i][j]=INF;
    while(m--)
    {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      u--;v--;
      if (w<dis[u][v])
        dis[u][v]=dis[v][u]=w;
	}
	for (i=0;i<n;i++)
	  dis[i][i]=0;
	for (i=0;i<tri[n];i++)
	  for (j=0;j<n;j++)
	    dp[i][j]=INF;
	for (j=0;j<n;j++)
	  dp[tri[j]][j]=0;
    for (j=0;j<tri[n];j++)
      for (i=0;i<n;i++)
        if (dig[j][i]>0)
          for (k=0;k<n;k++)
            if (dig[j][k]<2)
              dp[j+tri[k]][k]=min(dp[j+tri[k]][k],dp[j][i]+dis[i][k]);
    int ans=INF;
    for (j=1;j<tri[n];j++)
    {
      bool flag=true;
      for (i=0;i<n;i++)
        if (dig[j][i]==0){
          flag=false;break;}
      if (!flag)
        continue;
      for (i=0;i<n;i++)
        ans=min(ans,dp[j][i]);
	}
	if (ans==INF)
	  printf("-1\n");
	else
	  printf("%d\n",ans);
  }
  return 0;
}
