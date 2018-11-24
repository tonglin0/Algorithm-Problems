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
#define MN 82204
using namespace std;

int tot;
int S,T,n,m;
int c[102];
int aa[102][103];
struct edge{
	int from,to,c,f,cost;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],p[MN],a[MN];
bool ins[MN];
int cost=0;

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
  dis[S]=0;a[S]=INF;p[S]=0;
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
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
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
  int u=T;
  cost+=a[T]*dis[T];
  int x,y;
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    if (es[p[u]].to==T)
    {
      u=es[p[u]].from;
      x=(u-m-1)/tot+1;
      y=(u-m)%tot+1;
      continue;
	}
	u=es[p[u]].from;
  }
  for (int i=1;i<=m;i++)
    addedge(i,m+(x-1)*tot+y,1,y*aa[i][x]);
  addedge((x-1)*tot+y+m,T,1,0);
  return true;
}

int main()
{
  freopen("2879.in","r",stdin);
  freopen("2879.out","w",stdout);
  int ca,i,j,k,ii=0;
  scanf("%d%d",&m,&n);
  tot=0;
  for (i=1;i<=m;i++)
    scanf("%d",&c[i]),tot+=c[i];
  S=0;T=tot*n+m+1;
  for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
      scanf("%d",&aa[i][j]);
  for (i=1;i<=n;i++)
    addedge(m+(i-1)*tot+1,T,1,0);
  for (i=1;i<=m;i++)
    addedge(S,i,c[i],0);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      addedge(j,m+(i-1)*tot+1,1,aa[j][i]);
  while(spfa());
  printf("%d\n",cost);
  return 0;
}

