#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define MN 510
#define LL long long
#define INF (long long)1e8
using namespace std;

int pr[MN],ne[MN],cur[MN];
LL dis[MN],map[MN][MN];
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
  q.push(0);
  vis[0]=true;
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

LL min(LL a,LL b)
{
  if (a<b) return a;
  return b;
}

LL dfs(int u,LL a)
{
  if (u==T||a==0) return a;
  LL f,flow=0;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      a-=f;
      flow+=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  int n,i,j,m,k;
  freopen("2391.in","r",stdin);
  freopen("2391.out","w",stdout);
  scanf("%d%d",&n,&m);
  memset(pr,0,sizeof(pr));
  memset(ne,0,sizeof(ne));
  for (i=1;i<=n;i++)
    scanf("%d%d",&ne[i],&pr[i]);
  memset(map,0,sizeof(map));
  //printf("%d\n",map[1][1]);
  int u,v,w;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    if (map[u][v]!=0) 
      map[u][v]=min(map[u][v],(long long)w);
    else map[u][v]=w;
    map[v][u]=map[u][v];
  }
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if(i!=j&&map[i][k]!=0&&map[k][j]!=0) 
          if (map[i][j]!=0)
            map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
          else map[i][j]=map[i][k]+map[k][j];
  /*for (i=1;i<=n;i++)
    {for (j=1;j<=n;j++)
      printf("%d ",map[i][j]);
      printf("\n");
    }*/
  /*for(i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++) printf("%d ",map[i][j]);
    putchar('\n');
  }
  return 0;*/
  LL l=INF*(long long)100000,r=-INF*(long long)100000;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      if (map[i][j]!=0)
      {
        l=min(l,map[i][j]);
        //r=max(r,map[i][j]);
      }
  T=n+n+1;
  bool find=false;
  LL s=0;
  for (i=1;i<=n;i++)
    s+=(long long)ne[i];
  r=INF*(LL)1000000;
  //printf("%I64d %I64d",l,r);
  while(l<r)
  {
    LL mid=l+((r-l)>>1);
    es.clear();
    for (i=0;i<MN;i++) g[i].clear();
    for (i=1;i<=n;i++)
      addedge(0,i,ne[i]);
    for (i=1;i<=n;i++)
      addedge(i+n,T,pr[i]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (map[i][j]!=0&&map[i][j]<=mid) 
          addedge(i,j+n,INF);
    for (i=1;i<=n;i++) 
      addedge(i,i+n,INF);
    LL ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    if (ans==s) {find=true;r=mid;}
      else l=mid+1;
  }
  //printf("%d",map[0][0]);
  //system("pause");
  if (find) printf("%I64d\n",l);
    else printf("-1\n");
  return 0;
}
