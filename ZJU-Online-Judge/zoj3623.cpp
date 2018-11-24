#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int f[360];
int v[34],w[34];

int main()
{
  freopen("3623.in","r",stdin);
  freopen("3623.out","w",stdout);
  int n,i,j,m,k;
  while(scanf("%d%d",&n,&m)==2)
  {
    for (i=1;i<=n;i++)
      scanf("%d%d",&v[i],&w[i]);
    memset(f,0,sizeof(f));
    for (j=0;j<=352;j++)
      for (i=1;i<=n;i++)
        if (j>=v[i])
          f[j]=max(f[j],f[j-v[i]]+(j-v[i])*w[i]);
    for (i=0;i<=352;i++)
      if (f[i]>=m)
      {
        printf("%d\n",i);
        break;
	  }
  }
  return 0;
}
