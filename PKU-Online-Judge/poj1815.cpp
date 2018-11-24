#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define INF (int)1e9
#define MN 1604
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int dis[MN],cur[MN];
bool vis[MN],us[MN];//,nou[100000];
int T,S;

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
  vis[S]=true;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
      }
    }
  }
  return vis[T];
}


bool bfs2(int x)
{
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  vis[S]=true;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.to!=x&&us[e.to]&&e.c>e.f&&!vis[e.to])
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
      }
    }
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
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

int dfs2(int u,int a,int v)
{
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    //if (!nou[g[u][i]]) continue;
    edge &e=es[g[u][i]];
    if (us[e.to]&&e.to!=v&&dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
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
  int n,i,j,k,m;
  //freopen("1815.in","r",stdin);
  //freopen("1815.out","w",stdout);
  scanf("%d%d%d",&n,&S,&T);
  for (i=1;i<=n;i++)
    if (i!=S&&i!=T)
      addedge(i,i+n,1);
  bool flag=false;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      scanf("%d",&k);
      if (i==j)continue;
      if (k==1)
      {
        if (i!=S&&j!=T)
          addedge(i+n,j,INF);
        else if (i==S&&j==T)
        {
          addedge(i,j,INF);
          flag=true;
        }
        else if (i==S&&j!=T)
        {
          addedge(S,j,INF);
        }
        else if (i!=S&&j==T)
          addedge(i+n,T,INF);
      }
    }
  memset(us,1,sizeof(us));
  int ans=0;
  if (flag)
  {
    printf("NO ANSWER!\n");
    return 0;
  }
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  if (ans==0)
  {
    printf("0\n");
    return 0;
  }
  printf("%d\n",ans);
  bool fl=true;
  for (i=1;i<=n&&fl;i++)
  {
    if (i==T||i==S) continue;
    for (j=0;j<es.size();j++)
      es[j].f=0;
    int s=0;
    while(fl&&bfs2(i))
    {
      memset(cur,0,sizeof(cur));
      s+=dfs2(S,INF,i);      
    }
    if (s<ans)
      {
        printf("%d ",i);
        us[i]=false;
        //for (int ii=0;ii<g[i].size();ii++)
          //if (es[g[i][ii]].to=i+n)
            //nou[g[i][ii]]=false;
        ans=s;
        if (ans==0) fl=false;
      }
  }
  return 0;
}
