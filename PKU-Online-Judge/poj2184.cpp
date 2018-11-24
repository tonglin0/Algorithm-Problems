#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define dp(i) f[i-s2]
using namespace std;

int f[300009];
int v[109],w[109];

int main()
{
  freopen("2184.in","r",stdin);
  freopen("2184.out","w",stdout);
  int s1=0,s2=0,n,i,j,k,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&v[i],&w[i]);
    if (v[i]>0)
      s1+=v[i];
    else
      s2+=v[i];
  }
  for (i=s2;i<=s1;i++)
    dp(i)=-(int)1e9;
  dp(0)=0;
  for (i=1;i<=n;i++)
    if (v[i]>0)
      for (j=s1;j>=s2+v[i];j--)
        dp(j)=max(dp(j),dp(j-v[i])+w[i]);
    else
      for (j=s2;j<=s1+v[i];j++)
        dp(j)=max(dp(j),dp(j-v[i])+w[i]);
  int ans=0;
  for (i=0;i<=s1;i++)
    if (dp(i)>=0)
      ans=max(ans,dp(i)+i);
  printf("%d\n",ans);
  return 0;
}
