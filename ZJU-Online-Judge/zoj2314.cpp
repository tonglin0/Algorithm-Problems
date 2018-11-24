#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF (int)2e9
using namespace std;

struct edge{int from,to,c,f,b;bool pr;};
vector<edge> es;
vector<int> g[203];
bool vis[203];
int cur[203],dis[203],inx[203],outx[203];
int T,n;

void addedge(int from,int to,int c,int b,int p)
{
  edge e;
  e.pr=false;
  e.from=from;e.to=to;e.c=c;e.f=0;e.b=b;if (p) e.pr=true;
  es.push_back(e);
  e.from=to;e.to=from;e.c=0;e.pr=false;
  es.push_back(e);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
} 

bool bfs()
{
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  queue<int> q;
  q.push(0);
  vis[0]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.f<e.c)
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
      }
    }
  }
  return vis[n+1];
}

int dfs(int x,int a)
{
  if (x==n+1||a==0) return a;
  int flow=0,f;
  for(int i=cur[x];i<g[x].size();i++)
  {
    edge& e=es[g[x][i]];
    cur[x]=i;
    if (dis[e.to]==dis[x]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      e.f+=f;
      a-=f;
      es[g[x][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  //freopen("2314.in","r",stdin);
  //freopen("2314.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    int i,j,m;
    scanf("%d%d",&n,&m);
    es.clear();
    for (i=0;i<=202;i++)
      g[i].clear();
    memset(inx,0,sizeof(inx));
    memset(outx,0,sizeof(outx));
    int u,v,l,r; 
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d%d",&u,&v,&l,&r);
      addedge(u,v,r-l,l,1);
      inx[v]+=l;
      outx[u]+=l;
    }
    for (i=1;i<=n;i++)
      if (inx[i]>outx[i])
        addedge(0,i,inx[i]-outx[i],0,0);
      else if(inx[i]<outx[i])
        addedge(i,n+1,outx[i]-inx[i],0,0);   
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    bool flag=true;
    for (i=0;i<g[0].size();i++)
      if (es[g[0][i]].f!=es[g[0][i]].c)
      {
        flag=false;
        break;
      }
    if (!flag) printf("NO\n\n");
    else
    {
      printf("YES\n");
      for (i=0;i<es.size();i++)
        if (es[i].pr) printf("%d\n",es[i].f+es[i].b);//if(es[i].c!=0&&es[i].from!=0&&es[i].to!=n+1)printf("%d\n",es[i].f);
      printf("\n"); 
    }
  }
  return 0;
}
