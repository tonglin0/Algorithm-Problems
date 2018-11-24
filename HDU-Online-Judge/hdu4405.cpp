#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int vis[100009];
double f[100009];

int main()
{
  freopen("4405.in","r",stdin);
  freopen("4405.out","w",stdout);
  int u,v,n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    if (n+m==0)
      break;
    memset(vis,0,sizeof(vis));
    memset(f,0,sizeof(f));
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&u,&v);
      vis[u]=v;
	}
	f[n]=0;
	for (i=n-1;i>=0;i--)
	{
	  if (vis[i])
	    f[i]=f[vis[i]];
	  else
	  {
	    for (j=1;j<=6;j++)
	      f[i]+=f[min(i+j,n)]/6.0;
	    f[i]+=1.0;
	  }
	}
	printf("%.4lf\n",f[0]);
  }
  return 0;
}
