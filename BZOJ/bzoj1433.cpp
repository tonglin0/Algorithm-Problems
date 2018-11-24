#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MN 53
using namespace std;

int p[MN];
bool vis[MN],ins[MN],st[MN];
bool g[MN][MN];
int s=0,n;

bool find(int u)
{
  for (int i=1;i<=n;i++)
    if (g[i][u]&&ins[u]&&!vis[i])
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
  freopen("1433.in","r",stdin);
  freopen("1433.out","w",stdout);
  int T,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    memset(st,0,sizeof(st));
    memset(ins,0,sizeof(ins));
    memset(p,0,sizeof(p));
    memset(g,0,sizeof(g));
    scanf("%d",&n);
    s=0;
    for (i=1;i<=n;i++)
    {
      int u;
      scanf("%d",&u);
      if (u==1) ins[i]=true;
        else {s++;st[i]=true;}
    }
    for (i=1;i<=n;i++)
    {
      int u;
      scanf("%d",&u);
      if (u==0&&ins[i])
      {
        s++;
        st[i]=true;
        g[i][i]=true;
      }
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        int u;
        scanf("%d",&u);
        if (u&&st[i]&&ins[j])
          g[i][j]=true;
        //if (i==j) g[i][j]=true;
        if (u&&st[j]&&ins[i])
          g[j][i]=true;
      }
    int ans=0;
    for (i=1;i<=n;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    if (ans==s)
      printf("^_^\n");
    else printf("T_T\n");  
  }
  return 0;
}
