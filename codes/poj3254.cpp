#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MOD 100000000
using namespace std;

int dp[14][1<<13];
int st[1<<13];
int pre[1<<13];

bool ok(int x)
{
  if (x&(x<<1)) 
    return false;
  return true;
}

bool fit(int s,int i)
{
  if (s&pre[i])
    return false;
  return true;
}

int main()
{
  freopen("3254.in","r",stdin);
  freopen("3254.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  memset(dp,0,sizeof(dp));
  int top=0;
  for (i=0;i<(1<<m);i++)
    if (ok(i))
      st[++top]=i;
  for (i=1;i<=n;i++)
  {
    int t=0;
    for (j=1;j<=m;j++)
    {
      int d;
      scanf("%d",&d);
      if (d==0)
        t=t+(1<<(m-j));
    }
    pre[i]=t;
  }
  for (i=1;i<=top;i++)
    if (fit(st[i],1))
      dp[1][st[i]]=1;
  for (i=2;i<=n;i++)
    for (k=1;k<=top;k++)
      if (fit(st[k],i))
        for (j=1;j<=top;j++)
          if (fit(st[j],i-1))
            if (!(st[j]&st[k]))
              dp[i][st[k]]=(dp[i][st[k]]+dp[i-1][st[j]])%MOD;
  int ans=0;
  for (i=1;i<=top;i++)
    ans=(ans+dp[n][st[i]])%MOD;
  printf("%d\n",ans);
  return 0;
}
