#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 5003
#define INF (int)1e9
using namespace std;

int low[MAXN],pre[MAXN],d[MAXN],p[MAXN],fa[MAXN];
struct edge{int v,no;};
bool isbridge[10004],vis[MAXN];
vector<edge> g[MAXN];
//vector<int> ng;
int dfsclock=0;

void dfs(int u,int f)
{
  vis[u]=true;
  fa[u]=f;
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v]&&!isbridge[g[u][i].no])
      dfs(g[u][i].v,f);
}

int tarjan(int u,int fa)
{
  int lowu,lowv,child=0;
  lowu=pre[u]=++dfsclock;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i].v;
    if (!pre[v])
    {
      child++;
      //p[v]=u;
      lowv=tarjan(v,g[u][i].no);
      lowu=min(lowu,lowv);
      if (lowv>pre[u]) isbridge[g[u][i].no]=true;
    }
    else if (pre[v]<pre[u]&&g[u][i].no!=fa)
      lowu=min(pre[v],lowu);
  }
  return low[u]=lowu;
} 

int main()
{
  //freopen("poj3177.in","r",stdin);
  //freopen("poj3177.out","w",stdout);
  for (int i=0;i<MAXN;i++) g[i].clear();
  int n,i,no=0,j,k,m;
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    edge x;
    x.v=v;  
    x.no=++no;
    g[u].push_back(x);
    x.v=u;
    g[v].push_back(x); 
  }
  memset(low,0,sizeof(low));
  memset(pre,0,sizeof(pre));
  memset(p,0,sizeof(p));
  //for (i=0;i<MAXN;i++) ng[i].clear();
  memset(isbridge,0,sizeof(isbridge));
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
  memset(d,0,sizeof(d));
  for (i=1;i<=n;i++)
    for (j=0;j<g[i].size();j++)
      if (isbridge[g[i][j].no])
      {
        d[fa[i]]++;
        d[fa[g[i][j].v]]++;
        isbridge[g[i][j].no]=false;
      }
  int ans=0;
  for (i=1;i<=N;i++)
    if (d[i]==1) ans++;
  ans=(1+ans)/2;
  printf("%d\n",ans);
  return 0;
}
 
