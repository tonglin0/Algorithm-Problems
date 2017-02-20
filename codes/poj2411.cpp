#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

bool ok[(1<<11)+9];
long long dp[13][(1<<11)+9];
int m;

bool check(int s)
{
  int t=0;
  while(s)
  {
    if (s&1)
      t++;
    else
    {
      if (t&1)
        return false;
      t=0;
    }
    s>>=1;
  }
  if (t&1)
    return false;
  return true;
}

bool check2(int s1,int s2)
{
  if ((s1|s2)!=(1<<m)-1)
    return false;
  return ok[s1&s2];
}

int main()
{
  freopen("2411.in","r",stdin);
  freopen("2411.out","w",stdout);
  int n,i,j,k;
  int s;
  for (s=0;s<(1<<11);s++)
    if (check(s))
      ok[s]=true;
    else
      ok[s]=false;
  while(scanf("%d%d",&n,&m)==2&&(n+m))
  {
    if (n<m)
      swap(n,m);
    if ((n&1)&&(m&1))
    {
      printf("0\n");
      continue;
    }
    memset(dp,0,sizeof(dp));
    for (s=0;s<(1<<m);s++)
      if (ok[s])
        dp[1][s]=1;
    for (i=2;i<=n;i++)
      for (int s1=0;s1<(1<<m);s1++)
        for (int s2=0;s2<(1<<m);s2++)
          if (check2(s1,s2))
            dp[i][s1]+=dp[i-1][s2];
    printf("%I64d\n",dp[n][(1<<m)-1]);
  }
  return 0;
}
