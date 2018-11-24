#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define lint long long
using namespace std;

lint r[1006],b[1005];

int main()
{
  freopen("1510.in","r",stdin);
  freopen("1510.out","w",stdout);
  lint n,i,j,k,m,T;
  scanf("%lld",&T);
  while(T--)
  {
    scanf("%lld",&n);
    memset(r,0,sizeof(r));
    memset(b,0,sizeof(b));
    for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
      {
        scanf("%lld",&k);
        if (k==1)
        {
          r[i]++;
          r[j]++;
		}
		else
		{
		  b[i]++;
		  b[j]++;
		}
	  }
	lint ans=(n-1)*(n-2)/2*n/3;
	lint s=0;
	for (i=1;i<=n;i++)
	  s+=r[i]*b[i];
	s=s/2;
	ans-=s;
	printf("%lld\n",ans);
  }
  return 0;
}
