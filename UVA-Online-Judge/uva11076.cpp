#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define lint unsigned long long
using namespace std;

lint f[15];
lint times[13];
lint a[14];

int main()
{
  freopen("11076.in","r",stdin);
  freopen("11076.out","w",stdout);
  lint i,j,k,m,n,b,x;
  f[0]=1;
  for (i=1;i<=12;i++)
    f[i]=f[i-1]*i;
  while(scanf("%llu",&n)==1)
  {
	if (n==0) break;
    memset(times,0,sizeof(times));
    for (i=1;i<=n;i++)
    {
      lint d;
	  scanf("%llu",&a[i]);
	  d=a[i];
	  times[d]++;
    }
    lint mn=1;
    for (i=1;i<=n;i++)
      mn=mn*10;
    mn=(mn-1)/9;
    lint ans=0;
    for (i=1;i<=9;i++)
    {
      if (times[i]==0) continue;
      lint tmps=f[n-1];
      times[i]--;
	  for (j=0;j<=9;j++)
        tmps/=f[times[j]];
      ans=ans+tmps*mn*i;
      times[i]++;
	}
	printf("%llu\n",ans);
  }
  return 0;
}
