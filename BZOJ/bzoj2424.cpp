#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 54
using namespace std;

int S,T;
int cost=0,flow=0;
struct edge{
	int from,to,c,f,cost;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],a[MN],p[MN];
bool ins[MN];

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
    dis[i]=INF,ins[i]=false;
  dis[S]=0;
  queue<int> q;
  q.push(S);
  a[S]=INF;
  p[S]=0;
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
        a[e.to]=min(e.c-e.f,a[u]);
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
		}
	  }
	}
  }
  if (dis[T]==INF)
    return false;
  cost+=dis[T]*a[T];
  flow+=a[T];
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
  freopen("2424.in","r",stdin);
  freopen("2424.out","w",stdout);
  int ca,n,i,j,k,m,ii=0,s;
  scanf("%d%d%d",&n,&m,&s);
  S=0;T=n+1;
  for (i=1;i<=n;i++)
  {
  	int ui;
    scanf("%d",&ui);
    addedge(i,T,ui,0);
  }
  for (i=1;i<=n;i++)
  {
    int di;
    scanf("%d",&di);
    addedge(S,i,INF,di);
  }
  for (i=1;i<=n-1;i++)
    addedge(i,i+1,s,m);
  while(spfa());
  printf("%d\n",cost);
  return 0;
}

