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
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dot(a,a));}
vec normal(vec a){double l=length(a);return vec(-a.y/l,a.x/l);}
bool onleft(point p,line l){return dcmp(cross(l.v,p-l.p))>=0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

line l[203],o[203],q[1203];
point p[203];
vec o2[203];
int n;

int halfplane()
{
  sort(l+1,l+1+n,cmp);
  int last,first;
  q[last=first=0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(last>first&&!onleft(p[last-1],l[i]))last--;
    while(last>first&&!onleft(p[first],l[i]))first++;
    q[++last]=l[i];
    if (dcmp(cross(l[i].v,q[last-1].v))==0)
    {
      last--;
      if (onleft(l[i].p,q[last]))
        q[last]=l[i];
    }
    if (last>first)
      p[last-1]=llcross(q[last-1].p,q[last-1].v,q[last].p,q[last].v);
  }
  while(last>first&&!onleft(p[last-1],q[first])) last--;
  if (last-first<=1) return 0;
  return last-first+1;
}

int main()
{
  //freopen("3525.in","r",stdin);
  //freopen("3525.out","w",stdout);
  scanf("%d",&n);
  while(n)
  {
    memset(o,0,sizeof(o));
    memset(o2,0,sizeof(o2));
    point a,b,c;
    for (int i=1;i<=n;i++)
    {
      scanf("%lf%lf",&a.x,&a.y);
      if (i==1){b=a;c=a;continue;}
      o[i-1].p=b;
      o[i-1].v=a-b;
      o2[i-1]=normal(a-b);
      b=a;
    }
    o[n].p=a;
    o[n].v=c-a;
    o2[n]=normal(c-a);
    double r=10001.0,ll=-0.1;
    while(r-ll>1e-7)
    {
      double mid=(ll+r)/2.0;
      memset(p,0,sizeof(p));
      memset(q,0,sizeof(q));
      memset(l,0,sizeof(l));
      for (int i=1;i<=n;i++)
        l[i]=line(o[i].p+o2[i]*mid,o[i].v);
      for (int i=1;i<=n;i++)
        l[i].ang=atan2(l[i].v.y,l[i].v.x);
      int m=halfplane();
      if (m>0) ll=mid;
      else r=mid;
    }
    printf("%.6lf\n",ll);
    scanf("%d",&n);
  }
  return 0;
}
