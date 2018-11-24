#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define MN 200100
using namespace std;

stack<int> q;
int ind[MN];
int low[MN],pre[MN],fa[MN];
vector<int> g[MN];
int cl=0,scc=0;

void dfs(int u)
{
  pre[u]=low[u]=++cl;
  q.push(u);
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      dfs(v);
      low[u]=min(low[u],low[v]);
    }
    else if (!fa[v])
      low[u]=min(low[u],pre[v]);
  }
  if (pre[u]==low[u])
  {
    scc++;
    for (;;)
    {
      int x=q.top();q.pop();
      fa[x]=scc;
      if (x==u) break; 
    }
  }
}

int main()
{
  freopen("2002.in","r",stdin);
  freopen("2002.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  memset(low,0,sizeof(low));
  memset(pre,0,sizeof(pre));
  memset(fa,0,sizeof(fa));
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].push_back(v);
  }
  cl=0;
  for (i=1;i<=n;i++)
    if (!pre[i])
      dfs(i);
  int ans=0;
  int N=scc;
  memset(ind,0,sizeof(ind));
  for (i=1;i<=n;i++)
    for (j=0;j<g[i].size();j++)
      if (fa[i]!=fa[g[i][j]])
        ind[fa[g[i][j]]]++;
  for (i=1;i<=N;i++)
    if (ind[i]==0)
      ans++;
  printf("%d\n",ans);
  return 0;
}
