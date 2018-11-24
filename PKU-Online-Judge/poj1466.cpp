#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#define MN 505
using namespace std;

vector<int> g[MN];
int p[MN];
bool vis[MN];
bool c[MN][MN];

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
  //freopen("1466.in","r",stdin);
  //freopen("1466.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    memset(p,0,sizeof(p));
    memset(c,0,sizeof(c));
    for (i=0;i<MN;i++) g[i].clear();
    for (i=1;i<=n;i++)
    {
      int u;
      scanf("%d:",&u);
      char ch=' ';
      while(ch!='(')
        ch=getchar();
      int v;
      scanf("%d)",&v);
      for (j=1;j<=v;j++)
      {
        int d;
        scanf("%d",&d);
        //if (!c[u][d]&&!c[d][u])
        //{
          g[u].push_back(d);
          c[u][d]=c[d][u]=true;
        //}
      }
    }
    int ans=0;
    for (i=0;i<n;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    printf("%d\n",n-ans/2);
  }
  return 0;
}

