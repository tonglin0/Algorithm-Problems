#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MN 305
using namespace std;

bool map[MN][MN];
bool vis[MN];
int p[MN];
int n;

bool find(int x)
{
  for (int i=1;i<=n;i++)
    if (map[x][i]&&!vis[i])
    {
      vis[i]=true;
      if (p[i]==0||find(p[i]))
      {
        p[i]=x;
        return true;
      }
    }
  return false;
}

int main()
{
int T;
//freopen("1469.in","r",stdin);
//freopen("1469.out","w",stdout);
scanf("%d",&T);
while(T--)
{
  int m,i,j,k;
  scanf("%d%d",&m,&n);
  memset(map,0,sizeof(map));
  memset(p,0,sizeof(p));
  for (i=1;i<=m;i++)
  {
    scanf("%d",&k);
    for (j=1;j<=k;j++)
    {
      int u;
      scanf("%d",&u);
      map[i][u]=true;
    }
  }
  int ans=0;
  for (i=1;i<=m;i++)
  {
    memset(vis,0,sizeof(vis));
    if (find(i)) ans++;
  }
  if (ans==m) printf("YES\n");
    else printf("NO\n");
}
  return 0;
}
