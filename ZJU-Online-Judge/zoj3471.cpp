#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
using namespace std;

int a[13][13];

int dp[(1<<11)+9];

int main()
{
  freopen("3471.in","r",stdin);
  freopen("3471.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    int s;
    for (s=0;s<=(1<<n);s++)
      dp[s]=0;
    for (s=0;s<(1<<n);s++)
      for (i=0;i<n;i++)
        if (!(s&(1<<i)))
          for (j=0;j<n;j++)
            if ((!(s&(1<<j)))&&i!=j)
              dp[s|(1<<j)]=max(dp[s|(1<<j)],dp[s]+a[i][j]);
    int ans=0;
    int full=(1<<n)-1;
    for (i=0;i<n;i++)
      ans=max(ans,dp[full^(1<<i)]);
    printf("%d\n",ans);
  }
  return 0;
}
