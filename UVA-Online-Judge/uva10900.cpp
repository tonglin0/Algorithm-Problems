#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

double f[33];

int main()
{
  freopen("10900.in","r",stdin);
  freopen("10900.out","w",stdout);
  int n,i,j,k,m;
  double p,t;
  while(scanf("%d%lf",&n,&t)==2)
  {
    if (n==0)
      break;
    memset(f,0,sizeof(f));
    f[n]=1<<n;
    for (i=n-1;i>=0;i--)
    {
      p=(1<<i)/f[i+1];
      if (p<=t)
        f[i]=(t+1)/2*f[i+1];
      else
      {
        double a=p-t;
        double b=1-p;
        f[i]=a/(1-t)*(1<<i)+b/(1-t)*(p+1)/2.0*f[i+1];
      }
    }
    printf("%.3lf\n",f[0]);
  }
  return 0;
}
