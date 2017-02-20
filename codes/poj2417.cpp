#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#define LL long long
using namespace std;

LL pow_mod(LL a,LL b,LL n)
{
  LL ans=1,t=a%n;
  while(b)
  {
    if (b&1)  ans=ans*t%n;
    b=b>>1;
    t=t*t%n;
  }
  return ans;
}

LL log_mod(LL a,LL b,LL n)
{
  LL e=1,m,i,v;
  m=(LL)ceil(sqrt(n+0.5));
  v=pow_mod(a,n-m-1,n);
  map<LL,LL> x;
  x[1]=m;
  for (i=1;i<m;i++)
  {
    e=e*a%n;
    if (!x[e])
      x[e]=i;
  }
  for (i=0;i<m;i++)
  {
    if (x[b])
    {
      LL num=x[b];
      x.clear();
      return i*m+(num==m?0:num);
    }
    b=b*v%n;
  }
  return -1;
}

int main()
{
  freopen("2417.in","r",stdin);
  freopen("2417.out","w",stdout);
  LL ans,n,a,b;
  while(scanf("%I64d%I64d%I64d",&n,&a,&b)==3)
  {
    ans=log_mod(a,b,n);
    if (ans==-1)
      printf("no solution\n");
    else 
      printf("%I64d\n",ans);
  }
  return 0;
}
