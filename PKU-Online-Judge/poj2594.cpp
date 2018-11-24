#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MN 1005
using namespace std;

//vector<int> g[MN];
bool map[MN][MN];
int p[MN];
bool vis[MN];
int n;

bool find(int u)
{
  for (int i=1;i<=n;i++)
    if (!vis[i]&&map[i][u])
    {
      vis[i]=true;
      if (!p[i]||find(p[i]))
      {
        p[i]=u;
        return true;                      
      }
    }
  return false;
}

int main()
{
  int m,i,k,j;
  //freopen("2594.in","r",stdin);
  //freopen("2594.out","w",stdout);
  scanf("%d%d",&n,&m);
  while(!(n==0&&m==0))
  {
    memset(map,0,sizeof(map));
    memset(p,0,sizeof(p));
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      map[u][v]=true;
    }
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          if (i!=j&&map[i][k]&&map[k][j])
            map[i][j]=true;
    int ans=0;
    for (i=1;i<=n;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    printf("%d\n",n-ans);
    scanf("%d%d",&n,&m);
  }
  return 0;
}
