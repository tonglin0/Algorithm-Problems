#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;int no;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){if (a.y!=b.y) return a.y<b.y;return a.x<b.x;}
double dist(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

point l[100];
bool vis[100];

int main()
{
  //freopen("1696.in","r",stdin);
  //freopen("1696.out","w",stdout);
  int n,i,j,k,m,T;
  scanf("%d",&T);
  while(T--)
  {
    memset(l,0,sizeof(l));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&k);
      scanf("%lf%lf",&l[k].x,&l[k].y);
      l[k].no=k;
    }
    printf("%d ",n);
    sort(l+1,l+n+1,cmp);
    point a=l[1];
    k=l[1].no;
    printf("%d ",k);
    vis[1]=true;
    for (i=1;i<=n-1;i++)
    {
      vector<int> g;
      g.clear();
      for (j=2;j<=n;j++)
        if (!vis[j])
        {
          bool flag=true;
          for(int ii=2;ii<=n;ii++)
            if (!vis[ii]&&dcmp(cross(l[j]-a,l[ii]-a))<0)
            {
              flag=false;
              break;
            }
          if (flag)
            g.push_back(j);
        }
      double dis=1e9;
      for (j=0;j<g.size();j++)
        if (dist(l[g[j]],a)<dis)
        {
          dis=dist(l[g[j]],a);
          k=g[j];
        }
      a=l[k];
      vis[k]=true;
      printf("%d ",a.no);
    }
    printf("\n");
  }
  return 0;
}
