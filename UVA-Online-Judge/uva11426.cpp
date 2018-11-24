#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#define lint long long
#define MN 4000009
using namespace std;

lint g[MN];
lint f[MN];
lint phi[MN];

int main()
{
  freopen("11426.in","r",stdin);
  freopen("11426.out","w",stdout);
  lint n,i,j,k,m;
  memset(phi,0,sizeof(phi));
  phi[1]=0;
  for (i=2;i<=4000000;i++)
    if (!phi[i])
      for (j=i;j<=4000000;j+=i)
      {
        if (!phi[j])
          phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
	  }
  memset(g,0,sizeof(g));
  memset(f,0,sizeof(f));
  for (i=1;i<=4000000;i++)
    for (j=i;j<=4000000;j+=i)
      g[j]+=i*phi[j/i];
  f[1]=g[1];
  for (i=2;i<=4000000;i++)
    f[i]=f[i-1]+g[i];
  while(scanf("%lld",&n)==1&&n)
    printf("%lld\n",f[n]);
  //printf("%.6lf\n",clock()/(double)CLOCKS_PER_SEC);
  return 0;
}
