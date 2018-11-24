#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define MN 10009
#define INF (int)1e9
using namespace std;

int n,M;
struct node{int u,v,w;};
int fa[MN],dep[MN],up[MN][30],mi[MN][30];
bool vis[MN];
vector<node> g[MN];
node es[50009];
bool cmp(node a,node b){return a.w>b.w;}

int find(int x)
{
  if (fa[x]==x) return x;
  fa[x]=find(fa[x]);
  return fa[x];
}

void dfs(int u)
{
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v])
    {
      vis[g[u][i].v]=true;
      dep[g[u][i].v]=dep[u]+1;
      up[g[u][i].v][0]=u;
      mi[g[u][i].v][0]=g[u][i].w;
      dfs(g[u][i].v);
    }
}

void bz()
{
  for (int j=1;j<=M;j++)
    for (int i=1;i<=n;i++)
    {
      int t=up[i][j-1];
      up[i][j]=up[t][j-1];
      mi[i][j]=min(mi[i][j-1],mi[t][j-1]);
    }
}

int move(int &u,int h)
{
  int ans=INF;
  for (int i=M;i>=0;i--)
    if (dep[up[u][i]]>=h)
    {
      ans=min(ans,mi[u][i]);
      u=up[u][i];
    }
  return ans;
}

int query(int u,int v)
{
  int ans=INF;
  if (dep[u]>dep[v])
    ans=move(u,dep[v]);
  else if (dep[v]>dep[u])
    ans=move(v,dep[u]);
  if (u==v) return ans;
  for (int j=M;j>=0;j--)
    if (up[u][j]!=up[v][j])
    {
      ans=min(mi[u][j],min(ans,mi[v][j]));
      u=up[u][j];
      v=up[v][j];
    }
  return min(ans,min(mi[u][0],mi[v][0]));
}

int main()
{
  freopen("1843.in","r",stdin);
  freopen("1843.out","w",stdout);
  int i,j,k,m,u,v,w,q;
  scanf("%d%d",&n,&m);
  M=(int)(log((double)n)/log((double)2))+1;
  for (i=1;i<=m;i++)
    scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
  sort(es+1,es+m+1,cmp);
  for (i=1;i<=n;i++)
    fa[i]=i;
  memset(dep,0,sizeof(dep));
  memset(up,0,sizeof(up));
  memset(mi,0,sizeof(mi));
  for (i=1;i<=m;i++)
  {
    u=es[i].u;v=es[i].v;
    if (find(u)!=find(v))
    {
      fa[find(u)]=find(v);
      node t=es[i];
      g[u].push_back(t);
      swap(t.u,t.v);
      g[v].push_back(t);
    }
  }
  memset(vis,0,sizeof(vis));
  for (i=1;i<=n;i++)
    if (!vis[i])
    {
      vis[i]=true;
      dep[i]=1;
      mi[i][0]=INF;
      dfs(i);
    }
  bz();
  scanf("%d",&q);
  while(q--)
  {
    scanf("%d%d",&u,&v);
    if (find(u)!=find(v))
      printf("-1\n");
    else
      printf("%d\n",query(u,v));
  }
  return 0;
}
