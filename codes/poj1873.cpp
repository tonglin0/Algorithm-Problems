#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}

bool vis[20];
point p[20],poly[20],o[20];
int n, m;
int l[20];
double rest;
double len[20]; 
int ans=-10000,treenum;
vector<int> anss;

int find_poly(int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>0) m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>0) m--;
    poly[m++]=p[i];
  }
  return m;
}

void dfs(int k)
{
  if (k==n+1)
  {
    memset(p,0,sizeof(p));
    memset(poly,0,sizeof(poly));
    int d=0;
    double re=0;
    int value=0;
    int trees=0;
    for (int i=1;i<=n;i++)
    {
      if (vis[i])
      {
        p[++d]=o[i];
        value+=l[i];
        trees++;
      }
      else 
        re+=len[i];
    }
    if (value<ans) return ;
    int ff=find_poly(d);
    double f=0;
    for (int i=0;i<ff;i++)
      f+=dist(poly[i],poly[(i+1)%ff]);
    re-=f;
    if (dcmp(re)>=0)
    {
      if (value>ans)
      {
        ans=value;
        treenum=trees;
        rest=re;
        anss.clear();
        for (int j=1;j<=n;j++)
          if (!vis[j])
            anss.push_back(j);
      }
      else if (value==ans&&trees>treenum)
      {
        treenum=trees;
        rest=re;
        anss.clear();
        for (int j=1;j<=n;j++)
          if (!vis[j])
            anss.push_back(j);
      }
    }
    return;
  }
  vis[k]=true;
  dfs(k+1);
  vis[k]=false;
  dfs(k+1);
  return;
}

int main()
{
  freopen("1873.in","r",stdin);
  freopen("1873.out","w",stdout);
  int i,j,k;
  int ii=0;
  scanf("%d",&n);
  while(n)
  {
    ii++;
    memset(o,0,sizeof(o));
    memset(vis,0,sizeof(vis));
    memset(l,0,sizeof(l));
    memset(len,0,sizeof(len));
    ans=-10000;
    for (i=1;i<=n;i++)
      scanf("%lf%lf%d%lf",&o[i].x,&o[i].y,&l[i],&len[i]);
    dfs(1);
    printf("Forest %d\n",ii);
    printf("Cut these trees:");
    for (int i=0;i<anss.size();i++)
      printf(" %d",anss[i]);
    printf("\n");
    printf("Extra wood: %.2lf\n",rest);
    scanf("%d",&n);
    if (n!=0) printf("\n");
  }
  return 0;
}

