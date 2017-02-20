#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
#define INF (int)2e9
using namespace std;

bool can[23][9];
struct edge{int from,to,c,f;};
vector <edge> es;
vector<int> g[400];
int cur[400],dis[400],tim[22],needi[22];
int T,t;

void addedge(int from,int to,int w)
{
  edge x;
  x.from=from;x.to=to;x.c=w;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}
bool bfs()
{
  queue<int> q;
  bool vis[400];
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  vis[0]=true;
  q.push(0);
  int i;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[t];
}
int dfs(int x,int a)
{
  if (x==t||a==0) return a;
  int i,f,flow=0;
  for (i=cur[x];i<g[x].size();i++)
  {
    edge& e=es[g[x][i]];
    cur[x]=i;
    if (dis[e.to]==dis[x]+1&&(f=dfs(e.to,min(a,e.c-e.f))>0))
    {
      flow+=f;
      e.f+=f;
      es[g[x][i]^1].f-=f;
      a-=f;
      if (a==0) break;
    }
  }
  return flow;
}
int main()
{
  //freopen("1698.in","r",stdin);
  //freopen("1698.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    int n,i,j,k,s,maxweek=0;
    scanf("%d",&n);
    memset(tim,0,sizeof(tim));
    memset(can,0,sizeof(can));
    es.clear();
    for (i=0;i<=398;i++) g[i].clear();
    int need=0;
    for(i=1;i<=n;i++)
    {
      for (j=1;j<=7;j++)
      {
        int d;
        scanf("%d",&d);
        can[i][j]=d;
      }
      scanf("%d%d",&needi[i],&tim[i]);
      need+=needi[i];
      maxweek=max(maxweek,tim[i]);
    }
    int day=maxweek*7;
    for (i=1;i<=day;i++)
    {
      int s=(i-1)%7+1,k=(i-1)/7+1;
      bool flag=false;
      for (j=1;j<=n;j++)
        if (k<=tim[j]&&can[j][s])
        {
          flag=true;
          addedge(i,day+j,1);
        }
      if (flag) addedge(0,i,1);
    }
    t=day+n+1;
    for (i=1;i<=n;i++)
      addedge(day+i,t,needi[i]);
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    //printf("%d\n",ans); 
    if (ans==need) printf("Yes\n");else printf("No\n");
  }
  return 0;
} 
