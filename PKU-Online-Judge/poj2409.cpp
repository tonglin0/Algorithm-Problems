#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint f[40];

lint gcd(lint a,lint b)
{
  lint t;
  while(b)
  {
    t=a;
    a=b;
    b=t%b;
  }
  return a;
}

int main()
{
  freopen("2409.in","r",stdin);
  freopen("2409.out","w",stdout);
  lint n,i,j,k,m,c,s;
  while(scanf("%I64d%I64d",&c,&s)==2&&(c+s))
  {
    f[0]=1;
    for (i=1;i<=s;i++)
      f[i]=c*f[i-1];
    lint ans=0,n=s<<1;
    for (i=0;i<=s-1;i++)
      ans=ans+f[gcd(i,s)];
    if (s&1==1)
      ans+=(s*f[(s+1)>>1]);
    else
      ans+=((s>>1)*f[s>>1]+(s>>1)*f[(s>>1)+1]);
    printf("%I64d\n",ans/n);
  }
  return 0;
}
