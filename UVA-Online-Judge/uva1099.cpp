#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[17];
int sum[(1<<15)+5];
bool vis[104][(1<<15)+3];
bool dp[104][(1<<15)+4];
int num[(1<<15)+4];

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

bool find(int x,int s)
{
  if (vis[x][s])
    return dp[x][s];
  vis[x][s]=true;
  int y=sum[s]/x;
  int s0;
  if (num[s]==1)
    return dp[x][s]=true;
  for (s0=(s-1)&s;s0;s0=(s0-1)&s)
  {
    if (sum[s0]%x==0&&find(min(x,sum[s0]/x),s0)&&find(min(x,y-sum[s0]/x),s^s0))
      return dp[x][s]=true;
    if (sum[s0]%y==0&&find(min(y,sum[s0]/y),s0)&&find(min(y,x-sum[s0]/y),s^s0))
      return dp[x][s]=true;
  }
  return dp[x][s]=false;
}

int main()
{
  freopen("1099.in","r",stdin);
  freopen("1099.out","w",stdout);
  int ii=0,x,y,n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    scanf("%d%d",&x,&y);
    for (i=0;i<n;i++)
      scanf("%d",&a[i]);
    int full=(1<<n)-1;
    for (i=0;i<=full;i++)
    {
      sum[i]=0;
      for (j=0;j<n;j++)
        if (i&(1<<j))
          sum[i]+=a[j];
      num[i]=count(i);
	}
	if (sum[full]!=x*y)
	{
	  printf("Case %d: No\n",++ii);
	  continue;
	}
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	if (find(min(x,y),full))
	  printf("Case %d: Yes\n",++ii);
	else
	  printf("Case %d: No\n",++ii);
  }
  return 0;
}
