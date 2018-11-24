#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
struct line{
	point p;vec v;double ang;
	line(){}
	line(point p,vec v):p(p),v(v){}
};
bool onleft(point p,line l){return cross(l.v,p-l.p)>=0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

point p[1509],poly[1509];
line l[1509],q[1509];

int halfplane(int n)
{
  sort(l+1,l+n+1,cmp);
  int r=0,f=0;
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i]))
      r--;
    while(f<r&&!onleft(p[f],l[i]))
      f++;
    q[++r]=l[i];
    if (dcmp(cross(l[i].v,q[r-1].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
	}
	if (r>f)
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
  freopen("1304.in","r",stdin);
  freopen("1304.out","w",stdout);
  int n,i,j,k,m,ca;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    for (i=n;i>=2;i--)
      l[i]=line(p[i],p[i-1]-p[i]);
    l[1]=line(p[n],p[n]-p[1]);
    for (i=1;i<=n;i++)
      l[i].ang=atan2(l[i].v.y,l[i].v.x);
	m=halfplane(n);
    double ans=0;
    for (i=1;i<m;i++)
      ans+=cross(poly[i]-poly[0],poly[(i+1)%m]-poly[0]);
    printf("%.2lf\n",fabs(ans/2.0));
  }
  return 0;  
}
