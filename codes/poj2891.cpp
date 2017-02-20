#include<cstdio>
#include<cstdlib>
#include<cstring>
#define LL long long 
using namespace std;

LL x[401000],r[401000],a[400100];
bool flag;

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0)
  {
    d=a;x=1;y=0;
  }
  else
  {
    ex_gcd(b,a%b,d,y,x);y-=x*(a/b);
  }
}

int main()
{
  freopen("2891.in","r",stdin);
  freopen("2891.out","w",stdout);
  LL k,d,Y,M,n,i,j;
  while(scanf("%I64d",&n)==1)
  {
    flag=false;
    for (i=0;i<n;i++)
      scanf("%I64d%I64d",&a[i],&r[i]);
    x[0]=r[0];
    M=a[0];
    for (i=1;i<n;i++)
    {
      ex_gcd(M,a[i],d,k,Y);
      if ((r[i]-x[i-1])%d)
      {
        flag=true;
        break;
      }
      LL tmp=(r[i]-x[i-1])/d;
      LL b2=a[i]/d;
      k=(k%b2+b2)%b2;
      //k=(k%a[i]*tmp%a[i]+a[i])%a[i];
      k=(k*tmp%b2+b2)%b2;
      //std  k=(k%b2*tmp%b2+b2)%b2;
      x[i]=x[i-1]+k*M;
      M*=(a[i]/d);
    }
    if (flag)
      printf("-1\n");
    else
      printf("%I64d\n",x[n-1]);
  }
  return 0;
}
