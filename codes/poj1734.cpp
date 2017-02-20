#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define INF (int)1e8
using namespace std;

int map[104][104],a[104][104];
int p[104][104];
vector<int> anss;

void print(int u,int v)
{
  if (p[u][v]==0)
  {
    anss.push_back(u);
    return ;
  }
  else
  {
    print(u,p[u][v]);
    print(p[u][v],v);
    return ;
  }
}

int main()
{
  freopen("1734.in","r",stdin);
  freopen("1734.out","w",stdout);
  memset(p,0,sizeof(p));
  memset(a,0,sizeof(a));
  memset(map,0,sizeof(map));
  int ans=INF;
  int n,i,j,k,m;
  scanf("%d",&n);
  for (i=0;i<=n;i++)
    for (j=0;j<=n;j++)
      a[i][j]=map[i][j]=INF;
  scanf("%d",&m);
  int ansi,ansj,ansk;
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    if (w<map[u][v])
      a[u][v]=a[v][u]=map[u][v]=map[v][u]=w;
  }
  for (k=1;k<=n;k++)
  {
    for (i=1;i<k;i++)
      for (j=1;j<i;j++)
        if (a[i][j]+map[j][k]+map[k][i]<ans)
        {
          ans=a[i][j]+map[j][k]+map[k][i];
          anss.clear();
          int t=j;
          anss.push_back(k);
          print(i,j);
          anss.push_back(j);
        }
    for (i=1;i<=n;i++)
      for (j=1;j<i;j++)
        if (a[i][k]+a[k][j]<a[i][j])
        {
          a[i][j]=a[j][i]=a[i][k]+a[k][j];
          p[i][j]=p[j][i]=k;
        }
  }
  if (ans==INF)
    printf("No solution.\n");
  else
  {
    for (i=0;i<anss.size();i++)
      printf("%d ",anss[i]);
  }
  printf("\n");
  return 0;
}
