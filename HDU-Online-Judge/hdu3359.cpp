#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

double a[104][104];
double g[209][209];

void gause(int n)
{
  int i,j,k,r;
  for (i=1;i<=n;i++)
  {
    r=i;
    for (j=i+1;j<=n;j++)
      if (fabs(g[j][i])>fabs(g[r][i]))
        r=j;
    if (fabs(g[r][i])<1e-8)
      continue;
	if (r!=i)
      for (k=i;k<=n+1;k++)
        swap(g[r][k],g[i][k]);
    for (k=1;k<=n;k++)
      if (k!=i)
        for (j=n+1;j>=i;j--)
          g[k][j]-=g[k][i]/g[i][i]*g[i][j];
  }
  for (i=1;i<=n;i++)
    g[i][n+1]/=g[i][i];
}

int main()
{
  freopen("3359.in","r",stdin);
  freopen("3359.out","w",stdout);
  int n,i,j,k,m,w,h,d;
  bool first=true;
  while(scanf("%d%d%d",&w,&h,&d)==3)
  {
    if (w+h+d==0)
      break;
    for (i=1;i<=h;i++)
      for (j=1;j<=w;j++)
        scanf("%lf",&a[i][j]);
    memset(g,0,sizeof(g));
    n=w*h;
	for (i=1;i<=h;i++)
	  for (j=1;j<=w;j++)
	  {
	    int t=(i-1)*w+j;
	    for (int ii=1;ii<=h;ii++)
	      for (int jj=1;jj<=w;jj++)
	        if (abs(ii-i)+abs(jj-j)<=d)
	        {
	          int tn=(ii-1)*w+jj;
	          g[t][tn]=1;
	          g[t][n+1]+=a[i][j];
			}
	  }
	gause(n);
	if (!first)
	  printf("\n");
	first=false;
	for (i=1;i<=h;i++)
	{
	  for (j=1;j<=w;j++)
	    printf("%8.2lf",g[(i-1)*w+j][n+1]);
	  printf("\n");
	}
  }
  return 0;
}
