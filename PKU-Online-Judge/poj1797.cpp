#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{int u,v,w;};
struct node2{int v,w;};
vector<node2> ng[1003];
int fa[1003];
vector<node> q;
int dis[1003][1003];
int cnt,n;
bool vis[1003];

bool cmp(const node a,node b)
{
  return a.w>b.w;
}
void dfs(int root,int x,int w)
{
  for (int i=1;i<=n;i++)
    if (vis[i])
      dis[i][x]=dis[x][i]=min(dis[root][i],w);
  vis[x]=true;
  for (int i=0;i<ng[x].size();i++)
    if (!vis[ng[x][i].v])
      dfs(x,ng[x][i].v,ng[x][i].w);
}
int find(int x)
{
  if (fa[x]==x) return x;
  fa[x]=find(fa[x]);
  return fa[x];
} 
int main()
{
  freopen("1797.in","r",stdin);
  freopen("1797.out","w",stdout);
  scanf("%d",&cnt);
  int ii;
  for (ii=1;ii<=cnt;ii++)
  {
    int m,i,j,k;
    scanf("%d%d",&n,&m);
    memset(dis,0,sizeof(dis));
    for (i=0;i<=n;i++)
      ng[i].clear();
    q.clear();
    for (i=1;i<=m;i++)
    {
      node x;
      scanf("%d%d%d",&x.u,&x.v,&x.w);
      q.push_back(x);
    }
    sort(q.begin(),q.end(),cmp);
    int ing=0;
    for (i=1;i<=n;i++) fa[i]=i;
    i=0;
    while(ing<n-1)
    {
      int u=q[i].u,v=q[i].v,w=q[i].w;
      if (find(u)!=find(v))
      {
        fa[find(u)]=find(v);
        ing++;
        node2 x;
        x.v=v;
        x.w=w;
        ng[u].push_back(x);
        x.v=u;
        ng[v].push_back(x);
        //ng[u].push_back((node2){v,w});
        //ng[v].push_back((node2){u,w});
      }
      i++;
    }
    memset(vis,0,sizeof(vis));
    for (i=1;i<=n;i++)dis[i][i]=int(2e9);
    dfs(0,1,dis[1][1]);
    printf("Scenario #%d:\n%d\n\n",ii,dis[1][n]);
  }
  return 0;
} 
