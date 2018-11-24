#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

double a[50009];

int main()
{
  freopen("10883.in","r",stdin);
  freopen("10883.out","w",stdout);
  int T,ii,n,i,j,k,m;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    printf("Case #%d: ",ii);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%lf",&a[i]);
    if (n==0)
    {
      printf("0.000\n");
      continue;
	}
	if (n==1)
    {
      printf("%.3lf\n",a[1]);
      continue;
	}
	if (n==2)
	{
	  printf("%.3lf\n",(a[1]+a[2])/2.0);
	  continue;
	}
	double logd=(n-1)*log(2.0);
	double ans=0;
	double logc=0;
	for (i=0;i<=n-1;i++)
	{
	  if (i)
	    logc=logc+log(n-i)-log(i);
	  if (a[i+1]>0.00)
	    ans+=exp(logc+log(a[i+1])-logd);
	  else
	    ans-=exp(logc+log(-a[i+1])-logd);
	}
	printf("%.3lf\n",ans);
  }
  return 0;
}
