#include<cstdio>
#include<cstring>
#include<cstdlib>
#define eps 1e-8
using namespace std;

double p[1003];
double f[1003];

double pow_(double a,int b)
{
  double ans=1,t=a;
  while(b)
  {
    if (b&1)
      ans*=t;
    b>>=1;
    t*=t;
  }
  return ans;
}

int main()
{
  freopen("11021.in","r",stdin);
  freopen("11021.out","w",stdout);
  int n,i,j,k,m,ca,ii;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    scanf("%d%d%d",&n,&k,&m);
    for (i=0;i<n;i++)
      scanf("%lf",&p[i]);
    memset(f,0,sizeof(f));
    f[0]=0;f[1]=p[0];
    for (i=2;i<=m;i++)
    {
      f[i]=p[0];
      for (j=1;j<=n-1;j++)
        f[i]+=p[j]*pow_(f[i-1],j);
	}
	printf("Case #%d: ",ii);
	printf("%.7lf\n",eps+pow_(f[m],k));
  }
  return 0;
}

