#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define MOD 1000007
using namespace std;

int f[509][509];

int main()
{
  freopen("11806.in","r",stdin);
  freopen("11806.out","w",stdout);
  int n,T,m,i,j,k,x,y,c,ii=0;
  scanf("%d",&T);
  memset(f,0,sizeof(f));
  f[0][0]=1;
  for (i=1;i<=501;i++)
  {
    f[i][0]=f[i][i]=1;
    for (j=1;j<i;j++)
      f[i][j]=(f[i-1][j-1]+f[i-1][j])%MOD;
  }
  while(T--)
  {
    printf("Case %d: ",++ii);
	scanf("%d%d%d",&n,&m,&k);
    int ans=0;//f[m*n][k];
    for (i=0;i<16;i++)
    {
      c=0;x=n;y=m;
      if (i&1){x--;c++;}
      if (i&2){x--;c++;}
      if (i&4){y--;c++;}
      if (i&8){y--;c++;}
      if (c&1)
        ans=(ans-f[x*y][k]+MOD)%MOD;
      else
        ans=(ans+f[x*y][k])%MOD;
	}
	printf("%d\n",(ans+MOD)%MOD);
  }
  return 0;
}
