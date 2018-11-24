#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;
typedef struct{int w,v;}node;
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<node> g[1010];
int dis[1010];
bool vis[1010];
int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int n,m,i,j,s,t,k;
  scanf("%d%d",&m,&n);
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    node x;
    x.v=v;
    x.w=w;   
    g[u].push_back(x);
    x.v=u;
    g[v].push_back(x);
  }
  memset(dis,127,sizeof(dis));
  memset(vis,0,sizeof(vis));
  q.push(make_pair(0,n));
  dis[n]=0;
  while(!q.empty())
  {
    pii x;
    x=q.top();q.pop();
    int u,w;
    u=x.second;
    if (vis[u]) continue;
    vis[u]=true;
    int d=g[u].size();
    for (i=0;i<d;i++)
    {
      int v=g[u][i].v;
      if (!vis[v]&&dis[u]<dis[v]-g[u][i].w)
        q.push(make_pair(dis[v]=dis[u]+g[u][i].w,v));
    }
  }
  printf("%d\n",dis[1]);
  return 0;
}
