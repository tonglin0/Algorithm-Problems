#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#define lint long long
using namespace std;

int main()
{
  freopen("2800.in","r",stdin);
  freopen("2800.out","w",stdout);
  lint n,i,j,k,m;
  while(scanf("%I64d%I64d",&n,&k)==2)
  {
    lint ans=0;
    if (n>k)
      ans+=(n-k)*k;
    lint a,b;
    i=1;
    while(true)
    {
      a=k/i;
      b=k/(i+1)+1;
      if (a==b)
        break;
      if (b>n)
      {
        i++;
        continue;
	  }
	  if (a>n)
	    a=n;
	  ans+=(k%a+k%b)*(a-b+1)/2;
	  i++;
	}
	for (i=1;i<=min(n,a);i++)
	  ans+=k%i;
	printf("%I64d\n",ans);
  }
  return 0;
}
