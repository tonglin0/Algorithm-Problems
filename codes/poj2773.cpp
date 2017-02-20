#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;

LL gcd(LL a,LL b){if (b==0) return a;else return gcd(b,a%b);}
LL eular_phi(LL n)
{
  LL i,j,ans;
  ans=n;
  LL m=(LL)sqrt(n+0.5);
  for (i=2;i<=m;i++)
    if (n%i==0)
    {
      ans=ans/i*(i-1);
      while(n%i==0)n/=i;
    }
  if (n>1)
    ans=ans/n*(n-1);
  return ans;
}

int main()
{
  freopen("2773.in","r",stdin);
  freopen("2773.out","w",stdout);
  LL ans,n,m,k,phi,f,i,j;
  while(scanf("%I64d%I64d",&m,&k)==2)
  {
    phi=eular_phi(m);
    n=k/phi;
    f=k%phi;
    if (f==0)
    {
      f=phi;
      ans=-m;
    }
    else 
      ans=0;
    LL c=0;
    for (i=1;i<=m;i++)
      if (gcd(i,m)==1)
      {
        c++;
        if (c==f)
          break;
      }
    ans+=(i+n*m);
    printf("%I64d\n",ans);
  }
  return 0;
}
