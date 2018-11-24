#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define MN 204
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int S,T;
int cur[MN],dis[MN];
bool vis[MN];

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
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  vis[S]=true;
  queue<int> q;
  q.push(S);
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
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  freopen("1532.in","r",stdin);
  freopen("1532.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&m,&n)==2){
  int u,v,w;
  es.clear();
  for (i=0;i<MN;i++) g[i].clear();
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    addedge(u,v,w);
  }
  int ans=0;
  S=1;T=n;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  printf("%d\n",ans);}
  return 0;
}
