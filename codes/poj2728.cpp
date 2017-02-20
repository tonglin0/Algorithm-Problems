#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#define INF 1e9
#define MN 1003
using namespace std;

int h[MN][MN];
typedef pair<double,int> pii;
double f[MN],l[MN][MN],dis[MN][MN];
int p[MN][4];
bool vis[MN];

double sqr(int a)
{
  return 1.0*a*a;
}

double dist(int x1,int y1,int x2,int y2)
{
  return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

int main()
{
  //freopen("2728.in","r",stdin);
  //freopen("2728.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(l,0,sizeof(l));
    memset(h,0,sizeof(h));
    memset(f,0,sizeof(f));
    memset(dis,0,sizeof(dis));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&p[i][0],&p[i][1],&p[i][2]);
      for (j=1;j<i;j++)
      {
        h[i][j]=abs(p[i][2]-p[j][2]);
        h[j][i]=h[i][j];
        l[i][j]=dist(p[i][0],p[i][1],p[j][0],p[j][1]);
        l[j][i]=l[i][j];
      }
    }
    double r=1e2,ll=0.0;
    double mid;
    while(r-ll>1e-4)
    {
      mid=(ll+r)/2;//ll+(r-ll)/2.0;
      memset(dis,0,sizeof(dis));
      for (i=1;i<=n;i++)
        for (j=1;j<i;j++)
        {
          dis[i][j]=h[i][j]-mid*l[i][j];
          dis[j][i]=dis[i][j];
        }
      double ans=0;
      memset(vis,0,sizeof(vis));
      for (i=1;i<=n;i++)
        f[i]=INF;
      f[1]=0;
      int minj;
      for (i=1;i<=n;i++)
      {
        double mi=INF;
        for (j=1;j<=n;j++)
          if (!vis[j]&&f[j]<mi)
          {
            mi=f[j];
            minj=j;
          }
        vis[minj]=true;
        ans+=mi;
        for (j=1;j<=n;j++)
          if (!vis[j]&&dis[minj][j]<f[j])
            f[j]=dis[minj][j];
      }
      if (ans>=0.0)
        ll=mid;
      else 
        r=mid;
    }
    printf("%.3lf\n",ll);
    scanf("%d",&n);
  }
  return 0;
}
