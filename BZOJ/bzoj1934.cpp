#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 306
using namespace std;

struct edge{
	int from,to,c,f;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],cur[MN];
bool vis[MN];
int a[MN];
int S,T;


void addedge(int from,int to,int c)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  queue<int> q;
  memset(vis,0,sizeof(vis));
  dis[S]=0;
  q.push(S);
  vis[S]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
	  }
	}
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0)
    return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return flow;
	}
  }
  return flow;
}


int main()
{
  freopen("1934.in","r",stdin);
  freopen("1934.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  scanf("%d%d",&n,&m);
  S=0;T=n+1;
  for (i=1;i<=n;i++) 
  {
    scanf("%d",&a[i]);
    if (a[i]==1)
      addedge(S,i,1);
    else
      addedge(i,T,1);
  }
  while(m--)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(u,v,1);
    addedge(v,u,1);
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  printf("%d\n",ans);
  return 0;
}

