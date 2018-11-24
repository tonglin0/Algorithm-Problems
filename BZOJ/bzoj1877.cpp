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
#define MN 408
using namespace std;

struct edge{
	int from,to,c,f,cost;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],a[MN],p[MN];
bool ins[MN];
int n;
int S,T;
int cost=0,flow=0;

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
  for (int i=0;i<=n+n;i++)
    dis[i]=INF;
  memset(ins,0,sizeof(ins));
  queue<int> q;
  q.push(S);
  p[S]=0;
  dis[S]=0;
  a[S]=INF;
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
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
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
  int u=T;
  flow+=a[T];
  cost+=dis[T]*a[T];
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
  freopen("1877.in","r",stdin);
  freopen("1877.out","w",stdout);
  int i,j,k,m,ii=0,ca;
  scanf("%d%d",&n,&m);
  S=n+1;T=n;
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(u+n,v,1,w);
  }
  for (i=2;i<=n-1;i++)
    addedge(i,i+n,1,0);
  while(spfa());
  printf("%d %d\n",flow,cost);
  return 0;
}

