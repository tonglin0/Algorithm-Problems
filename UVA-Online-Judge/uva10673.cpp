#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("10673.in","r",stdin);
  freopen("10673.out","w",stdout);
  lint a,b,ca,x,y,n,d,m,k;
  scanf("%lld",&ca);
  while(ca--)
  {
    scanf("%lld%lld",&n,&k);
    a=(lint)((double)n/k);
    b=ceil((double)n/k);
    ex_gcd(a,b,d,x,y);
    x*=n;
    x=(x%b+b)%b;
    y=(n-a*x)/b;
    printf("%lld %lld\n",x,y);
  }
  return 0;
}
