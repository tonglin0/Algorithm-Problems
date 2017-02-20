#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int root;
int dep[10009];
int fa[10009][30];
vector<int> g[10009];
int M,n;

void dfs(int u,int fa)
{
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (v!=fa)
    {
      dep[v]=dep[u]+1;
      dfs(v,u);  
    }
  }
}

void bz()
{
  for (int j=1;j<=M;j++)
    for (int i=1;i<=n;i++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
}

int lca(int u,int v)
{
  if (dep[u]<dep[v])
    swap(u,v);
  int t=dep[u]-dep[v];
  for (int i=0;i<=M;i++)
    if ((1<<i)&t)
      u=fa[u][i];
  if (u==v) return u;
  for (int i=M;i>=0;i--)
    if (fa[u][i]!=fa[v][i])
    {
      u=fa[u][i];
      v=fa[v][i];
    }
  return fa[u][0];
}

int main()
{
  freopen("1330.in","r",stdin);
  freopen("1330.out","w",stdout);
  int T,i,j,k,m,u,v;
  scanf("%d",&T);
  while(T--)
  {
    memset(fa,0,sizeof(fa));
    for (i=0;i<10009;i++)
      g[i].clear();
    scanf("%d",&n);
    for (i=1;i<=n-1;i++)
    {
      scanf("%d%d",&u,&v);
      g[u].push_back(v);
      fa[v][0]=u;
      if (fa[u][0]==0)
        root=u;
    }
    M=(int)(log((double)n)/log((double)2))+1;
    dep[root]=1;
    dfs(root,0);
    bz();
    scanf("%d%d",&u,&v);
    printf("%d\n",lca(u,v));
  }
  return 0;
}
