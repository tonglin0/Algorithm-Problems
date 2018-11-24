#include<cstdio>
#include<cmath>
#define lint long long
#define MOD 1000000007
using namespace std;

lint pow(lint a,lint b,lint c)
{
  a%=c;
  lint ans=1,t=a;
  while(b)
  {
    if (b&1) ans=ans*t%MOD;
    b>>=1;
    t=t*t%MOD;
  }
  return ans;
}

int main()
{
  freopen("11609.in","r",stdin);
  freopen("11609.out","w",stdout);
  lint ii,T,n,m,i,j,k,a,b;
  scanf("%lld",&T);
  for (ii=1;ii<=T;ii++)
  {
    printf("Case #%lld: ",ii);
    scanf("%lld",&n);
    printf("%lld\n",n%MOD*pow(2,n-1,MOD)%MOD);
  }
  return 0;
}
