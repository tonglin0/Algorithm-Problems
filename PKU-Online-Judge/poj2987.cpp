#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
#define inf (long long)1e17
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[500004];
int dis[500004],cur[500005];
bool vis[500005];
int S,T,s=0;

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

long long min(long long a,int b)
{
  if (a<b) return a;
  return b;
}

bool bfs()
{
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  queue<int> q;
  vis[S]=true;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
      }
    }                 
  } 
  return vis[T];
}

long long dfs(int u,long long a)
{
  if (u==T||a==0) return a;
  long long flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    cur[u]=i;
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow=flow+f;
      a=a-f;
      e.f=e.f+f;
      es[g[u][i]^1].f=es[g[u][i]^1].f-f;
      if (a==0) return flow;
    }
  }
  return flow;
}

void floodfill(int u)
{
  vis[u]=true;
  s++;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (!vis[e.to]&&e.c>e.f)
      floodfill(e.to);
  }
}

int main()
{
  int n,i,j,k,m;
  //freopen("2987.in","r",stdin);
  //freopen("2987.out","w",stdout);
  scanf("%d%d",&n,&m);
  T=n+1;S=0;
  long long sum=0;
  for (i=1;i<=n;i++)
  {
    int u;
    scanf("%d",&u);
    if (u>0)
    {
      addedge(S,i,u);
      sum=sum+(long long)u;
    }
    else if (u<0)
      addedge(i,T,-u);
  }
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(u,v,INF);
  }
  long long ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans=ans+dfs(S,inf);
  }
  //printf("%I64d ",sum-ans);
  memset(vis,0,sizeof(vis));
  floodfill(S);
  printf("%d %I64d\n",s-1,sum-ans);
  return 0;
}

