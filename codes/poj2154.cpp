#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint int//long long
using namespace std;

lint phi[1000000];

lint phis(lint x)
{
  //return phi[abs(x)];
  lint ans=x;
  lint m=(lint)(sqrt(x+0.5));
  for (int i=2;i<=m;i++)
    if (x%i==0)
    {
      ans=ans/i*(i-1);
      while(x%i==0)
        x/=i;
    }
  if (x>1)
    ans=ans/x*(x-1);
  return ans;
}

lint pow_mod(lint a,lint b,lint c)
{
  a%=c;
  lint ans=1,t=a;
  while(b>0)
  {
    if (b&1) ans=ans*t%c;
    b=b>>1;
    t=t*t%c;
  }
  return ans;
}

int main()
{
  freopen("2154.in","r",stdin);
  freopen("2154.out","w",stdout);
  lint ans,p,n,i,j,k,m;
  int T;
  /*phi[1]=1;
  n=(lint)sqrt((lint)1000000001+0.5);
  for (i=2;i<=n;i++)
    phi[i]=0;
  for (i=2;i<=n;i++)
    if (!phi[i])
      for (j=i;j<=n;j+=i)
      {
        if (!phi[j])
          phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
      }
  k=n;*/
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&p);
    if (n==0)
    {
      printf("0\n");
      continue;
    }
    if (n==1)
    {
      printf("1\n");
      continue;
    }
    m=(lint)sqrt(n+0.5);
    ans=0;
    for (i=1;i<=m;i++)
      if (n%i==0)
      {
        lint t=pow_mod(n,i-1,p);
        ans=(ans+(phis(n/i)%p*t))%p;
      }
    if (n>m)
      ans=(ans+pow_mod(n%p,n-1,p))%p;
    printf("%d\n",ans);
  }
  return 0;
}
