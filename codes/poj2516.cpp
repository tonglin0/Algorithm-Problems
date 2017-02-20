#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
#define INF (int)1e9
using namespace std;

int ask[100][100],pro[100][100];
int map[53][53][53];
struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[503];
int dis[503],p[503],a[503];
bool ins[503];
int asks[53],pros[53];
int T,flow,cost;

void addedge(int from,int to,int c,int cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.cost=cost;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  memset(ins,0,sizeof(ins));
  memset(a,0,sizeof(a));
  memset(p,0,sizeof(p));
  for (int i=1;i<=T;i++)
    dis[i]=INF;
  dis[0]=0;
  ins[0]=true;
  a[0]=INF;
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int x=q.front();q.pop();
    ins[x]=false;
    for (int i=0;i<g[x].size();i++)
    {
      edge e=es[g[x][i]];
      if (e.c>e.f&&dis[x]<dis[e.to]-e.cost)
      {
        dis[e.to]=dis[x]+e.cost;
        p[e.to]=g[x][i];
        a[e.to]=min(e.c-e.f,a[x]);
        if (!ins[e.to]){q.push(e.to);ins[e.to]=true;}
      }
    }
  }
  if (dis[T]==INF) return false;
  flow+=a[T];
  cost+=a[T]*dis[T];
  int u=T;
  while(u!=0)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}

int main()
{
  //freopen("2516.in","r",stdin);
  //freopen("2516.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d%d",&n,&m,&k);
  while(!((n==0)&&(m==0)&&(k==0)))
  {
    memset(map,0,sizeof(map));
    memset(ask,0,sizeof(ask));
    memset(pro,0,sizeof(pro));
    es.clear();
    /*T=(m+n)*k+1;
    flow=cost=0;
    for (i=0;i<5003;i++) g[i].clear();
    for (i=1;i<=n;i++)
      for (j=1;j<=k;j++)
      {
        scanf("%d",&ask[i][j]);
        addedge((m+i-1)*k+j,T,ask[i][j],0);
      }
    for (i=1;i<=m;i++)
      for (j=1;j<=k;j++)
      {
        scanf("%d",&pro[i][j]);
        addedge(0,(i-1)*k+j,pro[i][j],0);
      }
    for (int r=1;r<=k;r++)
      for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
          int d;
          scanf("%d",&d);
          addedge((j-1)*k+r,(i+m-1)*k+r,INF,d);
        }
    while(bfs());
    int s=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=k;j++)
        s+=ask[i][j];
    //printf("flow= %d\n",flow);
    if (flow!=s) printf("-1\n");
      else printf("%d\n",cost);*/
    memset(asks,0,sizeof(asks));
    memset(pros,0,sizeof(pros));
    flow=cost=0;
    int ss=0;
    for (i=0;i<503;i++) g[i].clear();
    //int asks=0,pros=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=k;j++)
      {
        scanf("%d",&ask[i][j]);
        asks[j]+=ask[i][j];
        ss+=ask[i][j];
      }
    for (i=1;i<=m;i++)
      for (j=1;j<=k;j++)
      {
        scanf("%d",&pro[i][j]);
        pros[j]+=pro[i][j];
      }
    for (int r=1;r<=k;r++)
      for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
          scanf("%d",&map[r][i][j]);
        }
    bool flag=true;
    for (i=1;i<=k;i++)
      if (pros[i]<asks[i])
      {
        flag=false;
        break;
      }
    if (!flag)
    {
      scanf("%d%d%d",&n,&m,&k);
      printf("-1\n");
      continue;
    }
    T=n+m+1;
    for (i=1;i<=k;i++)
    {
      es.clear();
      for(j=0;j<503;j++) g[j].clear();
      for (j=1;j<=m;j++)
        addedge(0,j,pro[j][i],0);
      for (j=1;j<=n;j++)
        addedge(j+m,T,ask[j][i],0);
      for (j=1;j<=m;j++)
        for (int ii=1;ii<=n;ii++)
          addedge(j,ii+m,INF,map[i][ii][j]);
      while(bfs());
    }
    if (flow<ss) printf("-1\n");
      else printf("%d\n",cost);
    scanf("%d%d%d",&n,&m,&k);
  }
  return 0;
}
