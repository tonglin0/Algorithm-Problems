#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

int dis[305],cur[305],own[305],s[3005];
bool vis[305];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[305];
int T;

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
  queue<int> q;
  vis[0]=true;
  q.push(0);
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
  int flow=0,f;
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
  int n,m,i,j,k;
  //freopen("1149.in","r",stdin);
  //freopen("1149.out","w",stdout);
  scanf("%d%d",&m,&n);
  T=n+1;
  memset(own,0,sizeof(own));
  memset(s,0,sizeof(s));
  for (i=1;i<=m;i++)
    scanf("%d",&s[i]);
  es.clear();
  for (i=0;i<105;i++) g[i].clear();
  for (i=1;i<=n;i++)
  {
    int d;
    scanf("%d",&d);
    for (j=1;j<=d;j++)
    {
      scanf("%d",&k);
      if (!own[k]) {addedge(0,i,s[k]);own[k]=i;}
        else addedge(own[k],i,INF);
    }
    scanf("%d",&d);
    addedge(i,T,d);
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(0,INF);
  }
  printf("%d\n",ans);
  return 0;
} 
