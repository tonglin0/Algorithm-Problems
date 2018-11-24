#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
#define INF (int)1e9
#define MN 5003
using namespace std;

bool ins[MN];
int dis[MN],p[MN],a[MN];
struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int map[153][153];
int S,T,cost=0,flow=0;

void addedge(int from,int to,int c,int cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;x.cost=cost;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.f=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool spfa()
{
  memset(dis,60,sizeof(dis));
  memset(ins,0,sizeof(ins));
  memset(a,0,sizeof(a));
  memset(p,0,sizeof(p));
  queue<int> q;
  q.push(S);
  ins[S]=true;
  dis[S]=0;
  a[S]=INF;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[e.to]>dis[u]+e.cost)
      {
        dis[e.to]=dis[u]+e.cost;
        a[e.to]=min(a[u],e.c-e.f);
        p[e.to]=g[u][i];
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
  if (dis[T]==dis[MN-1]) return false;
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
  int n,i,j,k,m,N;
  //freopen("3422.in","r",stdin);
  //freopen("3422.out","w",stdout);
  scanf("%d%d",&n,&m);
  if (m==0)
  {
    printf("0\n");
    return 0;
  }
  memset(map,0,sizeof(map));
  N=n*n;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      scanf("%d",&map[i][j]);
      addedge((i-1)*n+j,(i-1)*n+j+N,1,-map[i][j]);
      addedge((i-1)*n+j,(i-1)*n+j+N,m-1,0);
      if (i!=n)
        addedge((i-1)*n+j+N,(i)*n+j,INF,0);
      if (j!=n)
        addedge((i-1)*n+j+N,(i-1)*n+j+1,INF,0);
    }
  S=1;
  T=N+N;
  while(spfa());
  printf("%d\n",-cost);
  return 0;
}
