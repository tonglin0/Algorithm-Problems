#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

double f[1004][1004];
double a[1004][1004][4];

int main()
{
  freopen("3853.in","r",stdin);
  freopen("3853.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        for (k=1;k<=3;k++)
          scanf("%lf",&a[i][j][k]);
    memset(f,0,sizeof(f));
    for (i=m-1;i>=1;i--)
    {
      if (a[n][i][1]==1)
        f[n][i]=-1;
      else if (f[n][i+1]==-1)
        f[n][i]=-1;
      else
	    f[n][i]=(a[n][i][2]*f[n][i+1]+2)/(1-a[n][i][1]);
    }
    for (i=n-1;i>=1;i--)
    {
      if (a[i][m][1]==1)
        f[i][m]=-1;
      else if (f[i+1][m]==-1)
        f[i][m]=-1;
      else
        f[i][m]=(a[i][m][3]*f[i+1][m]+2)/(1-a[i][m][1]);
	}
	for (i=n-1;i>=1;i--)
	  for (j=m-1;j>=1;j--)
	  {
	    if (a[i][j][1]==1)
	      f[i][j]=-1;
	    else if (f[i+1][j]==-1&&f[i][j+1]==-1)
	      f[i][j]=-1;
	    else
	    {
	      if (f[i+1][j]!=-1)
	        f[i][j]=a[i][j][3]*f[i+1][j];
	      if (f[i][j+1]!=-1)
	        f[i][j]+=a[i][j][2]*f[i][j+1];
	      f[i][j]+=2;
	      f[i][j]/=(1-a[i][j][1]);
		}
	  }
	printf("%.3lf\n",f[1][1]);
  }
  return 0;
}
