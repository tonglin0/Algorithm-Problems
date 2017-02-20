#include<cstdlib>
#include<cstdio>
#include<vector>
#define MN 1000
using namespace std;

int p[MN];
bool vis[MN];
vector<int> g[MN];
char map[MN][MN];
int a[MN][MN];
int N=0,M=0;

int find(int u)
{
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i]])
    {
      vis[g[u][i]]=true;
      if (p[g[u][i]]==0||find(p[g[u][i]]))
      {
        p[g[u][i]]=u;
        return true;
      }
    }
  return false;
}

int main()
{
  int n,m,i,j,k;
  //freopen("2226.in","r",stdin);
  //freopen("2226.out","w",stdout);
  scanf("%d%d",&n,&m);
  memset(map,0,sizeof(map));
  memset(a,0,sizeof(a));
  for (i=0;i<n;i++)
    scanf("%s",map[i]);
  for (i=0;i<MN;i++) g[i].clear();
  for (i=0;i<n;i++)
  {
    for (j=0;j<m;j++)
    if (map[i][j]=='*')
    {
      k=j;
      while (k<m&&map[i][k]=='*') k++;
      N++;
      for (int ii=j;ii<k;ii++)
        a[i][ii]=N;
      j=k;
    }
  }
  for (i=0;i<m;i++)
  {
    for (j=0;j<n;j++)
      if (map[j][i]=='*')
      {
        k=j;
        while(k<n&&map[k][i]=='*') k++;
        M++;
        for (int ii=j;ii<k;ii++)
          g[M].push_back(a[ii][i]);
        j=k;
      }
  }
  int ans=0;
  for (i=1;i<=M;i++)
  {
    memset(vis,0,sizeof(vis));
    if (find(i)) ans++;
  }
  printf("%d\n",ans);
  return 0;
}
