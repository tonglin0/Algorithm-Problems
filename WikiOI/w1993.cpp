#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<cstring>
#define INF 100000000
using namespace std;

queue <int> q;
int a[203][203],F[203][203],c[203][203],b[203],f[203],p[203];
int main()
{
  freopen("input7.in","r",stdin);
  freopen("1993.out","w",stdout);
  int u,v,w,n,m,i,j,ans=0;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  memset(F,0,sizeof(F));
  scanf("%d%d",&m,&n);
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    b[u]++;
    a[u][b[u]]=v;
    c[u][v]+=w;
    b[v]++;
    a[v][b[v]]=u;
  }
  for(;;)
  {
    memset(p,0,sizeof(p));
    memset(f,0,sizeof(f));
    q.push(1);
    f[1]=INF;
    while(!q.empty())
    {
      u=q.front();q.pop();
      for (i=1;i<=b[u];i++)
        if (!f[a[u][i]]&&F[u][a[u][i]]<c[u][a[u][i]])
        {
          q.push(a[u][i]);
          p[a[u][i]]=u;
          f[a[u][i]]=min(f[u],c[u][a[u][i]]-F[u][a[u][i]]);
        }
    }
    if (f[n]==0) break;
    for (i=n;i!=1;)
    {
      F[p[i]][i]+=f[n];
      F[i][p[i]]-=f[n];
      i=p[i];
    }
    ans+=f[n];
  }
  printf("%d\n",ans);
  return 0;
}
