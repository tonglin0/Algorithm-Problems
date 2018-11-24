#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int> g[503];
int p[503];
bool vis[503];
int n;

bool find(int u)
{
  for (int i=0;i<g[u].size();i++)
  {
    if (!vis[g[u][i]])
    {
      vis[g[u][i]]=true;
      if (!p[g[u][i]]||find(p[g[u][i]]))
      {
        p[g[u][i]]=u;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int m,j,i;
  //freopen("3041.in","r",stdin);
  //freopen("3041.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=0;i<503;i++) g[i].clear();
  memset(p,0,sizeof(p));
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    g[v].push_back(u);
  }  
  int ans=0;
  for (i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    if (find(i)) ans++;  
  }
  printf("%d\n",ans);
  return 0;
}
