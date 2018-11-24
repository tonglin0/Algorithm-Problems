#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define lint long long
#define MOD 1000000007
using namespace std;

lint c[2009][2009];
lint fac[2009];

int main()
{
  freopen("11481.in","r",stdin);
  freopen("11481.out","w",stdout);
  lint T,ii=0,n,i,j,k,m;
  memset(c,0,sizeof(c));
  c[0][0]=1;
  for (i=1;i<=2002;i++)
  {
    c[i][0]=c[i][i]=1;
    for (j=1;j<i;j++)
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
  }
  fac[0]=1;
  for (i=1;i<=2002;i++)
    fac[i]=fac[i-1]*i%MOD;
  scanf("%lld",&T);
  for (ii=1;ii<=T;ii++)
  {
    printf("Case %lld: ",ii);
    scanf("%lld%lld%lld",&n,&m,&k);
    lint ans=0;
    lint h=m-k;
    for (i=0;i<=h;i++)
      if (i&1)
        ans=((ans-c[h][i]*fac[n-k-i]%MOD)%MOD+MOD)%MOD;
      else 
        ans=(ans+c[h][i]*fac[n-k-i]%MOD)%MOD;
    ans=(c[m][k]*ans%MOD+MOD)%MOD;
    printf("%lld\n",ans);
  }
  return 0;
}
