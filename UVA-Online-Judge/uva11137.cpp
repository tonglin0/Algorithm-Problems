#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint d[30][100990];
lint fac[30];

int main()
{
  freopen("11137.in","r",stdin);
  freopen("11137.out","w",stdout);
  lint i,j,k,m,n;
  for (i=0;i<=22;i++)
    fac[i]=i*i*i;
  memset(d,0,sizeof(d));
  for (i=0;i<=10001;i++)
    d[1][i]=1;
  for (i=2;i<=22;i++)
    for (j=0;j<=10001;j++)
      for (lint a=0;j+a<=10001;a+=fac[i])
        d[i][j+a]+=d[i-1][j];
  while(scanf("%lld",&n)==1)
    printf("%lld\n",d[21][n]);
  return 0;
}
 
