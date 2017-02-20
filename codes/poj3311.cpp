#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
using namespace std;

int dis[12][12];
int dp[12][(1<<11)+5];

int main()
{
  freopen("3311.in","r",stdin);
  freopen("3311.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
  	++n;
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        scanf("%d",&dis[i][j]);
    for (k=0;k<n;k++)
      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int full=(1<<n)-1;
	for (i=0;i<n;i++)
      for (j=0;j<=full;j++)
        dp[i][j]=INF;
	dp[0][1]=0;
	for (j=1;j<=full;j++)
	  for (i=0;i<n;i++)
	    if (j&(1<<i))
	      for (k=0;k<n;k++)
	        if (!(j&(1<<k)))
	          dp[k][j|(1<<k)]=min(dp[k][j|(1<<k)],dp[i][j]+dis[i][k]);
	int ans=INF;
	for (i=0;i<n;i++)
	  if (dp[i][full]+dis[i][0]<ans)
	    ans=dp[i][full]+dis[i][0];
    printf("%d\n",ans);
  }
  return 0;
}
