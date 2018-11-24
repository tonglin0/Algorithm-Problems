#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define lint long long
using namespace std;

lint dp[10][83][(1<<9)+3];
int st[(1<<9)+3];
int num[(1<<9)+3];

bool ok(int s)
{
  if (s&(s<<1))
    return false;
  if (s&(s>>1))
    return false;
  return true;
}

int get_num(int s)
{
  int ans=0;
  while(s)
  {
    ans+=(s&1);
    s>>=1;
  }
  return ans;
}

bool fit(int s1,int s2)
{
  if (s1&s2)
    return false;
  if (s1&(s2>>1))
    return false;
  if (s1&(s2<<1))
    return false;
  return true;
}

int main()
{
  freopen("1087.in","r",stdin);
  freopen("1087.out","w",stdout);
  int n,top=0,i,j,k,m;
  scanf("%d%d",&n,&m);
  int full=(1<<n)-1;
  for (i=0;i<=full;i++)
    if (ok(i))
    {
	  st[++top]=i;
	  num[top]=get_num(i);
    }
  memset(dp,0,sizeof(dp));
  int s;
  for (i=1;i<=top;i++)
  {
    s=st[i];
    dp[1][num[i]][s]=1;
  }
  for (i=2;i<=n;i++)
  {
    for (j=1;j<=top;j++)
    {
      s=st[j];
      for (k=num[j];k<=m;k++)
        for (int ii=1;ii<=top;ii++)
          if (fit(s,st[ii]))
            dp[i][k][s]+=dp[i-1][k-num[j]][st[ii]];
	}
  }
  lint ans=0;
  for (i=1;i<=top;i++)
    ans+=dp[n][m][st[i]];
  //printf("%I64d\n",ans);
  cout<<ans<<endl;
  return 0;
}
