#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-8
#define lint long long
using namespace std;

int main()
{
  freopen("11461.in","r",stdin);
  freopen("11461.out","w",stdout);
  lint y,a,x,b,i,j,k,n,m;
  while(scanf("%lld%lld",&a,&b)==2&&(a+b))
  {
    x=ceil(sqrt(1.0*a));
    y=(lint)(sqrt(1.0*b));
    lint ans=y-x+1;
    printf("%lld\n",ans);
  }
  return 0;
}
