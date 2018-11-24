#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;

int main()
{
  freopen("2407.in","r",stdin);
  freopen("2407.out","w",stdout);
  LL n,i,j,k,ans;
  scanf("%I64d",&n);
  while(n)
  {
    ans=n;
    LL m=(int)sqrt(n+0.5);
    for (i=2;i<=m;i++)
      if (n%i==0)
      {
        ans=ans/i*(i-1);
        while(n%i==0)
          n/=i;
      }
    if (n>1)
      ans=ans/n*(n-1);
    printf("%I64d\n",ans);
    scanf("%I64d",&n);
  }
  return 0;
}
