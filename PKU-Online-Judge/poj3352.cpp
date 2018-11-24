#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAXN 1005
#define INF (int)1e10
using namespace std;

struct edge{int v,no;};
vector<edge> g[MAXN];
int fa[MAXN],low[MAXN],pre[MAXN],d[MAXN];
bool iscut[MAXN],vis[MAXN];
int dfsclock=0;

int tarjan(int u,int fa)
{
  int lowu,lowv;
  lowu=pre[u]=++dfsclock;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i].v;
    if (!pre[v])
    {
      lowv=tarjan(v,g[u][i].no);
      lowu=min(lowu,lowv);
      if (lowv>pre[u]) iscut[g[u][i].no]=true;
    }
    else if (pre[v]<pre[u]&&g[u][i].no!=fa) 
      lowu=min(lowu,pre[v]);
  }
  return low[u]=lowu;
}

void dfs(int u,int f)
{
  vis[u]=true;
  fa[u]=f;
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v]&&!iscut[g[u][i].no]) dfs(g[u][i].v,f);
}

int main()
{
  //freopen("poj3352.in","r",stdin);
  //freopen("poj3352.out","w",stdout);
  int i,j,m,n,k=0;
  scanf("%d%d",&n,&m);
  for (i=0;i<MAXN;i++) g[i].clear();
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    edge x;
    x.v=v;
    x.no=++k;
    g[u].push_back(x);
    x.v=u;
    g[v].push_back(x);
  }
  memset(iscut,0,sizeof(iscut));
  memset(low,0,sizeof(low));
  memset(pre,0,sizeof(pre));
  tarjan(1,-1);
  memset(vis,0,sizeof(vis));
  memset(fa,0,sizeof(fa));
  int N=0;
  for (i=1;i<=n;i++)
    if (!vis[i])
    {
      N++;
      dfs(i,N);
    }
  int ans=0;
  memset(d,0,sizeof(d));
  for (i=1;i<=n;i++)
    for (j=0;j<g[i].size();j++)
      if (iscut[g[i][j].no])
      {
        d[fa[i]]++;
        d[fa[g[i][j].v]]++;
        iscut[g[i][j].no]=false;
      }
  for (i=1;i<=N;i++)
    if (d[i]==1) ans++;
  ans=(ans+1)/2;
  printf("%d\n",ans);
  return 0;
}
