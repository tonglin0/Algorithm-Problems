#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

int c[103],a[103];
int t;
vector<int> g[103];

void dfs(int x)
{
  c[x]=-1;
  for (int i=0;i<g[x].size();i++)
  {
    if (!c[g[x][i]]) dfs(g[x][i]);
  }
  c[x]=1;
  a[t--]=x;
}

int main()
{
  //freopen("poj2367.in","r",stdin);
  //freopen("poj2367.out","w",stdout);
  int n,i,j;
  memset(a,0,sizeof(a));
  memset(c,0,sizeof(c));
  scanf("%d",&n);
  for (i=0;i<103;i++) g[i].clear();
  for (i=1;i<=n;i++)
  {
    int k;
    scanf("%d",&k);
    while(k)
    {
      g[i].push_back(k);
      scanf("%d",&k);
    }
  }
  t=n;
  for (i=1;i<=n;i++)
    if (!c[i])
      dfs(i);
  for (i=1;i<=n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n]);
  return 0;
}
