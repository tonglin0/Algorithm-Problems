#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-12
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
struct line{
	point p;vec v;
	double ang;
	line(){}
	line(point p,vec v):p(p),v(v){}
};
bool onleft(point p,line l)
{
  return dcmp(cross(l.v,p-l.p))>0;
}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec v){return sqrt(dot(v,v));}
vec normal(vec v){double l=length(v);return vec(-v.y/l,v.x/l);}
bool cmp(line a,line b){return a.ang<b.ang;}

line tl[1000],l[1000];
point p[1000],poly[1000];
line q[1000];

int halfplane(int n)
{
  int f=0,r=0;
  sort(l+1,l+n+1,cmp);
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i]))
      r--;
    while(f<r&&!onleft(p[f],l[i]))
      f++;
    q[++r]=l[i];
    if (dcmp(cross(q[r-1].v,l[i].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
	}
	if (f<r)
	  p[r-1]=llcross(q[r].p,q[r].v,q[r-1].p,q[r-1].v);
  }
  while(f<r&&!onleft(p[r-1],q[f]))
    r--;
  if (r-f<=1)
    return 0;
  p[r]=llcross(q[r].p,q[r].v,q[f].p,q[f].v);
  int m=0;
  for (int i=f;i<=r;i++)
    poly[m++]=p[i];
  return m;
}

int main()
{
  freopen("1396.in","r",stdin);
  freopen("1396.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    point a,b,c;
    scanf("%lf%lf",&a.x,&a.y);
    c=a;
	for (i=2;i<=n;i++)
    {
      scanf("%lf%lf",&b.x,&b.y);
      l[i-1]=line(a,b-a);
      a=b;
	}
	l[n]=line(b,c-b);
	for (i=1;i<=n;i++)
	  tl[i]=l[i];
	double ll=0,rr=(1e5)+10;
	while(rr-ll>=1e-11)
	{
	  double mid=(ll+rr)/2.0;
	  for (i=1;i<=n;i++)
	  {
	    vec v=normal(tl[i].v);
	    l[i]=line(tl[i].p+v*mid,tl[i].v);
	    l[i].ang=atan2(l[i].v.y,l[i].v.x);
	  }
	  m=halfplane(n);
	  double ans=0;
	  for (i=1;i<m;i++)
	    ans+=cross(poly[i]-poly[0],poly[(i+1)%m]-poly[0]);
	  if (m==0||fabs(ans)<=eps)
	    rr=mid;
	  else
	    ll=mid;
	}
	printf("%.6lf\n",ll);
  }
  return 0;
}
