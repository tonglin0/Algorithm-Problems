#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<vector>
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[1003];
int dis[1003],a[1003],p[1003];
bool vis[1003];
int cost=0,flow=0,n;

void addedge(int from,int to,int cost)
{
  edge x;
  x.from=from;
  x.to=to;
  x.f=0;
  x.c=1;
  x.cost=cost;
  es.push_back(x);
  x.from=to;
  x.to=from;
  x.c=0;
  x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

void addedge2(int from,int to,int cost)
{
  edge x;
  x.from=from;
  x.to=to;
  x.f=0;
  x.c=2;
  x.cost=cost;
  es.push_back(x);
  x.from=to;
  x.to=from;
  x.c=0;
  x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool spfa()
{
  for (int i=1;i<=n;i++) dis[i]=INF;
  memset(vis,0,sizeof(vis));
  queue<int> q;
  memset(p,0,sizeof(p));
  q.push(0);
  memset(a,0,sizeof(a));
  vis[0]=true;
  a[0]=INF;
  dis[0]=0;
  while(!q.empty())
  {
    int x=q.front();q.pop();
    vis[x]=false;
    for (int i=0;i<g[x].size();i++)
    {
      edge e=es[g[x][i]];
      if (e.c>e.f&&dis[x]<dis[e.to]-e.cost)
      {
        dis[e.to]=dis[x]+e.cost;
        if (!vis[e.to]){vis[e.to]=true;q.push(e.to);}
        a[e.to]=min(e.c-e.f,a[x]);
        p[e.to]=g[x][i];
      }
    }
  }
  if (dis[n]==INF) return false;
  flow+=a[n];
  cost+=dis[n]*a[n];
  int i=n;
  while(i!=0)
  {
    es[p[i]].f+=a[n];
    es[p[i]^1].f-=a[n];
    i=es[p[i]].from;
  }
  return true;
}

int main()
{
  freopen("2135.in","r",stdin);
  freopen("2135.out","w",stdout);
  int m,i,j,k;
  es.clear();
  for (i=0;i<1002;i++)g[i].clear();
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(u,v,w);
    addedge(v,u,w);
  }
  addedge2(0,1,0);
  addedge2(1,0,0);
  n++;
  addedge2(n-1,n,0);
  addedge2(n,n-1,0);
  while(spfa());
  printf("%d\n",cost);
  return 0;
}
