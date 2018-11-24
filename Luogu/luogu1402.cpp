#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

int dis[404],cur[404];
bool vis[404];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[404];
int T;

void addedge(int from,int to,int c)
{
  edge x;
  x.from=from;
  x.to=to;
  x.c=c;
  x.f=0;
  es.push_back(x);
  x.from=to;
  x.to=from;
  x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  queue<int> q;
  q.push(0);
  vis[0]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0) return a;
  int f,flow=0;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    cur[u]=i;
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      a-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  freopen("1402.in","r",stdin);
  freopen("1402.out","w",stdout);
  int n,i,j,m,p,q,ans=0;
  scanf("%d%d%d",&n,&p,&q);
  es.clear();
  T=p+n+n+q+1;
  for (i=0;i<404;i++) g[i].clear();
  for (i=1;i<=n;i++)
    for (j=1;j<=p;j++)
    {
      scanf("%d",&m);
      if (m) addedge(j,p+i,1);
    }
  for (i=1;i<=n;i++)
    for (j=1;j<=q;j++)
    {
      scanf("%d",&m);
      if (m) addedge(i+p+n,n+n+p+j,1);
    }
  for (i=1;i<=p;i++) 
    addedge(0,i,1);
  for (i=1;i<=n;i++)
    addedge(p+i,p+n+i,1);
  for (i=1;i<=q;i++)
    addedge(p+n+n+i,T,1);
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(0,INF);
  }
  printf("%d\n",ans);
  return 0;
}
