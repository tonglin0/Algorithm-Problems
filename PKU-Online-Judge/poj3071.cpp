#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-8
using namespace std;

double p[130][130];
double f[10][131];

int main()
{
  freopen("3071.in","r",stdin);
  freopen("3071.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    if (n==-1)
      break;
    for (i=0;i<(1<<n);i++)
      for (j=0;j<(1<<n);j++)
        scanf("%lf",&p[i][j]);
    memset(f,0,sizeof(f));
    m=1<<n;
	for (i=0;i<m;i++)
	  f[0][i]=1;
	for (i=1;i<=n;i++)
	  for (j=0;j<m;j++)
	    for (k=0;k<m;k++)
	      if (j!=k&&((k>>i)==(j>>i))&&((k>>i-1)!=(j>>i-1)))
	        f[i][j]+=f[i-1][j]*f[i-1][k]*p[j][k];
	double mn=-1;
	int ans=-1;
	for (i=0;i<m;i++)
	  if (f[n][i]>mn)
	  {
	    ans=i;
	    mn=f[n][i];
	  }
	printf("%d\n",ans+1);
	//printf("%.3lf\n",mn);
  }
  return 0;
}

