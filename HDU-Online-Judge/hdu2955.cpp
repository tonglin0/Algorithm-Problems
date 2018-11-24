#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

double f[10009];
double p[109];
int v[109];
int dcmp(double a){if (fabs(a)<eps) return 0;return a>0?1:-1;}
//double max(double a,double b){return a>b?a:b;}
double Min(double a,double b){return a<b?a:b;}

int main()
{
  freopen("2955.in","r",stdin);
  freopen("2955.out","w",stdout);
  int n,i,j,k,m,ca;
  double limit;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%lf%d",&limit,&n);
    m=0;
	for (i=1;i<=n;i++)
    {
      scanf("%d%lf",&v[i],&p[i]);
      m+=v[i];
	  p[i]=1.0-p[i];
	}
	/*if (limit<=eps)
	{
	  printf("0\n");
	  continue;
	}*/
	f[0]=1;
	for (i=1;i<=m;i++)
	  f[i]=0;
	for (i=1;i<=n;i++)
	  for (j=m;j>=v[i];j--)
	    f[j]=max(f[j],f[j-v[i]]*p[i]);
	for (i=m;i>=0;i--)
	  if (dcmp(1-f[i]-limit)<=0)
	  {
	    printf("%d\n",i);
	    break;
	  }
  }
  return 0;
}
