#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MN 250
using namespace std;

vector<int> g[MN];
bool vis[MN];
int p[MN];
int n;

bool find(int u)
{
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i]])
    {
      vis[g[u][i]]=true;
      if (!p[g[u][i]]||find(p[g[u][i]]))
      {
        p[g[u][i]]=u;
        return true;
      }
    }
  return false;
}

int main()
{
  //freopen("1422.in","r",stdin);
  //freopen("1422.out","w",stdout);  
  int T,m,k,j,i;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    memset(p,0,sizeof(p));
    for (i=0;i<MN;i++) g[i].clear();
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      g[v+n].push_back(u);
    }
    int ans=0;
    for (i=n+1;i<=n+n;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    printf("%d\n",n-ans);
  }
  return 0;
}
