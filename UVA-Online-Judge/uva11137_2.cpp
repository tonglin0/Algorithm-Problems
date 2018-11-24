#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint d[30][20090];
lint fac[30];

int main()
{
  freopen("11137.in","r",stdin);
  freopen("11137.out","w",stdout);
  lint n,i,j,k,m;
  memset(d,0,sizeof(d));
  for (i=0;i<=21;i++)
    fac[i]=i*i*i;
  for (i=0;i<=10000;i++)
    d[1][i]=1;
  for (i=2;i<=21;i++)
    for (j=0;j<=10000;j++)
      if (j-fac[i]>=0)
        d[i][j]=d[i-1][j]+d[i][j-fac[i]];
      else
        d[i][j]=d[i-1][j];
  while(scanf("%lld",&n)==1)
    printf("%lld\n",d[21][n]);
  return 0;
}
