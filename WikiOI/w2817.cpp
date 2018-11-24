#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF (int)1e9
#define inf (long long)1e15
#define MN 404
using namespace std;

struct edge{int from,to;long long c,f;};
vector<edge> es;
vector<int> g[MN];
int cur[MN],p[MN],a[MN],dis[MN],b[MN];
long long edges[5003][3];
bool vis[MN],ins[MN];
int S,T,flow=0,cost=0;

long long min(long long a,long long b)
{
  if (a<b) return a;
  return b;
}

void addedge(int from,int to,long long c)
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
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  queue<int> q;
  vis[S]=true;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if(e.c>e.f&&!vis[e.to])
      {
        dis[e.to]=dis[u]+1;
        vis[e.to]=true;
        q.push(e.to);
      }
    }
  }
  return vis[T];
}

long long Dfs(int u,long long a)
{
  if (u==T||a==0) return a;
  long long flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    cur[u]=i;;
    if (dis[e.to]==dis[u]+1&&(f=Dfs(e.to,min(a,e.c-e.f)))>0)
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
  //freopen("2817.in","r",stdin);
  //freopen("2817.out","w",stdout);
  es.clear();
  int i,j,k,m,n;
  memset(edges,0,sizeof(edges));
  for (i=0;i<MN;i++)g[i].clear();
  scanf("%d%d%d%d",&n,&m,&S,&T);
  //S=1;T=n;
  //addedge(S,1,inf);
  for (i=1;i<=m;i++)
  {
    int u,v;
    long long w;
    scanf("%d%d%I64d",&u,&v,&w);
    edges[i][0]=u;
    edges[i][1]=v;
    edges[i][2]=(long long)(w*(m+1)+1);
    //printf("%I64d\n",(long long)(w*(m+1)+1));
    addedge(u,v,(long long)(w*(m+1)+1));
  }
  //for (i=0;i<es.size();i++)
    //printf("c=%I64d\n",es[i].c);
  //return 0;
  long long ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=Dfs(S,inf);
  }
  int tot=0;
  printf("%I64d %I64d\n",ans/(m+1),ans%(m+1));
  //return 0;
  for (i=1;i<=m&&ans>0;i++)
  {
    int u=edges[i][0];
    int v=edges[i][1];
    long long w=edges[i][2];
    for (j=0;j<g[u].size();j++)
    {
      edge e=es[g[u][j]];
      if (e.to==v&&e.c==w)
      {
        es[g[u][j]].c=0;
        k=g[u][j];
        break;
      }  
    }
    for (j=0;j<es.size();j++)
      es[j].f=0;
    long long s=0;
    //for (j=0;j<es.size();j++)
      //printf("from=%d to=%d c=%d f=%d\n",es[j].from,es[j].to,es[j].c,es[j].f);
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      s+=Dfs(S,inf);
    }
    if (s==ans-w)
    {
      b[tot++]=i;
      ans=s;
    }
    else
    {
      es[k].c=w;
    }
  }
  for (i=0;i<tot;i++)
    printf("%d\n",b[i]);
  return 0;
}
