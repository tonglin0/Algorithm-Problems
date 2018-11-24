#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

int cur[100],dis[100],into[100];
bool vis[100];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[100];
int S,T,SS,TT;

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

bool bfs(int S,int T)
{
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  queue<int> q;
  q.push(S);
  vis[S]=true;
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

int dfs(int u,int a,int T)
{
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f),T))>0)
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
  //freopen("3157.in","r",stdin);
  //freopen("3157.out","w",stdout);
  scanf("%d%d",&n,&m);
  while(!(m==0&&n==0))
  {
    es.clear();
    for (i=0;i<100;i++) g[i].clear();
    memset(into,0,sizeof(into));
    S=0;
    T=n+1;
    SS=T+1;
    TT=SS+1;
    for (i=1;i<=m;i++)
    {
      char s[100];
      scanf("%s",s);
      int u,v,w;
      if (s[0]=='+')
        u=S;
      else if (s[0]=='-')
        u=T;
      else
        sscanf(s,"%d",&u);
      scanf("%s",s);
      if (s[0]=='+')
        v=S;
      else if (s[0]=='-')
        v=T;
      else
        sscanf(s,"%d",&v);
      scanf("%d",&w);
      into[u]-=w;
      into[v]+=w;
      addedge(u,v,INF);
    }
    addedge(T,S,INF);
    int s=0;
    for (i=0;i<=T;i++)
      if (into[i]>0)
      {
        s+=into[i];
        addedge(SS,i,into[i]);
      }
      else if (into[i]<0)
        addedge(i,TT,-into[i]);
    int ans=0;
    while(bfs(SS,TT))
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(SS,INF,TT);
    }
    if (ans!=s)
    {
      printf("impossible\n");
      scanf("%d%d",&n,&m);
      continue;
    }
    for (i=0;i<es.size();i++)
      if ((es[i].from==S&&es[i].to==T&&es[i].c==0)||(es[i].from==T&&es[i].to==S&&es[i].c==INF)||es[i].from==SS||es[i].from==TT||es[i].from==TT||es[i].to==SS)
        es[i].f=es[i].c=0;
    ans=0;
    while(bfs(T,S))
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(T,INF,S);
    }
    ans=0;
    for (i=0;i<es.size();i++)
      if (es[i].from==S&&es[i].c>0)
        ans+=es[i].f;
    printf("%d\n",ans);
    scanf("%d%d",&n,&m);
  }
  return 0;
}
