#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

double d[1002][32][32];
double a[1004][32];

int main()
{
  freopen("2151.in","r",stdin);
  freopen("2151.out","w",stdout);
  int t,n,i,j,k,m;
  while(scanf("%d%d%d",&m,&t,&n)==3)
  {
    if (m+t+n==0)
      break;
    memset(d,0,sizeof(d));
    for (i=1;i<=t;i++)
      for (j=1;j<=m;j++)
        scanf("%lf",&a[i][j]);
    for (i=1;i<=t;i++)
    {
      d[i][0][0]=1;
      d[i][0][1]=0;
	}
	for (i=1;i<=t;i++)
	  for (j=1;j<=m;j++)
	    for (k=0;k<=j;k++)
	    {
	      if (k)
	        d[i][j][k]=d[i][j-1][k-1]*a[i][j];
	      d[i][j][k]+=d[i][j-1][k]*(1-a[i][j]);
		}
	double ans=1;
	for (i=1;i<=t;i++)
	{
	  double s=0;
	  for (j=1;j<=m;j++)
	    s+=d[i][m][j];
	  ans*=s;
	}
	double ans2=1;
	for (i=1;i<=t;i++)
	{
	  double s=0;
	  for (j=1;j<=n-1;j++)
	    s+=d[i][m][j];
	  ans2*=s;
	}
	printf("%.3lf\n",ans-ans2);
  }
  return 0;
}
