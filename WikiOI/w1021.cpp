#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
vector <int> g[1003];
priority_queue<pii,vector<pii>,greater<pii> >q;
int p[1003],dis[1003],map[1003][1003];
bool vis[1003];
int n,m;
bool first;

void dijk()
{
  int i,j,k;
  memset(dis,127,sizeof(dis));
  memset(vis,0,sizeof(vis));
  while(!q.empty()) q.pop();
  //q.clear();
  if (first)memset(p,0,sizeof(p));
  dis[1]=0;
  q.push(make_pair(0,1));
  while(!q.empty())
  {
    pii x=q.top();
    q.pop();
    int u=x.second;
    if (vis[u]) continue;
    vis[u]=true;
    int d=g[u].size();
    for (i=0;i<d;i++)
    {
      int v=g[u][i];
      if (!vis[v]&&map[u][v]!=0&&dis[u]+map[u][v]<dis[v])
      {
        q.push(make_pair(dis[v]=dis[u]+map[u][v],v));
        if (first)p[v]=u;
      }    
    }
  }
}
int main()
{
  freopen("1021.in","r",stdin);
  freopen("1021.out","w",stdout);
  int i,j,s,t,k;
  memset(map,0,sizeof(map));
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    g[u].push_back(v);
    g[v].push_back(u);
    map[u][v]=w;
    map[v][u]=w;
  }
  first=true;
  dijk();
  first=false;
  int max=dis[n];
  int x=n;
  while (p[x]!=0)
  {
    int t=map[p[x]][x];
    map[p[x]][x]=0;
    map[x][p[x]]=0;
    dijk();
    if (dis[n]>max) max=dis[n];
    map[p[x]][x]=t;
    map[x][p[x]]=t;
    x=p[x];
  }
  printf("%d\n",max);
  return 0;
}
