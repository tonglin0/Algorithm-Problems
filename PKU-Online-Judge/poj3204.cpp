#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<edge> es2;
vector<int> g[604];
int cur[604],dis[604];
bool vis[604];
bool fll[604];//,fill[604];
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
        dis[e.to]=dis[u]+1;
        vis[e.to]=true;
        q.push(e.to);
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
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      a-=f;
      flow+=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

void floodfill(int u)
{
  fll[u]=true;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c>e.f&&!fll[e.to])
      floodfill(e.to);
  }
}

int main()
{
  //freopen("3204.in","r",stdin);
  //freopen("3204.out","w",stdout);
  int n,i,j,m,k;
  scanf("%d%d",&n,&m);
  S=0;T=n-1;
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(u,v,w);
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  for (i=0;i<es.size();i++)
  {
    edge x=es[i];
    es2.push_back(x);
  }
  memset(fll,0,sizeof(fll));
  floodfill(S);
  int s=0;
  for (i=0;i<es2.size();i++)
    if (es2[i].c>0&&fll[es2[i].from]&&!fll[es2[i].to])
    {
      es.clear();
      for (j=0;j<es2.size();j++)
      {
        edge x=es2[j];
        es.push_back(x);
      }
      int t=0;
      bool flag=false;
      es[i].c=INF;
      while(!flag&&bfs())
      {
        memset(cur,0,sizeof(cur));
        t+=dfs(S,INF);
        if (t>0)
        {
          flag=true;
          break;
        }
      }
      if (flag) s++;
    }  
  printf("%d\n",s);
  return 0;
}
