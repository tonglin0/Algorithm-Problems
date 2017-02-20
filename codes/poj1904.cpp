#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
#define MN 34006
using namespace std;

int low[MN],pre[MN],fa[MN];
vector<int> g[MN];
vector<int> p[MN];
int cnt,dfn;
stack<int> s;

void tarjan(int u)
{
  pre[u]=low[u]=++dfn;
  s.push(u);
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      tarjan(v);
      low[u]=min(low[u],low[v]);
    }
    else if (!fa[v])
      low[u]=min(low[u],pre[v]);    
  }
  if (pre[u]==low[u])
  {
    cnt++;
    for (;;)
    {
      int x=s.top();s.pop();
      fa[x]=cnt;
      if (x==u) break;
    }
  }
}

int main()
{
  freopen("1904.in","r",stdin);
  freopen("1904.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    memset(low,0,sizeof(low));
    memset(pre,0,sizeof(pre));
    for (i=0;i<MN;i++) g[i].clear();
    memset(fa,0,sizeof(fa));
    for (i=1;i<=n;i++)
    {
      int v;
      int d;
      scanf("%d",&d);
      for (j=1;j<=d;j++)
      {
        scanf("%d",&v);
        g[i].push_back(v+n);
      }
    }
    for (i=1;i<=n;i++)
    {
      int v;
      scanf("%d",&v);
      g[v+n].push_back(i);
    }
    dfn=cnt=0;
    while(!s.empty())s.pop();
    for (i=1;i<=n+n;i++)
      if (!pre[i])
        tarjan(i);
    for (i=0;i<MN;i++) p[i].clear();
    for (i=1;i<=n;i++)
      for (j=0;j<g[i].size();j++)
        if (fa[i]==fa[g[i][j]])
          p[i].push_back(g[i][j]-n);  
    for (i=1;i<=n;i++)
    {
      sort(p[i].begin(),p[i].end());
      printf("%d",p[i].size());
      for (j=0;j<p[i].size();j++)
        printf("% d",p[i][j]);
      printf("\n");
    }
  }
  return 0;
}
