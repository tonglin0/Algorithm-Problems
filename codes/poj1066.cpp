#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define INF (int)1e9
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator - (vec a,double b){return vec(a.x*b,a.y*b);}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
struct line{point a,b;};
double cross(point a,point b){return a.x*b.y-a.y*b.x;}

bool h[103],h2[103],z[103],z2[103];
int t[1000];
vector<line> l;
vector<point> p;

bool sscross(point a,point b,point c,point d)
{
  int d1,d2,d3,d4;
  d1=dcmp(cross(b-a,c-a));
  d2=dcmp(cross(b-a,d-a));
  d3=dcmp(cross(d-c,a-c));
  d4=dcmp(cross(d-c,b-c));
  if (d1*d2<0&&d3*d4<0) return true;
  return false;
}

int main()
{
  //freopen("1066.in","r",stdin);
  //freopen("1066.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  memset(h,0,sizeof(h));
  memset(h2,0,sizeof(h2));
  memset(z,0,sizeof(z));
  memset(z2,0,sizeof(z2));
  l.clear();
  p.clear();
  for (i=1;i<=n;i++)
  {
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (x1==0) z[y1]=true;
    if (x2==0) z[y2]=true;
    if (x1==100) z2[y1]=true;
    if (x2==100) z2[y2]=true;
    if (y1==0) h[x1]=true;
    if (y2==0) h[x2]=true;
    if (y1==100) h2[x1]=true;
    if (y2==100) h2[x2]=true;
    line ll;
    ll.a=vec(x1,y1);
    ll.b=vec(x2,y2);
    l.push_back(ll);
  }
  memset(t,0,sizeof(t));
  h[0]=true;h[100]=true;
  int d=0;
  for (i=0;i<=100;i++)
    if (h[i])
      t[++d]=i;
  for (i=2;i<=d;i++)
  {
    point a=vec((t[i-1]+t[i])/2.0,0);
    p.push_back(a);
  }
  memset(t,0,sizeof(t));
  h2[0]=true;h2[100]=true;
  d=0;
  for (i=0;i<=100;i++)
    if (h2[i])
      t[++d]=i;
  for (i=2;i<=d;i++)
  {
    point a=vec((t[i-1]+t[i])/2.0,100);
    p.push_back(a);
  }
  memset(t,0,sizeof(t));
  z[0]=true;z[100]=true;
  d=0;
  for (i=0;i<=100;i++)
    if (z[i])
      t[++d]=i;
  for (i=2;i<=d;i++)
  {
    point a=vec(0,(t[i-1]+t[i])/2.0);
    p.push_back(a);
  }
  memset(t,0,sizeof(t));
  z2[0]=true;z2[100]=true;
  d=0;
  for (i=0;i<=100;i++)
    if (z2[i])
      t[++d]=i;
  for (i=2;i<=d;i++)
  {
    point a=vec(100,(t[i-1]+t[i])/2.0);
    p.push_back(a);
  }
  double x,y;
  scanf("%lf%lf",&x,&y);
  point en=vec(x,y);
  int ans=INF;
  for (i=0;i<p.size();i++)
  {
    int s=0;
    for (j=0;j<l.size();j++)
      if (sscross(p[i],en,l[j].a,l[j].b))
        s++;
    ans=min(ans,s);
  }
  printf("Number of doors = %d\n",ans+1);
  return 0;
}
