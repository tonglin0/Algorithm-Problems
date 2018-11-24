#include<cstdlib>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#define INF (int)1e9
#define MN 403
using namespace std;

int ind[MN],outd[MN],x[MN],dis[MN],cur[MN];
bool vis[MN];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
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
  if(u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  //freopen("1637.in","r",stdin);
  //freopen("1637.out","w",stdout);
  int TC,n,m,i,j,k;
  scanf("%d",&TC);
  while(TC--)
  {
    memset(ind,0,sizeof(ind));
    memset(outd,0,sizeof(outd));
    memset(x,0,sizeof(x));
    es.clear();
    for (i=0;i<MN;i++) g[i].clear();
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d%d",&u,&v,&k);
      if (k==1)
      {
        outd[u]++;
        ind[v]++;
      }
      else
      {
        outd[u]++;
        ind[v]++;
        addedge(u,v,1);
      }
    }
    int s=0;
    bool flag=true;
    for (i=1;i<=n;i++)
      if ((ind[i]-outd[i])&1==1)
      {
        flag=false;
        break;
      }
    if (!flag)
    {
      printf("impossible\n");
      continue;
    }
    T=n+1;
    for (i=1;i<=n;i++)
    {
      if (ind[i]<outd[i])
      {
        s+=((outd[i]-ind[i])>>1);
        addedge(0,i,(outd[i]-ind[i])>>1);
      }
      else
        addedge(i,T,(ind[i]-outd[i])>>1);
    }
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    if (ans==s)
      printf("possible\n");
    else
      printf("impossible\n");
  }
  return 0;
}
