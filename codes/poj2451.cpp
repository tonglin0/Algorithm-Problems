#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
struct line{
       point p;vec v;double ang;
       line(){}
       line(point p,vec v):p(p),v(v){}};
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(line a,line b){return a.ang<b.ang;}
bool onleft(point p,line b){return dcmp(cross(b.v,p-b.p))>=0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}

line l[20050],q[20050];
point p[20040];
int n;

int halfplane()
{
  sort(l+1,l+n+1,cmp);
  int f=0,r=0;
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i]))r--;
    while(f<r&&!onleft(p[f],l[i]))f++;
    q[++r]=l[i];
    if (dcmp(cross(l[i].v,q[r-1].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
    }
    if (f<r) p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  while(f<r&&!onleft(p[r-1],q[f]))r--;
  if (r-f<=1) return 0;
  p[r]=llcross(q[f].p,q[f].v,q[r].p,q[r].v);
  int m=0;
  for (int i=f;i<=r;i++)
    p[m++]=p[i];
  return m;
}

int main()
{
  //freopen("2451.in","r",stdin);
  //freopen("2451.out","w",stdout);
  memset(l,0,sizeof(l));
  memset(q,0,sizeof(q));
  memset(p,0,sizeof(p));
  int i,j,k,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    point a,b;
    scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
    l[i].p=a;
    l[i].v=b-a;
  }
  l[++n].p=vec(0,0);l[n].v=vec(10000,0)-vec(0,0);
  l[++n].p=vec(10000,0);l[n].v=vec(10000,10000)-vec(10000,0);
  l[++n].p=vec(10000,10000);l[n].v=vec(0,10000)-vec(10000,10000);
  l[++n].p=vec(0,10000);l[n].v=vec(0,0)-vec(0,10000);
  for (int i=1;i<=n;i++)
    l[i].ang=atan2(l[i].v.y,l[i].v.x);
  m=halfplane();
  double ans=0;
  for (i=1;i<m;i++)
    ans+=cross(p[i]-p[0],p[(i+1)%m]-p[0]);
  ans=fabs(ans)/2.0;
  printf("%.1lf\n",ans);
  return 0;
}
