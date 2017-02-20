#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define INF 100000000
#include<cstring>
using namespace std;

queue<int> q;
int f[203][203],c[203][203],a[203],p[203];
int main()
{
  freopen("input7.in","r",stdin);
  freopen("1273.out","w",stdout);
  int n,i,j,m,u,v,w;
  while(scanf("%d%d",&m,&n)==2)
  {
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      c[u][v]+=w;
    }
    int ans=0;
    for (;;)
    {
      memset(p,0,sizeof(p));
      memset(a,0,sizeof(a));
      a[1]=INF;
      q.push(1);
      while (!q.empty())
      {
        u=q.front();q.pop();
        for (i=1;i<=n;i++)
          if (!a[i]&&c[u][i]>f[u][i])
          {
            a[i]=min(a[u],c[u][i]-f[u][i]);
            q.push(i);
            p[i]=u;
          }
      }
        if (a[n]==0) break;
        for (i=n;i!=1;i=p[i])
        {
          f[p[i]][i]+=a[n];
          f[i][p[i]]-=a[n];
        }
        ans+=a[n];
    }
    printf("%d\n",ans);
  }
  return 0;
} 
