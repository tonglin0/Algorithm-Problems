#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
struct line{
       point p;vec v;double ang;
       line(){}
       line(point p,vec v):p(p),v(v){}
       };
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool onleft(point a,line l){return dcmp(cross(l.v,a-l.p))<0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

line l[1600],q[4000];
point p[1600],poly[1600];
int n;

int halfplane()
{
  sort(l+1,l+1+n,cmp);
  int f,r;
  q[f=r=0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i])) r--;
    while(f<r&&!onleft(p[f],l[i])) f++;
    q[++r]=l[i];
    if (dcmp(cross(q[r-1].v,l[i].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
    }
    if (r>f) p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  while(f<r&&!onleft(p[r-1],q[f]))r--;
  if (r-f<=1) return 0;
  p[r]=llcross(q[r].p,q[r].v,q[f].p,q[f].v);
  int m=0;
  for (int i=f;i<=r;i++)
    poly[m++]=p[i];
  return m;
}

int main()
{
  //freopen("1279.in","r",stdin);
  //freopen("1279.out","w",stdout);
  int m,k,i,j,T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    memset(l,0,sizeof(l));
    memset(q,0,sizeof(q));
    memset(poly,0,sizeof(poly));
    memset(p,0,sizeof(p));
    point a,b,c;
    //scanf("%lf%lf",&a.x,&a.y);
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&a.x,&a.y);
      if (i==1){b=a;c=a;continue;}
      l[i-1].p=b;
      l[i-1].v=a-b;
      b=a;
    }     
    l[n].p=a;
    l[n].v=c-a;
    for (i=1;i<=n;i++)
      l[i].ang=atan2(l[i].v.y,l[i].v.x);
    m=halfplane();
    double ans=0;
    for (i=1;i<m;i++)
      ans+=cross(poly[i]-poly[0],poly[(i+1)%m]-poly[0]);
    printf("%.2lf\n",fabs(ans)/2.0); 
  }
  return 0;
}

