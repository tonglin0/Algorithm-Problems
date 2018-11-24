#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
int dis[105],cur[105];
bool vis[105];
int S,T;
vector<int> g[105];

void read()
{
  char ch;
  ch=getchar();
  while(ch!='(') 
    ch=getchar();
  //while(getchar()!='(');
}

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
  int f,flow=0;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      e.f+=f;
      a-=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  freopen("1966.in","r",stdin);
  freopen("1966.out","w",stdout);
  int n,i,j,m,k;
  while(scanf("%d%d",&n,&m)==2)
  {
    es.clear();
    for (i=0;i<105;i++) g[i].clear();
    for (i=1;i<=m;i++)
    { 
      read();
      int u,v;
      scanf("%d,%d)",&u,&v);
      addedge(u+n,v,INF);
      addedge(v+n,u,INF);      
    }
    for (i=0;i<n;i++)
      addedge(i,i+n,1);
    int ans=n;
    for (S=0;S<n;S++)
    {
    for (i=S+1;i<n;i++)
    {
      T=i;
      int flow=0;
      for (j=0;j<es.size();j++) {es[j].f=0;if (es[j].from==S&&es[j].to==S+n) es[j].c=INF;if (es[j].from==T&&es[j].to==T+n) es[j].c=INF;}
      while(bfs())
      {
        memset(cur,0,sizeof(cur));
        flow+=dfs(S,INF);
      }
      ans=min(ans,flow);
      for (j=0;j<es.size();j++) if (es[j].from==T&&es[j].to==T+n) es[j].c=1;  
    }
    for (j=0;j<es.size();j++) if (es[j].from==S&&es[j].to==S+n) es[j].c=1;
    }
    printf("%d\n",ans);
  }
  return 0;
}
