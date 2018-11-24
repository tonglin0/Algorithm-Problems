#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
using namespace std;

bool map[16][16];
int w[15];
long long dp[(1<<13)+9][14][14];
long long way[(1<<13)+9][14][14];

int main()
{
  freopen("2288.in","r",stdin);
  freopen("2288.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d",&n,&m);
    memset(w,0,sizeof(w));
    for (i=0;i<n;i++)
      scanf("%d",&w[i]);
    memset(map,0,sizeof(map));
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      v--;u--;
      map[u][v]=map[v][u]=true;
	}
	for (i=0;i<n;i++)
	  map[i][i]=true;
	int full=(1<<n)-1;
	for (i=0;i<=full;i++)
	  for (j=0;j<=n;j++)
	    for (k=0;k<=n;k++)
	      dp[i][j][k]=-(int)1e13;
	for (i=0;i<n;i++)
	  dp[1<<i][i][i]=0;
	int s;
	memset(way,0,sizeof(way));
	for (i=0;i<n;i++)
	  way[1<<i][i][i]=1;
	for (s=1;s<=full;s++)
	  for (i=0;i<n;i++)
	    if (s&(1<<i))
	      for (j=0;j<n;j++)
	        if ((s&(1<<j))&&map[j][i])
	          for (k=0;k<n;k++)
	            if ((!(s&(1<<k)))&&map[i][k])
	            {
	              long long sum=w[i]*w[k];
	              if (i!=j&&map[j][k])
	                sum+=(long long)w[i]*w[j]*w[k];
	              if (dp[s][i][j]+sum>dp[s|(1<<k)][k][i])
	              {
	                dp[s|(1<<k)][k][i]=dp[s][i][j]+sum;
	                way[s|(1<<k)][k][i]=way[s][i][j];
				  }
				  else if (dp[s|(1<<k)][k][i]==dp[s][i][j]+sum)
				    way[s|(1<<k)][k][i]+=way[s][i][j];
				}
	long long ans=-1,ways=0;
	for (i=0;i<n;i++)
	  for (j=0;j<n;j++)
	    if (dp[full][i][j]>ans)
	    {
	      ans=(long long)dp[full][i][j];
	      ways=(long long)way[full][i][j];
		}
		else if (dp[full][i][j]==ans)
		  ways+=(long long)way[full][i][j];
	long long sum=0;
	for (i=0;i<n;i++)
	  sum+=(long long)w[i];
	if (ans==-1)
	  printf("0 0\n");
	else
	  printf("%I64d %I64d\n",ans+sum,(long long)((ways+(long long)1)>>(long long)1));
  }
  return 0;
}
