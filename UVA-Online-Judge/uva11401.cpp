#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

unsigned long long f[1000009];

int main()
{
  freopen("11401.in","r",stdin);
  freopen("11401.out","w",stdout);
  unsigned long long i,j,a,b,x,y,z,n;
  memset(f,0,sizeof(f));
  for (i=3;i<=1000000;i++)
  {
    x=i;
    a=(x>>1)+1;
    b=x-1;
    f[x]=((x-1)*(x-2)/2-(b-a+1))/2;
  }
  while(scanf("%llu",&n)==1)
  {
    if (n<3) break;
    unsigned long long ans=0;
    for (i=3;i<=n;i++)
      ans+=f[i];
    printf("%llu\n",ans);
  }
  return 0;
}
