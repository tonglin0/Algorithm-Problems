#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define MOD 1000000
using namespace std;

int c[204][204];

int main()
{
  freopen("10943.in","r",stdin);
  freopen("10943.out","w",stdout);
  int n,k,i,j;
  memset(c,0,sizeof(c));
  c[0][0]=1;
  for (i=1;i<=200;i++)
  {
    c[i][0]=c[i][i]=1;
    for (j=1;j<=i-1;j++)
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
  }
  while(scanf("%d%d",&n,&k)==2&&(n+k))
    printf("%d\n",c[n+k-1][k-1]);
  return 0;
}
