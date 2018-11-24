#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define lint long long
using namespace std;

lint f[100010];

void get_fact(lint p)
{
  f[0]=1;
  for (int i=1;i<=p;i++)
    f[i]=f[i-1]*i%p;
}

lint pow_mod(lint a,lint b,lint c)
{
  lint ans=1,t=a%c;
  while(b)
  {
    if (b&1) ans=ans*t%c;
    b=b>>1;
    t=t*t%c;
  }
  return ans;
}

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

lint inv(lint a,lint n)
{
  lint x,y,d;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

lint lucas(lint n,lint m,lint p)
{
  lint a,b;
  lint ans=1;
  while(n&&m)
  {
    a=n%p;b=m%p;
    if (a<b) return 0;
    ans=ans*f[a]*inv(f[b]*f[a-b]%p,p)%p;//pow_mod(f[b]*f[a-b]%p,p-2,p)%p;
    n/=p;m/=p;
  }
  return ans;
}

int main()
{
  freopen("3037.in","r",stdin);
  freopen("3037.out","w",stdout);
  lint p,T,n,m;
  scanf("%I64d",&T);
  while(T--)
  {
    scanf("%I64d%I64d%I64d",&n,&m,&p);
    get_fact(p);
    printf("%I64d\n",lucas(n+m,n,p));
  }
  return 0;
}
