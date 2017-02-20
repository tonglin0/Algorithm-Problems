#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
       int v,w;
};
vector<node> g[10003];
int dis[10003];

void dfs(int u,int pre,int d)
{
  dis[u]=dis[pre]+d;
  for (int i=0;i<g[u].size();i++)
    if (g[u][i].v!=pre)
      dfs(g[u][i].v,u,g[u][i].w);
}

int main()
{
  freopen("2631.in","r",stdin);
  freopen("2631.out","w",stdout);
  int n=1,i,j,k,u,v,w,m;
  while(scanf("%d%d%d",&u,&v,&w)==3)
  {
    ++n;
    node tmp;
    tmp.v=v;tmp.w=w;
    g[u].push_back(tmp);
    tmp.v=u;
    g[v].push_back(tmp);
  }
  dis[0]=0;
  dfs(1,0,0);
  k=2;
  for (i=3;i<=n;i++)
    if (dis[i]>dis[k])
      k=i;
  dfs(k,0,0);
  k=1;
  for (i=2;i<=n;i++)
    if (dis[i]>dis[k])
      k=i;
  printf("%d\n",dis[k]);
  return 0;
}
