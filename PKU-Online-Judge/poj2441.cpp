#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

bool map[23][23];
int dp[2][(1<<20)+3];

int count(int s)
{
  int ans=0;
  while(s)
  {
    ans+=(s&1);
    s>>=1;
  }
  return ans;
}

int main()
{
  freopen("2441.in","r",stdin);
  freopen("2441.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  memset(map,0,sizeof(map));
  for (i=1;i<=n;i++)
  {
    int v;
	scanf("%d",&k);
    while(k--)
    {
      scanf("%d",&v);
      v--;
	  map[i][v]=true;
	}
  }
  memset(dp[0],0,sizeof(dp[0]));
  dp[0][0]=1;
  int x=0;
  int s;
  int full=(1<<m)-1;
  for (i=1;i<=n;i++)
  {
    x^=1;
    memset(dp[x],0,sizeof(dp[x]));
    for (s=0;s<=full;s++)
      if (count(s)==i-1)
      for (j=0;j<m;j++)
        if ((!(s&(1<<j)))&&map[i][j])
          dp[x][s|(1<<j)]+=dp[x^1][s];
  }
  int ans=0;
  for (s=0;s<=full;s++)
    if (count(s)==n)
      ans+=dp[x][s];
  printf("%d\n",ans);
  return 0;
}
