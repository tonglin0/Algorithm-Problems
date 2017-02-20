#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#define MN 103
using namespace std;

int p[MN];
bool vis[MN];
double a[MN][2];
vector<int> g[MN];
int n;

double sqr(double a)
{
  return a*a;
}

double dis(double x1,double y1,double x2,double y2)
{
  return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

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
  //freopen("2536.in","r",stdin);
  //freopen("2536.out","w",stdout);
  int v,s,m,i,j,k;
while(scanf("%d%d%d%d",&n,&m,&s,&v)==4)
{
  int S=s*v;
  memset(p,0,sizeof(p));
  for (i=0;i<MN;i++) g[i].clear();
  for (i=1;i<=n;i++)
  {
    double x,y;
    scanf("%lf%lf",&x,&y);
    a[i][0]=x;
    a[i][1]=y;
  }
  for (i=1;i<=m;i++)
  {
    double x,y;
    scanf("%lf%lf",&x,&y);
    for (j=1;j<=n;j++)
      if (dis(x,y,a[j][0],a[j][1])<=S)
        g[i].push_back(j);
  }
  int ans=0;
  for (i=1;i<=m;i++)
  {
    memset(vis,0,sizeof(vis));
    if (find(i)) ans++;
  }
  printf("%d\n",n-ans);
}
  return 0;
}
