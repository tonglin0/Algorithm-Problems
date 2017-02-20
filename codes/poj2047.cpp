#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF (int)1e9
#define MN 390
using namespace std;

struct edge{
	int from,to,c,f,cost;
};
int S,T;
vector<edge> es;
vector<int> g[MN];
int dis[MN],a[MN],p[MN];
bool ins[MN];
int cost;

void addedge(int from,int to,int c,int cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;x.cost=cost;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool spfa()
{
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  dis[S]=0;
  a[S]=INF;
  memset(ins,0,sizeof(ins));
  ins[S]=true;
  p[S]=0;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[u]+e.cost<dis[e.to])
      {
        dis[e.to]=dis[u]+e.cost;
        a[e.to]=min(a[u],e.c-e.f);
        p[e.to]=g[u][i];
        if (!ins[e.to])
        {
          q.push(e.to);
          ins[e.to]=true;
		}
	  }
	}
  }
  if (dis[T]==INF)
    return false;
  cost+=dis[T]*a[T];
  int u=T;
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}

int main()
{
  freopen("2047.in","r",stdin);
  freopen("2047.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    es.clear();
    for (i=0;i<MN;i++)
      g[i].clear();
    S=0;
    T=367;
    for (i=0;i<=366;i++)
      addedge(i,i+1,2,0);
    int u,v,w;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      addedge(u,v+1,1,-w);
	}
	cost=0;
	while(spfa());
	printf("%d\n",-cost);
  }
  return 0;
}
