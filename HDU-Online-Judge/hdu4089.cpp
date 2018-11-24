#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

double dp[2005][2005];
double c[2005];

int main()
{
  freopen("4089.in","r",stdin);
  freopen("4089.out","w",stdout);
  int n,i,j,k,m;
  double p1,p2,p3,p4,p,p31,p41;
  while(scanf("%d%d%d",&n,&m,&k)==3)
  {
    scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
    if (p4<=1e-9)//if (fabs(1.0-p1-p2)<=1e-9)
    {
      printf("0.00000\n");
      continue;
	}
    double pp[2005];
    p=p2/(1-p1);
    p31=p3/(1-p1);
    p41=p4/(1-p1);
    dp[1][1]=p4/(1-p1-p2);
    pp[0]=1.0;
    for (i=1;i<=n;i++)
      pp[i]=pp[i-1]*p;
    c[1]=p41;
    for (i=2;i<=n;i++)
    {
      for (j=2;j<=k;j++)
        c[j]=p31*dp[i-1][j-1]+p41;
      for (j=k+1;j<=n;j++)
        c[j]=p31*dp[i-1][j-1];
      double tmp=0.0;
      for (j=1;j<=i;j++)
        tmp+=pp[i-j]*c[j];
      dp[i][i]=tmp/(1-pp[i]);
      dp[i][1]=p*dp[i][i]+c[1];
      for (j=2;j<=n;j++)
        dp[i][j]=p*dp[i][j-1]+c[j];
	}
	printf("%.5lf\n",dp[n][m]);
  }
  return 0;
}
