#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

LL phi[1000100];

int main()
{
  freopen("2478.in","r",stdin);
  freopen("2478.out","w",stdout);
  LL ans,n,m,i,j,k;
  memset(phi,0,sizeof(phi));
  n=1000000;
  m=(LL)sqrt(n+0.5);
  for (i=2;i<=n;i++)
    if (!phi[i])
      for (j=i;j<=n;j+=i)
      {
        if (!phi[j])
          phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
      }
  while(scanf("%I64d",&n)&&n)
  {
    ans=0;
    for (i=2;i<=n;i++)
      ans+=phi[i];
    printf("%I64d\n",ans);
  }
  return 0;
}
